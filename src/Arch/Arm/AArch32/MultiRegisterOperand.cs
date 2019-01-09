﻿#region License
/* 
 * Copyright (C) 1999-2019 John Källén.
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

using Reko.Core;
using Reko.Core.Machine;
using Reko.Core.Types;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Reko.Arch.Arm.AArch32
{
    public class MultiRegisterOperand : MachineOperand
    {
        private readonly RegisterStorage[] registers;
        private readonly uint bitmask;

        public MultiRegisterOperand(RegisterStorage[] registers, PrimitiveType width, uint bitmask) : base(width)
        {
            this.registers = registers;
            this.bitmask = bitmask;
        }

        public IEnumerable<RegisterStorage> GetRegisters()
        {
            int mask = 1;
            for (int i = 0; i < 32; ++i, mask <<= 1)
            {
                if ((bitmask & mask) != 0)
                    yield return registers[i];
            }
        }

        public override void Write(MachineInstructionWriter writer, MachineInstructionWriterOptions options)
        {
            var sep = "{";
            int mask = 1;
            int iStart = -1;
            for (int i = 0; i < 33; ++i, mask <<= 1)
            {
                if ((bitmask & mask) != 0)
                {
                    if (iStart < 0)
                    {
                        // Start a range
                        writer.WriteString(sep);
                        sep = ",";
                        iStart = i;
                        writer.WriteString(registers[i].Name);
                    }
                }
                else
                {
                    if (0 <= iStart && iStart < i - 1)
                    {
                        writer.WriteChar('-');
                        writer.WriteString(registers[i-1].Name);
                    }
                    iStart = -1;
                }
            }
            writer.WriteChar('}');
        }
    }
}
