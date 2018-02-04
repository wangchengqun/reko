﻿#region License
/* 
 * Copyright (C) 2017-2018 Christian Hostelet.
 * inspired by work of:
 * Copyright (C) 1999-2017 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using Microchip.Crownking;
using Reko.Arch.Microchip.Common;
using Reko.Core;
using Reko.Core.Types;
using Reko.Core.Expressions;
using System;
using System.Collections.Generic;
using System.Linq;


namespace Reko.Arch.Microchip.PIC18
{

    /// <summary>
    /// This class implements the PIC18 registers pool.
    /// </summary>
    public class PIC18Registers : PICRegistersBuilder, IPICRegisterSymTable
    {

        //TODO: Should I revert joined registers' numbering to allow EnsureSequence to work? To be clarified w/John.
        
        #region Helper classes

        /// <summary>
        /// A register address which can be an actual data memory address or a Non-Memory-Mapped Register ID.
        /// </summary>
        private sealed class RegAddress : IEquatable<RegAddress>
        {
            /// <summary>
            /// The register address if memory-mapped.
            /// </summary>
            public readonly PICDataAddress Addr;

            /// <summary>
            /// The register ID is non-memory-mapped.
            /// </summary>
            public readonly string NMMRID;

            #region Constructors

            /// <summary>
            /// Constructor.
            /// </summary>
            /// <param name="regAddr">The register address.</param>
            public RegAddress(PICDataAddress regAddr)
            {
                Addr = regAddr;
                NMMRID = String.Empty;
            }

            /// <summary>
            /// Constructor.
            /// </summary>
            /// <param name="regAddr">The register absolute 16-bit address.</param>
            public RegAddress(ushort regAddr)
            {
                Addr = PICDataAddress.Ptr(regAddr);
                NMMRID = String.Empty;
            }

            /// <summary>
            /// Constructor.
            /// </summary>
            /// <param name="nmmrID">The register ID if non-memory-mapped.</param>
            public RegAddress(string nmmrID)
            {
                Addr = null;
                NMMRID = nmmrID;
            }

            #endregion

            public bool Equals(RegAddress other)
            {
                if (other is null) return false;
                if (ReferenceEquals(this, other)) return true;
                if (!String.IsNullOrEmpty(NMMRID)) return (NMMRID == other.NMMRID);
                return Addr == other.Addr;
            }

            public override bool Equals(object obj)
            {
                return Equals(obj as RegAddress);
            }

            public override int GetHashCode()
            {
                return (Addr?.GetHashCode() ?? 0 * 17) ^ NMMRID.GetHashCode(); ;
            }

            public override string ToString()
            {
                if (Addr != null) return $"{Addr}";
                return $"NMMRID({NMMRID})";
            }

        }

        /// <summary>
        /// A bit field address composed of the containing register's address and bit field position.
        /// </summary>
        private sealed class BitFieldAddr : IEquatable<BitFieldAddr>
        {
            public readonly PICDataAddress RegAddr;
            public readonly ulong BitPos;

            public BitFieldAddr(PICDataAddress regaddr, ulong bitpos)
            {
                RegAddr = regaddr;
                BitPos = bitpos;
            }

            public bool Equals(BitFieldAddr other)
            {
                if (other == null) return false;
                return RegAddr.Equals(other.RegAddr) && BitPos.Equals(other.BitPos);
            }

            public override bool Equals(object obj)
            {
                return Equals(obj as BitFieldAddr);
            }

            public override int GetHashCode()
            {
                return (RegAddr.GetHashCode() * 17) ^ BitPos.GetHashCode(); ;
            }

            public override string ToString()
            {
                return $"{RegAddr}.bit{BitPos}";
            }
        }

        /// <summary>
        /// List of bit fields. Permits to get bit fields with different widths at same register's bit position.
        /// </summary>
        private sealed class BitFieldList : SortedList<uint, PICBitFieldStorage>
        {
        }

        #endregion

        #region Locals

        private static object _symtabLock = new object(); // lock to allow concurrent access.
        private static PIC18Registers _registers;

        private static Dictionary<string, PICRegisterStorage> UniqueRegNames
            = new Dictionary<string, PICRegisterStorage>();
        private static Dictionary<string, PICBitFieldStorage> UniqueFieldNames
            = new Dictionary<string, PICBitFieldStorage>();
        private static Dictionary<RegAddress, RegisterStorage> RegsByAddr
            = new Dictionary<RegAddress, RegisterStorage>();
        private static Dictionary<BitFieldAddr, BitFieldList> RegsBitFields
            = new Dictionary<BitFieldAddr, BitFieldList>();


        internal static readonly Dictionary<RegisterStorage, Dictionary<uint, RegisterStorage>> SubRegisters
            = new Dictionary<RegisterStorage, Dictionary<uint, RegisterStorage>>();

        #endregion

        #region PIC18 standard (core) registers and bit fields

        /// <summary>
        /// STATUS register.
        /// </summary>
        public static PICRegisterStorage STATUS { get; private set; }

        /// <summary>
        /// Carry bit in STATUS register.
        /// </summary>
        public static PICBitFieldStorage C { get; private set; }

        /// <summary>
        /// Digit-Carry bit in STATUS register..
        /// </summary>
        public static PICBitFieldStorage DC { get; private set; }

        /// <summary>
        /// Zero bit in STATUS register..
        /// </summary>
        public static PICBitFieldStorage Z { get; private set; }

        /// <summary>
        /// Overflow bit in STATUS register..
        /// </summary>
        public static PICBitFieldStorage OV { get; private set; }

        /// <summary>
        /// Negative bit in STATUS register..
        /// </summary>
        public static PICBitFieldStorage N { get; private set; }

        /// <summary>
        /// Power-Down bit in STATUS or PCON register..
        /// </summary>
        public static PICBitFieldStorage PD { get; private set; }

        /// <summary>
        /// Timed-Out bit in STATUS or PCON register..
        /// </summary>
        public static PICBitFieldStorage TO { get; private set; }

        /// <summary>
        /// FSR2L special function register.
        /// </summary>
        public static PICRegisterStorage FSR2L { get; private set; }

        /// <summary>
        /// FSR2H special function register.
        /// </summary>
        public static PICRegisterStorage FSR2H { get; private set; }

        /// <summary>
        /// PLUSW2 special function register.
        /// </summary>
        public static PICRegisterStorage PLUSW2 { get; private set; }

        /// <summary>
        /// PREINC2 special function register.
        /// </summary>
        public static PICRegisterStorage PREINC2 { get; private set; }

        /// <summary>
        /// POSTDEC2 special function register.
        /// </summary>
        public static PICRegisterStorage POSTDEC2 { get; private set; }

        /// <summary>
        /// POSTINC2 special function register.
        /// </summary>
        public static PICRegisterStorage POSTINC2 { get; private set; }

        /// <summary>
        /// INDF2 special function register.
        /// </summary>
        public static PICRegisterStorage INDF2 { get; private set; }

        /// <summary>
        /// BSR special function register.
        /// </summary>
        public static PICRegisterStorage BSR { get; private set; }

        /// <summary>
        /// FSR1L special function register.
        /// </summary>
        public static PICRegisterStorage FSR1L { get; private set; }

        /// <summary>
        /// FSR1H special function register.
        /// </summary>
        public static PICRegisterStorage FSR1H { get; private set; }

        /// <summary>
        /// PLUSW1 special function register.
        /// </summary>
        public static PICRegisterStorage PLUSW1 { get; private set; }

        /// <summary>
        /// PREINC1 special function register.
        /// </summary>
        public static PICRegisterStorage PREINC1 { get; private set; }

        /// <summary>
        /// POSTDEC1 special function register.
        /// </summary>
        public static PICRegisterStorage POSTDEC1 { get; private set; }

        /// <summary>
        /// POSTINC1 special function register.
        /// </summary>
        public static PICRegisterStorage POSTINC1 { get; private set; }

        /// <summary>
        /// INDF1 special function register.
        /// </summary>
        public static PICRegisterStorage INDF1 { get; private set; }

        /// <summary>
        /// WREG special function register.
        /// </summary>
        public static PICRegisterStorage WREG { get; private set; }

        /// <summary>
        /// FSR0L special function register.
        /// </summary>
        public static PICRegisterStorage FSR0L { get; private set; }

        /// <summary>
        /// FSR0H special function register.
        /// </summary>
        public static PICRegisterStorage FSR0H { get; private set; }

        /// <summary>
        /// PLUSW0 special function register.
        /// </summary>
        public static PICRegisterStorage PLUSW0 { get; private set; }

        /// <summary>
        /// PREINC0 special function register.
        /// </summary>
        public static PICRegisterStorage PREINC0 { get; private set; }

        /// <summary>
        /// POSTDEC0 special function register.
        /// </summary>
        public static PICRegisterStorage POSTDEC0 { get; private set; }

        /// <summary>
        /// POSTINC0 special function register.
        /// </summary>
        public static PICRegisterStorage POSTINC0 { get; private set; }

        /// <summary>
        /// INDF0 special function register.
        /// </summary>
        public static PICRegisterStorage INDF0 { get; private set; }

        /// <summary>
        /// PRODL special function register.
        /// </summary>
        public static PICRegisterStorage PRODL { get; private set; }

        /// <summary>
        /// PRODH special function register.
        /// </summary>
        public static PICRegisterStorage PRODH { get; private set; }

        /// <summary>
        /// TABLAT special function register.
        /// </summary>
        public static PICRegisterStorage TABLAT { get; private set; }

        /// <summary>
        /// TBLPTRL special function register.
        /// </summary>
        public static PICRegisterStorage TBLPTRL { get; private set; }

        /// <summary>
        /// TBLPTRH special function register.
        /// </summary>
        public static PICRegisterStorage TBLPTRH { get; private set; }

        /// <summary>
        /// TBLPTRU special function register.
        /// </summary>
        public static PICRegisterStorage TBLPTRU { get; private set; }

        /// <summary>
        /// PCL special function register.
        /// </summary>
        public static PICRegisterStorage PCL { get; private set; }

        /// <summary>
        /// PCLH special function register.
        /// </summary>
        public static PICRegisterStorage PCLATH { get; private set; }

        /// <summary>
        /// PCLU special function register.
        /// </summary>
        public static PICRegisterStorage PCLATU { get; private set; }

        /// <summary>
        /// STKPTR special function register.
        /// </summary>
        public static PICRegisterStorage STKPTR { get; private set; }

        /// <summary>
        /// TOSL special function register.
        /// </summary>
        public static PICRegisterStorage TOSL { get; private set; }

        /// <summary>
        /// TOSH special function register.
        /// </summary>
        public static PICRegisterStorage TOSH { get; private set; }

        ///<summary>
        /// TOSU special function register.
        ///</summary>
        public static PICRegisterStorage TOSU { get; private set; }

        #region Pseudo-registers

        /// <summary>
        /// PROD pseudo-register (alias to PRODH:PRODL).
        /// </summary>
        public static PICRegisterStorage PROD { get; private set; }

        /// <summary>
        /// FSR0 pseudo-register (alias to FSR0H:FSR0L).
        /// </summary>
        public static PICRegisterStorage FSR0 { get; private set; }

        /// <summary>
        /// FSR1 pseudo-register (alias to FSR1H:FSR1L).
        /// </summary>
        public static PICRegisterStorage FSR1 { get; private set; }

        /// <summary>
        /// FSR2 pseudo-register (alias to FSR2H:FSR2L).
        /// </summary>
        public static PICRegisterStorage FSR2 { get; private set; }

        /// <summary>
        /// TOS pseudo-register (alias to TOSU:TOSH:TOSL).
        /// </summary>
        public static PICRegisterStorage TOS { get; private set; }

        /// <summary>
        /// PC pseudo-register (alias to PCLATU:PCLATH:PCL).
        /// </summary>
        public static PICRegisterStorage PC { get; private set; }

        /// <summary>
        /// TBLPTR pseudo-register (alias to TBLPTRL:TBLPTRH:TBLPTRL).
        /// </summary>
        public static PICRegisterStorage TBLPTR { get; private set; }

        #endregion

        /// <summary>
        /// Return Address Stack of the PIC.
        /// </summary>
        public static MemoryIdentifier RAS { get; private set; }

        #endregion

        #region Constructors

        /// <summary>
        /// Constructor.
        /// </summary>
        /// <param name="pic">The PIC18 definition.</param>
        private PIC18Registers(PIC pic) : base(pic)
        {
            lock (_symtabLock)
            {
                UniqueRegNames.Clear();
                UniqueFieldNames.Clear();
                RegsByAddr.Clear();
                RegsBitFields.Clear();
                SubRegisters.Clear();
            }
        }

        #endregion

        #region Helpers

        private PICRegisterStorage _getRegister(string name)
        {
            lock (_symtabLock)
            {
                if (!UniqueRegNames.TryGetValue(name, out PICRegisterStorage reg))
                    throw new InvalidOperationException($"Missing definition of register '{name}' in symbol table.");
                return reg;
            }
        }

        private PICRegisterStorage _peekRegister(string name)
        {
            lock (_symtabLock)
            {
                UniqueRegNames.TryGetValue(name, out PICRegisterStorage reg);
                return reg;
            }
        }

        private PICRegisterStorage _peekRegister(RegAddress aAddr)
        {
            lock (_symtabLock)
            {
                if (RegsByAddr.TryGetValue(aAddr, out RegisterStorage reg))
                {
                    return reg as PICRegisterStorage;
                }
                return null;
            }
        }

        private RegisterStorage _peekRegister(int number)
        {
            lock (_symtabLock)
            {
                var reg = RegsByAddr.Where(l => l.Value.Number == number)
                    .Select(e => (KeyValuePair<RegAddress, RegisterStorage>?)e)
                    .FirstOrDefault()?.Value;
                return reg ?? RegisterStorage.None;
            }
        }

        private RegisterStorage _peekCoreRegister(int i)
        {
            lock (_symtabLock)
            {
                var entry = RegsByAddr.Where(p => p.Value.Number == i).Select(e => e.Value).FirstOrDefault();
                return entry ?? RegisterStorage.None;
            }
        }

        private PICBitFieldStorage _getBitField(string name)
        {
            lock (_symtabLock)
            {
                if (!UniqueFieldNames.TryGetValue(name, out PICBitFieldStorage fld))
                    throw new InvalidOperationException($"Missing definition of bit field '{name}' in symbol table.");
                return fld;
            }
        }

        private PICBitFieldStorage _peekBitField(string name)
        {
            lock (_symtabLock)
            {
                UniqueFieldNames.TryGetValue(name, out PICBitFieldStorage fld);
                return fld;
            }
        }

        private FlagGroupStorage _peekBitField(PICDataAddress regAddress, uint bitPos, uint bitWidth = 0)
        {
            lock (_symtabLock)
            {
                if (RegsBitFields.TryGetValue(new BitFieldAddr(regAddress, bitPos), out BitFieldList flist))
                {
                    if (bitWidth == 0)
                        return flist.LastOrDefault().Value;
                    return flist.FirstOrDefault(f => f.Value.BitWidth == bitWidth).Value;
                }
            }
            return null;

        }

        /// <summary>
        /// This method sets the standard "core" registers as retrieved from the registers symbol table populated by the PIC definition.
        /// </summary>
        /// <remarks>
        /// This permits to still get a direct reference to standard registers and keeps having the capability to get a dynamic definition
        /// </remarks>
        /// <exception cref="InvalidOperationException">Thrown when the requested operation is invalid.</exception>
        private void _setCoreRegisters()
        {

            STATUS = _getRegister("STATUS");
            C = _getBitField("C");
            DC = _getBitField("DC");
            Z = _getBitField("Z");
            OV = _getBitField("OV");
            N = _getBitField("Z");

            PD = _peekBitField("PD");
            if (PD == null)
                PD = _peekBitField("nPD");
            TO = _peekBitField("TO");
            if (TO == null)
                TO = _peekBitField("nTO");

            FSR2L = _getRegister("FSR2L");
            FSR2H = _getRegister("FSR2H");
            PLUSW2 = _getRegister("PLUSW2");
            PREINC2 = _getRegister("PREINC2");
            POSTDEC2 = _getRegister("POSTDEC2");
            POSTINC2 = _getRegister("POSTINC2");
            INDF2 = _getRegister("INDF2");
            BSR = _getRegister("BSR");
            FSR1L = _getRegister("FSR1L");
            FSR1H = _getRegister("FSR1H");
            PLUSW1 = _getRegister("PLUSW1");
            PREINC1 = _getRegister("PREINC1");
            POSTDEC1 = _getRegister("POSTDEC1");
            POSTINC1 = _getRegister("POSTINC1");
            INDF1 = _getRegister("INDF1");
            WREG = _getRegister("WREG");
            FSR0L = _getRegister("FSR0L");
            FSR0H = _getRegister("FSR0H");
            PLUSW0 = _getRegister("PLUSW0");
            PREINC0 = _getRegister("PREINC0");
            POSTDEC0 = _getRegister("POSTDEC0");
            POSTINC0 = _getRegister("POSTINC0");
            INDF0 = _getRegister("INDF0");
            PRODL = _getRegister("PRODL");
            PRODH = _getRegister("PRODH");
            TABLAT = _getRegister("TABLAT");
            TBLPTRL = _getRegister("TBLPTRL");
            TBLPTRH = _getRegister("TBLPTRH");
            TBLPTRU = _getRegister("TBLPTRU");
            PCL = _getRegister("PCL");
            PCLATH = _getRegister("PCLATH");
            PCLATU = _getRegister("PCLATU");
            STKPTR = _getRegister("STKPTR");
            TOSL = _getRegister("TOSL");
            TOSH = _getRegister("TOSH");
            TOSU = _getRegister("TOSU");

            PROD = new PICRegisterStorage("PROD", PRODL.Number, PrimitiveType.Word16) { Address = PRODL.Address };
            PRODH.BitAddress = 8;
            FSR0 = new PICRegisterStorage("FSR0", FSR0L.Number, PrimitiveType.Ptr16) { Address = FSR0L.Address };
            FSR0H.BitAddress = 8;
            FSR1 = new PICRegisterStorage("FSR1", FSR1L.Number, PrimitiveType.Ptr16) { Address = FSR1L.Address };
            FSR1H.BitAddress = 8;
            FSR2 = new PICRegisterStorage("FSR2", FSR2L.Number, PrimitiveType.Ptr16) { Address = FSR2L.Address };
            FSR2H.BitAddress = 8;
            TOS = new PICRegisterStorage("TOS", TOSL.Number, PrimitiveType.Word32) { Address = TOSL.Address };
            TOSH.BitAddress = 8;
            TOSU.BitAddress = 16;
            PC = new PICRegisterStorage("PC", PCL.Number, PrimitiveType.Ptr32) { Address = PCL.Address };
            PCLATH.BitAddress = 8;
            PCLATU.BitAddress = 16;
            TBLPTR = new PICRegisterStorage("TBLPTR", TBLPTRL.Number, PrimitiveType.Word32) { Address = TBLPTRL.Address };
            TBLPTRH.BitAddress = 8;
            TBLPTRU.BitAddress = 16;

            SubRegisters.Add(PROD, new Dictionary<uint, RegisterStorage> { { 0x0008, PRODL }, { 0x0808, PRODH } });
            SubRegisters.Add(FSR0, new Dictionary<uint, RegisterStorage> { { 0x0008, FSR0L }, { 0x0808, FSR0H } });
            SubRegisters.Add(FSR1, new Dictionary<uint, RegisterStorage> { { 0x0008, FSR1L }, { 0x0808, FSR1H } });
            SubRegisters.Add(FSR2, new Dictionary<uint, RegisterStorage> { { 0x0008, FSR2L }, { 0x0808, FSR2H } });
            SubRegisters.Add(TOS, new Dictionary<uint, RegisterStorage> { { 0x0008, TOSL }, { 0x0808, TOSH }, { 0x1008, TOSU } });
            SubRegisters.Add(PC, new Dictionary<uint, RegisterStorage> { { 0x0008, PCL }, { 0x0808, PCLATH }, { 0x1008, PCLATU } });
            SubRegisters.Add(TBLPTR, new Dictionary<uint, RegisterStorage> { { 0x0008, TBLPTRL }, { 0x0808, TBLPTRH }, { 0x1008, TBLPTRU } });

        }

        #endregion

        #region Methods

        /// <summary>
        /// Creates a new <see cref="PIC18Registers"/> instance.
        /// </summary>
        /// <param name="pic">The PIC definition.</param>
        /// <returns>
        /// A <see cref="PICRegistersBuilder"/> instance.
        /// </returns>
        /// <exception cref="ArgumentNullException">Parameter <paramref name="pic"/> is null.</exception>
        public static PIC18Registers Create(PIC pic)
        {
            if (pic == null) throw new ArgumentNullException(nameof(pic));
            _registers = new PIC18Registers(pic);
            return _registers;
        }

        /// <summary>
        /// Loads the PIC18 registers into the registers symbol table.
        /// </summary>
        public void LoadRegisters()
        {
            base.LoadRegisters(this);
            _setCoreRegisters();
        }

        #endregion

        #region IRegisterSymTable interface

        /// <summary>
        /// Adds a PIC register. Returns null if no addition done.
        /// </summary>
        /// <param name="reg">The register.</param>
        /// <returns>
        /// A <seealso cref="RegisterStorage"/> or null if tentative of duplication.
        /// </returns>
        public RegisterStorage AddRegister(PICRegisterStorage reg)
        {
            RegAddress addr = (reg.IsNMMR ? new RegAddress(reg.SFRDef.NMMRID) : new RegAddress(reg.Address));

            lock (_symtabLock)
            {
                if (UniqueRegNames.ContainsKey(reg.Name)) return null;      // Do not duplicate name
                if (RegsByAddr.ContainsKey(addr)) return null;   // Do not duplicate register with same address
                UniqueRegNames[reg.Name] = reg;
                RegsByAddr[addr] = reg;
            }
            return reg;
        }

        /// <summary>
        /// Adds a register's named bit field. Returns null if no addition done.
        /// </summary>
        /// <param name="reg">The parent register.</param>
        /// <param name="field">The bit field.</param>
        /// <returns>
        /// A <seealso cref="FlagGroupStorage"/> or null if tentative of duplication.
        /// </returns>
        public FlagGroupStorage AddRegisterField(PICRegisterStorage reg, PICBitFieldStorage field)
        {
            lock (_symtabLock)
            {
                if (UniqueRegNames.ContainsKey(field.Name)) return null;      // Do not duplicate name
                BitFieldAddr key = new BitFieldAddr(reg.Address, field.BitPos);
                if (!RegsBitFields.ContainsKey(key))
                {
                    var newfieldlist = new BitFieldList
                    {
                        { field.BitWidth, field }
                    };
                    UniqueFieldNames[field.Name] = field;
                    RegsBitFields[key] = newfieldlist;
                    return field;
                }
                var fieldlist = RegsBitFields[key];
                if (!fieldlist.ContainsKey(field.BitWidth))
                {
                    UniqueFieldNames[field.Name] = field;
                    fieldlist.Add(field.BitWidth, field);
                    return field;
                }
            }
            return null;
        }

        #endregion

        #region Registers API

        /// <summary>
        /// Gets all the defined PIC registers.
        /// </summary>
        /// <value>
        /// An array of PIC registers.
        /// </value>
        public static RegisterStorage[] GetRegisters => RegsByAddr.Values.ToArray();

        /// <summary>
        /// Gets a register by its name or <seealso cref="RegisterStorage.None"/>.
        /// </summary>
        /// <param name="name">The name as a string.</param>
        /// <returns>
        /// The register or null.
        /// </returns>
        public static RegisterStorage GetRegister(string name)
        {
            PICRegisterStorage reg = _registers?._peekRegister(name);
            if (reg == null)
                return RegisterStorage.None;
            return reg;
        }

        /// <summary>
        /// Gets a register by its address or <seealso cref="RegisterStorage.None"/>.
        /// </summary>
        /// <param name="address">The data memory address.</param>
        /// <returns>
        /// The register or null.
        /// </returns>
        public static RegisterStorage GetRegister(PICDataAddress address)
        {
            RegAddress addr = new RegAddress(address);
            RegisterStorage reg = _registers?._peekRegister(addr);
            if (reg == null)
                return RegisterStorage.None;
            return reg;
        }

        /// <summary>
        /// Gets a register by its absolute address or <seealso cref="RegisterStorage.None"/>.
        /// </summary>
        /// <param name="uAddr">The absolute address of the register.</param>
        /// <returns>
        /// The register or <seealso cref="RegisterStorage.None"/>.
        /// </returns>
        public static RegisterStorage GetRegister(ushort uAddr)
        {
            var regaddr = new RegAddress(uAddr);
            RegisterStorage reg = _registers?._peekRegister(regaddr);
            if (reg == null)
                return RegisterStorage.None;
            return reg;
        }

        /// <summary>
        /// Gets a register by its index number or <seealso cref="RegisterStorage.None"/>.
        /// </summary>
        /// <param name="number">Index number of the register.</param>
        /// <returns>
        /// The register or <seealso cref="RegisterStorage.None"/>.
        /// </returns>
        public static RegisterStorage GetRegister(int number)
        {
            return _registers?._peekRegister(number) ?? RegisterStorage.None;
        }

        /// <summary>
        /// Gets a standard (core) register by its index or <seealso cref="RegisterStorage.None"/>.
        /// </summary>
        /// <param name="i">Zero-based index of the register.</param>
        /// <returns>
        /// The register or <seealso cref="RegisterStorage.None"/>.
        /// </returns>
        public static RegisterStorage GetCoreRegister(int i)
        {
            return _registers?._peekCoreRegister(i) ?? RegisterStorage.None;
        }

        /// <summary>
        /// Gets a register bit field by its name or null.
        /// </summary>
        /// <param name="name">The name as a string.</param>
        /// <returns>
        /// The bit field or null.
        /// </returns>
        public static FlagGroupStorage GetBitField(string name)
        {
            return _registers?._peekBitField(name);
        }

        /// <summary>
        /// Gets a register bit field by its register address and bit position/width or null.
        /// If <paramref name="bitwidth"/> is 0, then the widest bit field is retrieved.
        /// </summary>
        /// <param name="regAddress">The parent register address.</param>
        /// <param name="bitPos">The bit position.</param>
        /// <param name="bitWidth">(Optional) The bit field width.</param>
        /// <returns>
        /// The bit field or null.
        /// </returns>
        public static FlagGroupStorage GetBitField(PICDataAddress regAddress, uint bitPos, uint bitWidth = 0)
        {
            return _registers?._peekBitField(regAddress, bitPos, bitWidth);
        }

        /// <summary>
        /// Gets a register bit field by its register and bit position/width or null.
        /// If <paramref name="bitWidth"/> is 0, then the widest bit field is retrieved.
        /// </summary>
        /// <param name="reg">The parent register.</param>
        /// <param name="bitPos">The bit position.</param>
        /// <param name="bitWidth">(Optional) The bit field width.</param>
        /// <returns>
        /// The bit field or null.
        /// </returns>
        public static FlagGroupStorage GetBitField(PICRegisterStorage reg, uint bitPos, uint bitWidth = 0)
        {
            if (reg == null) return null;
            return GetBitField(reg.Address, bitPos, bitWidth);
        }

        /// <summary>
        /// Gets a register bit field by its register name and bit position/width or null.
        /// If <paramref name="bitWidth"/> is 0, then the widest bit field is retrieved.
        /// </summary>
        /// <param name="name">The parent register name.</param>
        /// <param name="bitPos">The bit position.</param>
        /// <param name="bitWidth">(Optional) The bit field width.</param>
        /// <returns>
        /// The bit field or null.
        /// </returns>
        public static FlagGroupStorage GetBitField(string name, uint bitPos, uint bitWidth = 0)
        {
            return GetBitField(GetRegister(name) as PICRegisterStorage, bitPos, bitWidth);
        }

        /// <summary>
        /// Gets the maximum number of registers.
        /// </summary>
        public static int Max => RegsByAddr.Count;

        #endregion

    }

}
