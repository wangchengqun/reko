// TLCS-90.c
// Generated by decompiling TLCS-90.corpus
// using Reko decompiler version 0.8.0.2.

#include "TLCS-90.h"

// 0000: void fn0000(Register cu8 a, Stack ui16 wArg00)
void fn0000(cu8 a, ui16 wArg00)
{
	*null = a;
}

// 02C2: void fn02C2(Register byte a)
void fn02C2(byte a)
{
}

// 02F4: Register word16 fn02F4(Register word16 af, Register Eq_10 b, Register Eq_10 c, Register Eq_12 de, Register ptr16 hl, Register (ptr16 Eq_14) ix, Register out Eq_15 bcOut, Register out Eq_16 deOut, Register out Eq_17 hlOut, Register out Eq_18 ixOut)
word16 fn02F4(word16 af, Eq_10 b, Eq_10 c, Eq_12 de, ptr16 hl, Eq_14 * ix, Eq_15 & bcOut, Eq_16 & deOut, Eq_17 & hlOut, Eq_18 & ixOut)
{
	cu8 a_7 = (bool) C + (a + ix->bFFFFFFE4);
	ui8 a_24 = b ^ ix->bFFFFFFFB;
	ui8 a_28 = a_7 ^ ix->bFFFFFFFC;
	ui8 a_32 = (bool) (a_7 < 0x00) + (h + ix->bFFFFFFE5) ^ ix->bFFFFFFFD;
	Eq_10 a_36 = (word16) ix->tFFFFFFF6 + (c ^ ix->bFFFFFFFA);
	ix->tFFFFFFF6 = a_36;
	Eq_10 a_42 = (bool) (a_36 < 0x00) + ((word16) ix->tFFFFFFF7 + a_24);
	ix->tFFFFFFF7 = a_42;
	Eq_10 a_48 = (bool) (a_42 < 0x00) + ((word16) ix->tFFFFFFF8 + a_28);
	ix->tFFFFFFF8 = a_48;
	ix->tFFFFFFF9 = (bool) (a_48 < 0x00) + ((word16) ix->tFFFFFFF9 + a_32);
	Eq_10 c_63 = ix->tFFFFFFF6;
	Eq_10 b_65 = ix->tFFFFFFF7;
	ui16 hl_73 = DPB(hl, ix->tFFFFFFF9, 8);
	byte a_76 = 0x04;
	word16 af_77 = DPB(af, 0x04, 8);
	do
	{
		c_63 <<= 0x01;
		b_65 = __rcl(b_65, 0x01, (bool) cond(c_63));
		hl_73 = hl_73 * 0x02 + (b_65 < 0x00);
		--a_76;
		Eq_10 h_92 = SLICE(hl_73, byte, 8);
		Eq_10 l_93 = (byte) hl_73;
		af_77 = DPB(af_117, a_76, 8);
		word16 af_117 = af_77;
	} while (a_76 != 0x00);
	word16 af_103 = DPB(af_117, c_63 + Mem59[ix + -0x0022:byte], 8);
	word16 bc_107;
	word16 de_108;
	word16 hl_109;
	word16 ix_110;
	return fn034E(af_103, c_63, b_65, de, l_93, h_92, ix, out bc_107, out de_108, out hl_109, out ix_110);
}

// 034E: Register word16 fn034E(Register word16 af, Register Eq_10 c, Register Eq_10 b, Register Eq_12 de, Register Eq_10 l, Register Eq_10 h, Register (ptr16 Eq_14) ix, Register out Eq_157 bcOut, Register out Eq_158 deOut, Register out Eq_159 hlOut, Register out Eq_160 ixOut)
word16 fn034E(word16 af, Eq_10 c, Eq_10 b, Eq_12 de, Eq_10 l, Eq_10 h, Eq_14 * ix, Eq_157 & bcOut, Eq_158 & deOut, Eq_159 & hlOut, Eq_160 & ixOut)
{
	ix->bFFFFFFFA = a;
	word16 bc_11;
	word16 de_12;
	word16 hl_13;
	word16 ix_14;
	return fn03B2(af, c, b, de, l, h, ix, out bc_11, out de_12, out hl_13, out ix_14);
}

// 0350: Register word16 fn0350(Register word16 af, Register Eq_10 b, Register Eq_12 de, Register Eq_10 l, Register Eq_10 h, Register (ptr16 Eq_14) ix, Register out Eq_198 bcOut, Register out Eq_199 deOut, Register out Eq_200 hlOut, Register out Eq_201 ixOut)
word16 fn0350(word16 af, Eq_10 b, Eq_12 de, Eq_10 l, Eq_10 h, Eq_14 * ix, Eq_198 & bcOut, Eq_199 & deOut, Eq_200 & hlOut, Eq_201 & ixOut)
{
	byte a_8 = b + Mem0[ix + -33:byte] + C;
	ix->bFFFFFFFB = a_8;
	byte a_15 = l + Mem11[ix + -0x0020:byte] + (a_8 <u 0x00);
	ix->bFFFFFFFC = a_15;
	ix->bFFFFFFFD = (uint8) ((bool) (a_15 < 0x00) + ((word16) h + ix->bFFFFFFE1));
	cu8 a_27 = (word16) ix->tFFFFFFF6 + ix->bFFFFFFEE;
	cu8 a_34 = (bool) (a_27 < 0x00) + ((word16) ix->tFFFFFFF7 + ix->bFFFFFFEF);
	cu8 a_41 = (bool) (a_34 < 0x00) + ((word16) ix->tFFFFFFF8 + ix->bFFFFFFF0);
	byte a_48 = (bool) (a_41 < 0x00) + ((word16) ix->tFFFFFFF9 + ix->bFFFFFFF1);
	ix->bFFFFFFFA = ix->bFFFFFFFA ^ a_27;
	ix->bFFFFFFFB = ix->bFFFFFFFB ^ a_34;
	ix->bFFFFFFFC = ix->bFFFFFFFC ^ a_41;
	uint8 a_64 = ix->bFFFFFFFD ^ a_48;
	ix->bFFFFFFFD = a_64;
	*(v3 - 0x02) = DPB(af, a_64, 8);
	Eq_10 v32_75 = ix->tFFFFFFF6;
	Eq_10 v33_77 = ix->tFFFFFFF7;
	Eq_10 v34_81 = ix->tFFFFFFF8;
	Eq_10 v35_83 = ix->tFFFFFFF9;
	word16 af_90 = DPB(Mem74[v3 - 0x02 + 0x00:word16], 0x05, 8);
	word16 bc_92;
	word16 de_93;
	word16 hl_94;
	word16 ix_95;
	return fn03B2(af_90, v32_75, v33_77, de, v34_81, v35_83, ix, out bc_92, out de_93, out hl_94, out ix_95);
}

// 039D: void fn039D(Register word16 af, Register Eq_12 de, Register byte h, Register (ptr16 Eq_14) ix)
void fn039D(word16 af, Eq_12 de, byte h, Eq_14 * ix)
{
	ix->bFFFFFFFD = a ^ h;
	Eq_10 v12_16 = ix->tFFFFFFF6;
	Eq_10 v14_18 = ix->tFFFFFFF7;
	Eq_10 v16_22 = ix->tFFFFFFF8;
	Eq_10 v18_24 = ix->tFFFFFFF9;
	word16 af_31 = DPB(af, 0x05, 8);
	word16 bc_33;
	word16 de_34;
	word16 hl_35;
	word16 ix_36;
	fn03B2(af_31, v12_16, v14_18, de, v16_22, v18_24, ix, out bc_33, out de_34, out hl_35, out ix_36);
}

// 03AA: void fn03AA()
void fn03AA()
{
}

// 03B2: Register word16 fn03B2(Register word16 af, Register Eq_10 c, Register Eq_10 b, Register Eq_12 de, Register Eq_10 l, Register Eq_10 h, Register (ptr16 Eq_14) ix, Register out Eq_183 bcOut, Register out Eq_184 deOut, Register out Eq_185 hlOut, Register out Eq_186 ixOut)
word16 fn03B2(word16 af, Eq_10 c, Eq_10 b, Eq_12 de, Eq_10 l, Eq_10 h, Eq_14 * ix, Eq_183 & bcOut, Eq_184 & deOut, Eq_185 & hlOut, Eq_186 & ixOut)
{
}

// 03CD: void fn03CD(Register word16 af, Register byte b, Register byte c, Register Eq_12 de, Register byte l, Register (ptr16 Eq_14) ix)
void fn03CD(word16 af, byte b, byte c, Eq_12 de, byte l, Eq_14 * ix)
{
	ui8 a_17 = b ^ ix->bFFFFFFFB;
	ui8 a_22 = l ^ ix->bFFFFFFFC;
	ui8 a_26 = (bool) C + (a + ix->bFFFFFFDD) ^ ix->bFFFFFFFD;
	Eq_10 a_30 = (word16) ix->tFFFFFFF2 + (c ^ ix->bFFFFFFFA);
	ix->tFFFFFFF2 = a_30;
	Eq_10 a_36 = (bool) (a_30 < 0x00) + ((word16) ix->tFFFFFFF3 + a_17);
	ix->tFFFFFFF3 = a_36;
	Eq_10 a_42 = (bool) (a_36 < 0x00) + ((word16) ix->tFFFFFFF4 + a_22);
	ix->tFFFFFFF4 = a_42;
	ix->tFFFFFFF5 = (bool) (a_42 < 0x00) + ((word16) ix->tFFFFFFF5 + a_26);
	Eq_10 v24_50 = ix->tFFFFFFEA;
	Eq_10 a_58 = (bool) (v24_50 < ~0x00) + ((word16) ix->tFFFFFFEB + 0x00FF);
	Eq_10 a_66 = (bool) (a_58 < 0x00) + ((word16) ix->tFFFFFFEC + 0x00FF);
	Eq_10 a_72 = (bool) (a_66 < 0x00) + ((word16) ix->tFFFFFFED + 0x00FF);
	ix->tFFFFFFEA = (word16) v24_50 + 0x00FF;
	ix->tFFFFFFEB = a_58;
	ix->tFFFFFFEC = a_66;
	ix->tFFFFFFED = a_72;
	byte a_83 = a_72 | a_66 | a_58 | (word16) v24_50 + 0x00FF;
	word16 af_85 = DPB(af, a_83, 8);
	if (a_83 != 0x00)
	{
		word16 bc_103;
		word16 de_104;
		word16 hl_105;
		word16 ix_106;
		fn0350(af_85, a_58, de, a_66, a_72, ix, out bc_103, out de_104, out hl_105, out ix_106);
	}
	else
	{
		word16 de_99;
		word16 hl_100;
		word16 ix_101;
		fn0434(de, ix, out de_99, out hl_100, out ix_101);
	}
}

// 0434: Register word16 fn0434(Register Eq_12 de, Register (ptr16 Eq_14) ix, Register out Eq_588 deOut, Register out Eq_589 hlOut, Register out Eq_590 ixOut)
word16 fn0434(Eq_12 de, Eq_14 * ix, Eq_588 & deOut, Eq_589 & hlOut, Eq_590 & ixOut)
{
	Eq_742 hl_14 = (char *) v3 + 0x001C;
	word16 bc_10;
	for (bc_10 = 0x04; bc_10 != 0x00; --bc_10)
	{
		*de = *hl_14;
		hl_14 = (word32) hl_14 + 0x01;
		de = (word32) de + 0x01;
	}
	Eq_762 de_22 = v3->t0024;
	Eq_766 hl_24 = (char *) v3 + 0x0018;
	word16 bc_27;
	for (bc_27 = 0x04; bc_27 != 0x00; --bc_27)
	{
		*de_22 = *hl_24;
		hl_24 = (word32) hl_24 + 0x01;
		*hlOut = hl_24;
		++de_22;
		*deOut = de_22;
	}
	word16 ix_41;
	*ixOut = ix->w0000;
	return bc_27;
}

// 04EE: void fn04EE(Register word16 af, Register Eq_793 de, Register word16 hl, Register (ptr16 Eq_14) ix)
void fn04EE(word16 af, Eq_793 de, word16 hl, Eq_14 * ix)
{
	ix->bFFFFFFDB = 55;
	ix->bFFFFFFDC = ~0x10;
	ix->bFFFFFFDD = 0xC6;
	Eq_10 c_13 = ix->tFFFFFFE6;
	Eq_10 b_15 = ix->tFFFFFFE7;
	ui16 hl_21 = DPB(hl, ix->bFFFFFFE9, 8);
	byte a_24 = 0x04;
	word16 af_25 = DPB(af, 0x04, 8);
	do
	{
		c_13 <<= 0x01;
		b_15 = __rcl(b_15, 0x01, (bool) cond(c_13));
		hl_21 = hl_21 * 0x02 + (b_15 < 0x00);
		--a_24;
		byte h_38 = SLICE(hl_21, byte, 8);
		byte l_39 = (byte) hl_21;
		af_25 = DPB(af_281, a_24, 8);
		word16 af_281 = af_25;
	} while (a_24 != 0x00);
	byte a_48 = c_13 + Mem9[ix + -0x0A:byte];
	ix->bFFFFFFFC = a_48;
	byte a_54 = b_15 + Mem51[ix + -0x09:byte] + (a_48 <u 0x00);
	ix->bFFFFFFFD = a_54;
	uint8 a_60 = (bool) (a_54 < 0x00) + ((word16) ix->tFFFFFFF8 + l_39);
	ix->bFFFFFFFE = a_60;
	ix->bFFFFFFFF = (ui8) ((bool) (a_60 < 0x00) + ((word16) ix->tFFFFFFF9 + h_38));
	cu8 a_71 = (word16) ix->tFFFFFFE6 + ix->bFFFFFFDA;
	cu8 a_78 = (bool) (a_71 < 0x00) + ((word16) ix->tFFFFFFE7 + ix->bFFFFFFDB);
	cu8 a_85 = (bool) (a_78 < 0x00) + ((word16) ix->tFFFFFFE8 + ix->bFFFFFFDC);
	byte a_92 = (bool) (a_85 < 0x00) + (ix->bFFFFFFE9 + ix->bFFFFFFDD);
	ix->bFFFFFFFC = ix->bFFFFFFFC ^ a_71;
	ix->bFFFFFFFD = ix->bFFFFFFFD ^ a_78;
	ix->bFFFFFFFE = ix->bFFFFFFFE ^ a_85;
	ix->bFFFFFFFF = ix->bFFFFFFFF ^ a_92;
	uint8 v43_124 = ix->bFFFFFFE9;
	Eq_10 c_119 = ix->tFFFFFFE6;
	Eq_10 b_121 = ix->tFFFFFFE7;
	Eq_10 l_123 = ix->tFFFFFFE8;
	uint8 h_125 = v43_124;
	ui16 hl_126 = DPB(hl_21, v43_124, 8);
	byte a_129 = 0x05;
	word16 af_130 = DPB(af_281, 0x05, 8);
	do
	{
		h_125 >>= 0x01;
		l_123 = __rcr(l_123, 0x01, (bool) cond(h_125));
		b_121 = __rcr(b_121, 0x01, (bool) cond(l_123));
		--a_129;
		hl_126 = DPB(hl_126, l_123, 0);
		c_119 = __rcr(c_119, 0x01, (bool) cond(b_121));
		af_130 = DPB(af_282, a_129, 8);
		word16 af_282 = af_130;
	} while (a_129 != 0x00);
	byte a_157 = c_119 + Mem115[ix + -22:byte];
	byte a_163 = b_121 + Mem115[ix + -0x0015:byte] + (a_157 <u 0x00);
	byte a_169 = l_123 + Mem115[ix + -0x0014:byte] + (a_163 <u 0x00);
	ui8 a_183 = a_163 ^ ix->bFFFFFFFD;
	ui8 a_187 = a_169 ^ ix->bFFFFFFFE;
	ui8 a_191 = (word16) ix->tFFFFFFED + h_125 + (a_169 < 0x00) ^ ix->bFFFFFFFF;
	Eq_10 a_195 = ix->tFFFFFFDE - (a_157 ^ ix->bFFFFFFFC);
	ix->tFFFFFFDE = a_195;
	Eq_10 a_201 = ix->tFFFFFFDF - a_183 - (a_195 < 0x00);
	ix->tFFFFFFDF = a_201;
	Eq_10 a_207 = ix->tFFFFFFE0 - a_187 - (a_201 < 0x00);
	ix->tFFFFFFE0 = a_207;
	ix->bFFFFFFE1 = ix->bFFFFFFE1 - a_191 - (a_207 < 0x00);
	Eq_10 c_221 = ix->tFFFFFFDE;
	Eq_10 b_223 = ix->tFFFFFFDF;
	ui16 hl_228 = DPB(hl_126, ix->bFFFFFFE1, 8);
	byte a_231 = 0x04;
	word16 af_232 = DPB(af_282, 0x04, 8);
	do
	{
		c_221 <<= 0x01;
		b_223 = __rcl(b_223, 0x01, (bool) cond(c_221));
		hl_228 = hl_228 * 0x02 + (b_223 < 0x00);
		--a_231;
		byte h_245 = SLICE(hl_228, byte, 8);
		byte l_246 = (byte) hl_228;
		af_232 = DPB(af_283, a_231, 8);
		word16 af_283 = af_232;
	} while (a_231 != 0x00);
	uint8 a_255 = (byte) c_221.u1 + ix->bFFFFFFEE;
	ix->bFFFFFFFC = a_255;
	uint8 a_261 = (bool) (a_255 < 0x00) + ((word16) b_223 + ix->bFFFFFFEF);
	ix->bFFFFFFFD = a_261;
	uint8 a_267 = (bool) (a_261 < 0x00) + (l_246 + ix->bFFFFFFF0);
	ix->bFFFFFFFE = a_267;
	ix->bFFFFFFFF = (ui8) ((bool) (a_267 < 0x00) + (h_245 + ix->bFFFFFFF1));
	word16 af_279 = DPB(af_283, ix->tFFFFFFDE, 8);
	fn0607(af_279, de, ix);
}

// 0607: void fn0607(Register word16 af, Register Eq_793 de, Register (ptr16 Eq_14) ix)
void fn0607(word16 af, Eq_793 de, Eq_14 * ix)
{
	cu8 a_6 = a + ix->bFFFFFFDA;
	word16 af_13 = DPB(af, ix->tFFFFFFDF, 8);
	fn060E(af_13, a_6, de, ix);
}

// 060E: void fn060E(Register word16 af, Register cu8 c, Register Eq_793 de, Register (ptr16 Eq_14) ix)
void fn060E(word16 af, cu8 c, Eq_793 de, Eq_14 * ix)
{
	do
	{
		cu8 a_25 = (bool) C + (a + ix->bFFFFFFDB);
		cu8 a_32 = (bool) (a_25 < 0x00) + ((word16) ix->tFFFFFFE0 + ix->bFFFFFFDC);
		byte a_39 = (bool) (a_32 < 0x00) + (ix->bFFFFFFE1 + ix->bFFFFFFDD);
		ix->bFFFFFFFC = ix->bFFFFFFFC ^ c;
		ix->bFFFFFFFD = ix->bFFFFFFFD ^ a_25;
		ix->bFFFFFFFE = ix->bFFFFFFFE ^ a_32;
		ui8 a_55 = ix->bFFFFFFFF ^ a_39;
		ix->bFFFFFFFF = a_55;
		*(v3 - 0x02) = DPB(af, a_55, 8);
		Eq_10 c_66 = ix->tFFFFFFDE;
		Eq_10 b_68 = ix->tFFFFFFDF;
		Eq_10 l_71 = ix->tFFFFFFE0;
		uint8 h_73 = ix->bFFFFFFE1;
		byte a_100 = 0x05;
		word16 af_101 = DPB(Mem64[v3 - 0x02 + 0x00:word16], 0x05, 8);
		do
		{
			h_73 >>= 0x01;
			l_71 = __rcr(l_71, 0x01, (bool) cond(h_73));
			b_68 = __rcr(b_68, 0x01, (bool) cond(l_71));
			--a_100;
			c_66 = __rcr(c_66, 0x01, (bool) cond(b_68));
			af_101 = DPB(af_284, a_100, 8);
			word16 af_284 = af_101;
		} while (a_100 != 0x00);
		byte a_107 = c_66 + Mem64[ix + -0x0E:byte];
		byte a_113 = b_68 + Mem64[ix + -0x0D:byte] + (a_107 <u 0x00);
		byte a_119 = l_71 + Mem64[ix + -0x0C:byte] + (a_113 <u 0x00);
		ui8 a_133 = a_113 ^ ix->bFFFFFFFD;
		ui8 a_137 = a_119 ^ ix->bFFFFFFFE;
		ui8 a_141 = (word16) ix->tFFFFFFF5 + h_73 + (a_119 < 0x00) ^ ix->bFFFFFFFF;
		Eq_10 a_145 = ix->tFFFFFFE6 - (a_107 ^ ix->bFFFFFFFC);
		ix->tFFFFFFE6 = a_145;
		Eq_10 a_151 = ix->tFFFFFFE7 - a_133 - (a_145 < 0x00);
		ix->tFFFFFFE7 = a_151;
		Eq_10 a_157 = ix->tFFFFFFE8 - a_137 - (a_151 < 0x00);
		ix->tFFFFFFE8 = a_157;
		ix->bFFFFFFE9 = ix->bFFFFFFE9 - a_141 - (a_157 < 0x00);
		cu8 v45_165 = ix->bFFFFFFDA;
		ix->bFFFFFFDA = v45_165 + 0x47;
		cu8 a_173 = (bool) (v45_165 < 0x47) + (ix->bFFFFFFDB + 0x86);
		ix->bFFFFFFDB = a_173;
		cu8 a_179 = (bool) (a_173 < 0x00) + (ix->bFFFFFFDC + 200);
		ix->bFFFFFFDC = a_179;
		ix->bFFFFFFDD = (bool) (a_179 < 0x00) + (ix->bFFFFFFDD + 0x61);
		cu8 v49_187 = ix->bFFFFFFE2;
		cu8 a_195 = (bool) (v49_187 < ~0x00) + (ix->bFFFFFFE3 + ~0x00);
		cu8 a_202 = (bool) (a_195 < 0x00) + (ix->bFFFFFFE4 + ~0x00);
		byte a_208 = (bool) (a_202 < 0x00) + (ix->bFFFFFFE5 + ~0x00);
		ix->bFFFFFFE2 = v49_187 + ~0x00;
		ix->bFFFFFFE3 = a_195;
		ix->bFFFFFFE4 = a_202;
		ix->bFFFFFFE5 = a_208;
		a = a_208 | a_202 | a_195 | v49_187 + ~0x00;
		c = v49_187 + ~0x00;
		af = DPB(af_284, a, 8);
		C.u0 = false;
	} while (a != 0x00);
	Eq_1500 hl_230 = (char *) v3 + 0x0C;
	word16 bc_235;
	for (bc_235 = 0x04; bc_235 != 0x00; --bc_235)
	{
		*de = *hl_230;
		hl_230 = (word32) hl_230 + 0x01;
		de = (word32) de + 0x01;
	}
	Eq_1519 de_256 = v3->t0020;
	Eq_1523 hl_258 = (char *) v3 + 0x04;
	word16 bc_263;
	for (bc_263 = 0x04; bc_263 != 0x00; --bc_263)
	{
		*de_256 = *hl_258;
		hl_258 = (word32) hl_258 + 0x01;
		++de_256;
	}
}

// 0805: void fn0805(Register byte a)
void fn0805(byte a)
{
	__disable_interrupts();
	fn0823(wLoc02);
	fn0822();
	__halt();
}

// 0822: void fn0822()
void fn0822()
{
	fn0823(wLoc02);
}

// 0823: void fn0823(Stack word16 wArg00)
void fn0823(word16 wArg00)
{
}

// 0AA6: void fn0AA6(Register word16 af, Register cu8 b, Register cu8 c, Register Eq_12 de, Register byte h, Register Eq_10 l, Register (ptr16 Eq_14) ix)
void fn0AA6(word16 af, cu8 b, cu8 c, Eq_12 de, byte h, Eq_10 l, Eq_14 * ix)
{
	ix->bFFFFFFFA = a ^ c;
	ix->bFFFFFFFB = ix->bFFFFFFFB ^ b;
	ix->bFFFFFFFC = ix->bFFFFFFFC ^ l;
	uint8 a_20 = ix->bFFFFFFFD ^ h;
	ix->bFFFFFFFD = a_20;
	*(v3 - 0x02) = DPB(af, a_20, 8);
	Eq_10 c_32 = ix->tFFFFFFF6;
	Eq_10 b_34 = ix->tFFFFFFF7;
	Eq_10 l_36 = ix->tFFFFFFF8;
	Eq_10 h_38 = ix->tFFFFFFF9;
	byte a_41 = 0x05;
	word16 af_42 = DPB(Mem30[v3 - 0x02 + 0x00:word16], 0x05, 8);
	do
	{
		h_38 >>= 0x01;
		Eq_389 C_53 = (bool) cond(h_38);
		l_36 = __rcr(l_36, 0x01, C_53);
		b_34 = __rcr(b_34, 0x01, (bool) cond(l_36));
		--a_41;
		c_32 = __rcr(c_32, 0x01, (bool) cond(b_34));
		af_42 = DPB(af_148, a_41, 8);
		word16 af_148 = af_42;
	} while (a_41 != 0x00);
	cu8 a_74 = (word16) c_32 + ix->bFFFFFFDA;
	cu8 a_80 = (bool) (a_74 < 0x00) + ((word16) b_34 + ix->bFFFFFFDB);
	cu8 a_86 = (bool) (a_80 < 0x00) + ((word16) l_36 + ix->bFFFFFFDC);
	uint8 a_92 = (byte) h_38.u1 + ix->bFFFFFFDD + (a_86 < 0x00);
	ui8 a_96 = a_74 ^ ix->bFFFFFFFA;
	ui8 a_100 = a_80 ^ ix->bFFFFFFFB;
	ui8 a_110 = a_86 ^ ix->bFFFFFFFC;
	ui8 a_120 = a_92 ^ ix->bFFFFFFFD;
	Eq_10 a_124 = (word16) ix->tFFFFFFF2 + a_96;
	ix->tFFFFFFF2 = a_124;
	Eq_10 a_130 = (bool) (a_124 < 0x00) + ((word16) ix->tFFFFFFF3 + a_100);
	ix->tFFFFFFF3 = a_130;
	word16 af_137 = DPB(af_148, (bool) (a_130 < 0x00) + ((word16) ix->tFFFFFFF4 + a_110), 8);
	fn0B1B(af_137, de, a_120, ix);
}

// 0B1B: void fn0B1B(Register word16 af, Register Eq_12 de, Register ui8 h, Register (ptr16 Eq_14) ix)
void fn0B1B(word16 af, Eq_12 de, ui8 h, Eq_14 * ix)
{
	ix->tFFFFFFF4 = a;
	ix->tFFFFFFF5 = (bool) C + ((word16) ix->tFFFFFFF5 + h);
	Eq_10 v10_11 = ix->tFFFFFFEA;
	word16 af_15 = DPB(af, (word16) v10_11 + 0x00FF, 8);
	fn0B2C(af_15, (word16) v10_11 + 0x00FF, de, ix);
}

// 0B2C: void fn0B2C(Register word16 af, Register Eq_10 c, Register Eq_12 de, Register (ptr16 Eq_14) ix)
void fn0B2C(word16 af, Eq_10 c, Eq_12 de, Eq_14 * ix)
{
	ptr32 fp;
	struct Eq_14 * ix;
	<type-error> Mem0;
	bool C;
	word16 bc;
	word16 hl;
	Eq_10 c;
	word16 af;
	Eq_12 de;
	sp_1 = fp;
	v4_4 = ix->tFFFFFFEB;
	a_5 = v4_4;
	a_7 = (bool) C + ((byte) a_5 + 0x00FF);
	SZHXVC_8 = cond(a_7);
	C_9 = (bool) SZHXVC_8;
	b_10 = a_7;
	bc_12 = DPB(bc, b_10, 8);
	v10_13 = ix->tFFFFFFEC;
	a_14 = v10_13;
	a_15 = (bool) (a_7 < 0x00) + ((byte) a_14 + 0x00FF);
	SZHXVC_16 = cond(a_15);
	C_17 = (bool) SZHXVC_16;
	l_18 = a_15;
	v12_19 = ix->tFFFFFFED;
	a_20 = v12_19;
	a_21 = (bool) (a_15 < 0x00) + ((byte) a_20 + 0x00FF);
	h_22 = a_21;
	hl_24 = DPB(hl, h_22, 8);
	ix->tFFFFFFEA = c;
	ix->tFFFFFFEB = b_10;
	ix->tFFFFFFEC = l_18;
	ix->tFFFFFFED = h_22;
	a_30 = h_22;
	a_31 = a_30 | l_18;
	a_32 = a_31 | b_10;
	a_33 = a_32 | c;
	af_35 = DPB(af, a_33, 8);
	H_36 = false;
	X_37 = false;
	N_38 = false;
	C_39 = false;
	SZV_40 = cond(a_33);
	SZHXVC_41 = SZV_40;
	Z_42 = (bool) SZV_40;
	if (a_33 != 0x00)
		af_53 = fn0350(af_35, b_10, de, l_18, h_22, ix, out bc_49, out de_50, out hl_51, out ix_52);
	else
		fn0B55(de, ix);
}

// 0B55: void fn0B55(Register Eq_12 de, Register (ptr16 Eq_14) ix)
void fn0B55(Eq_12 de, Eq_14 * ix)
{
	Eq_1944 hl_14 = (char *) v3 + 0x001C;
	word16 bc_10;
	for (bc_10 = 0x04; bc_10 != 0x00; --bc_10)
	{
		*de = *hl_14;
		hl_14 = (word32) hl_14 + 0x01;
		++de;
	}
	Eq_1964 de_22 = v3->t0024;
	Eq_1968 hl_24 = (char *) v3 + 0x0018;
	word16 bc_27;
	for (bc_27 = 0x04; bc_27 != 0x00; --bc_27)
	{
		*de_22 = *hl_24;
		hl_24 = (word32) hl_24 + 0x01;
		++de_22;
	}
}

// 0BFE: void fn0BFE()
void fn0BFE()
{
}

// 0C1D: void fn0C1D(Register Eq_793 de, Register word16 hl, Register (ptr16 Eq_14) ix, Stack word16 wArg00)
void fn0C1D(Eq_793 de, word16 hl, Eq_14 * ix, word16 wArg00)
{
	Eq_10 c_19 = ix->tFFFFFFE6;
	Eq_10 b_20 = ix->tFFFFFFE7;
	byte * hl_13 = DPB(hl, ix->bFFFFFFE9, 8);
	byte a_17 = 0x04;
	word16 af_18 = DPB(wArg00, 0x04, 8);
	do
	{
		c_19 <<= 0x01;
		b_20 = __rcl(b_20, 0x01, (bool) cond(c_19));
		--a_17;
		hl_13 = hl_13 * 0x02 + (b_20 < 0x00);
		af_18 = DPB(af_18, a_17, 8);
	} while (a_17 != 0x00);
	fn0C35(af_18, c_19, b_20, de, hl_13, ix);
}

// 0C35: void fn0C35(Register word16 af, Register Eq_10 c, Register Eq_10 b, Register Eq_793 de, Register (ptr16 byte) hl, Register (ptr16 Eq_14) ix)
void fn0C35(word16 af, Eq_10 c, Eq_10 b, Eq_793 de, byte * hl, Eq_14 * ix)
{
	word16 af_9 = DPB(af, c + Mem0[ix + -0x0A:byte], 8);
	fn0C39(af_9, b, de, hl, ix);
}

// 0C39: void fn0C39(Register word16 af, Register Eq_10 b, Register Eq_793 de, Register (ptr16 byte) hl, Register (ptr16 Eq_14) ix)
void fn0C39(word16 af, Eq_10 b, Eq_793 de, byte * hl, Eq_14 * ix)
{
	ix->bFFFFFFFC = a;
	byte a_9 = b + Mem3[ix + -0x09:byte] + C;
	ix->bFFFFFFFD = a_9;
	uint8 a_16 = (bool) (a_9 < 0x00) + ((word16) ix->tFFFFFFF8 + l);
	ix->bFFFFFFFE = a_16;
	ix->bFFFFFFFF = (ui8) ((bool) (a_16 < 0x00) + ((word16) ix->tFFFFFFF9 + h));
	cu8 a_28 = (word16) ix->tFFFFFFE6 + ix->bFFFFFFDA;
	cu8 a_35 = (bool) (a_28 < 0x00) + ((word16) ix->tFFFFFFE7 + ix->bFFFFFFDB);
	word16 hl_52 = DPB(hl, (bool) ((bool) (a_35 < 0x00) + ((word16) ix->tFFFFFFE8 + ix->bFFFFFFDC) < 0x00) + (ix->bFFFFFFE9 + ix->bFFFFFFDD), 8);
	ix->bFFFFFFFC = ix->bFFFFFFFC ^ a_28;
	ix->bFFFFFFFD = ix->bFFFFFFFD ^ a_35;
	word16 af_69 = DPB(af, ix->bFFFFFFFE, 8);
	fn0C80(af_69, de, hl_52, ix);
}

// 0C80: void fn0C80(Register word16 af, Register Eq_793 de, Register word16 hl, Register (ptr16 Eq_14) ix)
void fn0C80(word16 af, Eq_793 de, word16 hl, Eq_14 * ix)
{
	ix->bFFFFFFFE = a ^ l;
	ix->bFFFFFFFF = ix->bFFFFFFFF ^ h;
	uint8 v19_27 = ix->bFFFFFFE9;
	Eq_10 c_22 = ix->tFFFFFFE6;
	Eq_10 b_24 = ix->tFFFFFFE7;
	Eq_10 l_26 = ix->tFFFFFFE8;
	uint8 h_28 = v19_27;
	word16 hl_30 = DPB(hl, v19_27, 8);
	byte a_33 = 0x05;
	word16 af_34 = DPB(af, 0x05, 8);
	do
	{
		h_28 >>= 0x01;
		l_26 = __rcr(l_26, 0x01, (bool) cond(h_28));
		b_24 = __rcr(b_24, 0x01, (bool) cond(l_26));
		--a_33;
		hl_30 = DPB(hl_88, l_26, 0);
		c_22 = __rcr(c_22, 0x01, (bool) cond(b_24));
		af_34 = DPB(af_87, a_33, 8);
		word16 af_87 = af_34;
		word16 hl_88 = hl_30;
	} while (a_33 != 0x00);
	byte a_61 = c_22 + Mem18[ix + -22:byte];
	byte a_67 = b_24 + Mem18[ix + -0x0015:byte] + (a_61 <u 0x00);
	byte a_73 = l_26 + Mem18[ix + -0x0014:byte] + (a_67 <u 0x00);
	word16 af_74 = DPB(af_87, a_73, 8);
	word16 hl_85 = DPB(hl_88, a_73, 0);
	fn0CB7(af_74, a_67, a_61, de, hl_85, ix);
}

// 0CB7: void fn0CB7(Register word16 af, Register cu8 b, Register cu8 c, Register Eq_793 de, Register word16 hl, Register (ptr16 Eq_14) ix)
void fn0CB7(word16 af, cu8 b, cu8 c, Eq_793 de, word16 hl, Eq_14 * ix)
{
	ui8 a_18 = b ^ ix->bFFFFFFFD;
	ui8 a_23 = l ^ ix->bFFFFFFFE;
	ui8 a_27 = (bool) C + ((word16) ix->tFFFFFFED + h) ^ ix->bFFFFFFFF;
	Eq_10 a_31 = ix->tFFFFFFDE - (c ^ ix->bFFFFFFFC);
	ix->tFFFFFFDE = a_31;
	Eq_10 a_37 = ix->tFFFFFFDF - a_18 - (a_31 < 0x00);
	ix->tFFFFFFDF = a_37;
	Eq_10 a_43 = ix->tFFFFFFE0 - a_23 - (a_37 < 0x00);
	ix->tFFFFFFE0 = a_43;
	ix->bFFFFFFE1 = ix->bFFFFFFE1 - a_27 - (a_43 < 0x00);
	Eq_10 c_58 = ix->tFFFFFFDE;
	Eq_10 b_60 = ix->tFFFFFFDF;
	ui16 hl_68 = DPB(hl, ix->bFFFFFFE1, 8);
	byte a_71 = 0x04;
	word16 af_72 = DPB(af, 0x04, 8);
	do
	{
		c_58 <<= 0x01;
		b_60 = __rcl(b_60, 0x01, (bool) cond(c_58));
		hl_68 = hl_68 * 0x02 + (b_60 < 0x00);
		--a_71;
		byte h_87 = SLICE(hl_68, byte, 8);
		byte l_88 = (byte) hl_68;
		af_72 = DPB(af_332, a_71, 8);
		word16 af_332 = af_72;
	} while (a_71 != 0x00);
	uint8 a_97 = (byte) c_58.u1 + ix->bFFFFFFEE;
	ix->bFFFFFFFC = a_97;
	uint8 a_103 = (bool) (a_97 < 0x00) + ((word16) b_60 + ix->bFFFFFFEF);
	ix->bFFFFFFFD = a_103;
	uint8 a_109 = (bool) (a_103 < 0x00) + (l_88 + ix->bFFFFFFF0);
	ix->bFFFFFFFE = a_109;
	ix->bFFFFFFFF = (ui8) ((bool) (a_109 < 0x00) + (h_87 + ix->bFFFFFFF1));
	cu8 a_120 = (word16) ix->tFFFFFFDE + ix->bFFFFFFDA;
	cu8 a_127 = (bool) (a_120 < 0x00) + ((word16) ix->tFFFFFFDF + ix->bFFFFFFDB);
	cu8 a_134 = (bool) (a_127 < 0x00) + ((word16) ix->tFFFFFFE0 + ix->bFFFFFFDC);
	byte a_141 = (bool) (a_134 < 0x00) + (ix->bFFFFFFE1 + ix->bFFFFFFDD);
	ix->bFFFFFFFC = ix->bFFFFFFFC ^ a_120;
	ix->bFFFFFFFD = ix->bFFFFFFFD ^ a_127;
	ix->bFFFFFFFE = ix->bFFFFFFFE ^ a_134;
	ix->bFFFFFFFF = ix->bFFFFFFFF ^ a_141;
	Eq_10 c_168 = ix->tFFFFFFDE;
	Eq_10 b_170 = ix->tFFFFFFDF;
	Eq_10 l_173 = ix->tFFFFFFE0;
	uint8 h_175 = ix->bFFFFFFE1;
	byte a_179 = 0x05;
	word16 af_180 = DPB(af_332, 0x05, 8);
	do
	{
		h_175 >>= 0x01;
		l_173 = __rcr(l_173, 0x01, (bool) cond(h_175));
		b_170 = __rcr(b_170, 0x01, (bool) cond(l_173));
		--a_179;
		c_168 = __rcr(c_168, 0x01, (bool) cond(b_170));
		af_180 = DPB(af_333, a_179, 8);
		word16 af_333 = af_180;
	} while (a_179 != 0x00);
	byte a_209 = c_168 + Mem164[ix + -0x0E:byte];
	byte a_215 = b_170 + Mem164[ix + -0x0D:byte] + (a_209 <u 0x00);
	byte a_221 = l_173 + Mem164[ix + -0x0C:byte] + (a_215 <u 0x00);
	ui8 a_235 = a_215 ^ ix->bFFFFFFFD;
	ui8 a_239 = a_221 ^ ix->bFFFFFFFE;
	ui8 a_243 = (word16) ix->tFFFFFFF5 + h_175 + (a_221 < 0x00) ^ ix->bFFFFFFFF;
	Eq_10 a_247 = ix->tFFFFFFE6 - (a_209 ^ ix->bFFFFFFFC);
	ix->tFFFFFFE6 = a_247;
	Eq_10 a_253 = ix->tFFFFFFE7 - a_235 - (a_247 < 0x00);
	ix->tFFFFFFE7 = a_253;
	Eq_10 a_259 = ix->tFFFFFFE8 - a_239 - (a_253 < 0x00);
	ix->tFFFFFFE8 = a_259;
	ix->bFFFFFFE9 = ix->bFFFFFFE9 - a_243 - (a_259 < 0x00);
	cu8 v65_267 = ix->bFFFFFFDA;
	ix->bFFFFFFDA = v65_267 + 0x47;
	cu8 a_275 = (bool) (v65_267 < 0x47) + (ix->bFFFFFFDB + 0x86);
	ix->bFFFFFFDB = a_275;
	cu8 a_281 = (bool) (a_275 < 0x00) + (ix->bFFFFFFDC + 200);
	ix->bFFFFFFDC = a_281;
	ix->bFFFFFFDD = (bool) (a_281 < 0x00) + (ix->bFFFFFFDD + 0x61);
	cu8 v69_289 = ix->bFFFFFFE2;
	cu8 a_297 = (bool) (v69_289 < ~0x00) + (ix->bFFFFFFE3 + ~0x00);
	cu8 a_304 = (bool) (a_297 < 0x00) + (ix->bFFFFFFE4 + ~0x00);
	byte a_310 = (bool) (a_304 < 0x00) + (ix->bFFFFFFE5 + ~0x00);
	ix->bFFFFFFE2 = v69_289 + ~0x00;
	ix->bFFFFFFE3 = a_297;
	ix->bFFFFFFE4 = a_304;
	ix->bFFFFFFE5 = a_310;
	byte a_319 = a_310 | a_304 | a_297 | v69_289 + ~0x00;
	word16 af_320 = DPB(af_333, a_319, 8);
	if (a_319 != 0x00)
		fn060E(af_320, v69_289 + ~0x00, de, ix);
	else
		fn0E13(de, ix);
}

// 0DFC: void fn0DFC(Register word16 af, Register cu8 c, Register cu8 b, Register Eq_793 de, Register byte h, Register cu8 l, Register (ptr16 Eq_14) ix)
void fn0DFC(word16 af, cu8 c, cu8 b, Eq_793 de, byte h, cu8 l, Eq_14 * ix)
{
	ix->bFFFFFFE2 = c;
	ix->bFFFFFFE3 = b;
	ix->bFFFFFFE4 = l;
	ix->bFFFFFFE5 = h;
	byte a_14 = h | l | b | c;
	word16 af_16 = DPB(af, a_14, 8);
	if (a_14 != 0x00)
		fn060E(af_16, c, de, ix);
	else
		fn0E13(de, ix);
}

// 0E13: void fn0E13(Register Eq_793 de, Register (ptr16 Eq_14) ix)
void fn0E13(Eq_793 de, Eq_14 * ix)
{
	Eq_2734 hl_14 = (char *) v3 + 0x0C;
	word16 bc_10;
	for (bc_10 = 0x04; bc_10 != 0x00; --bc_10)
	{
		*de = *hl_14;
		hl_14 = (word32) hl_14 + 0x01;
		++de;
	}
	Eq_2754 de_22 = v3->t0020;
	Eq_2758 hl_24 = (char *) v3 + 0x04;
	word16 bc_27;
	for (bc_27 = 0x04; bc_27 != 0x00; --bc_27)
	{
		*de_22 = *hl_24;
		hl_24 = (word32) hl_24 + 0x01;
		++de_22;
	}
}

// 0F9A: void fn0F9A(Stack word16 wArg00)
void fn0F9A(word16 wArg00)
{
}

// 164F: void fn164F(Register word16 af, Register byte b, Register byte c, Register byte h, Register (ptr16 Eq_14) ix, Stack Eq_12 wArg13, Stack (ptr16 Eq_2784) wArg1B)
void fn164F(word16 af, byte b, byte c, byte h, Eq_14 * ix, Eq_12 wArg13, Eq_2784 * wArg1B)
{
	ix->tFFFFFFEC = a;
	ix->tFFFFFFED = ix->tFFFFFFF9 - h - C;
	byte a_42 = ix->tFFFFFFF9 - ix->bFFFFFFFD - (ix->tFFFFFFF8 - ix->bFFFFFFFC < 0x00);
	Eq_10 a_22 = c - wArg1B->b0000;
	ptr16 hl_48 = DPB(&wArg1B->b0001, a_42, 8);
	Eq_10 a_28 = b - wArg1B->b0001 - (a_22 < 0x00);
	byte l_63 = (byte) hl_48;
	word16 bc_70;
	Eq_793 de_71;
	word16 hl_72;
	struct Eq_14 * ix_73;
	word16 af_74 = fn02F4(DPB(af, a_42, 8), a_28, a_22, wArg13, hl_48, ix, out bc_70, out de_71, out hl_72, out ix_73);
	word16 af_79 = DPB(af_74, l_63, 8);
	if (l_63 != 0x00)
	{
		struct Eq_2851 * v30_103 = fp->ptr0015;
		struct Eq_2856 * v33_110 = fp->ptr0013;
		byte v31_105 = v30_103->b0000;
		byte v32_108 = v30_103->b0001;
		byte v36_115 = v33_110->b0001;
		Eq_10 a_118 = v31_105 - v33_110->b0000;
		ix_73->tFFFFFFEC = a_118;
		ix_73->tFFFFFFED = v32_108 - v36_115 - (a_118 < 0x00);
		struct Eq_2887 * v38_125 = fp->ptr001F;
		struct Eq_2891 * v41_132 = fp->ptr000C;
		cu8 v39_127 = v38_125->b0000;
		byte v40_130 = v38_125->b0001;
		byte v43_137 = v41_132->b0001;
		Eq_10 a_141 = v39_127 - v41_132->b0000;
		ix_73->tFFFFFFEA = a_141;
		ix_73->tFFFFFFEB = v40_130 - v43_137 - (a_141 < 0x00);
		struct Eq_2922 * v44_148 = fp->ptr0019;
		Eq_10 a_157 = v31_105 - v44_148->b0000;
		struct Eq_2931 * v47_165 = fp->ptr0023;
		Eq_10 a_162 = v32_108 - v44_148->b0001 - (a_157 < 0x00);
		byte a_179 = v40_130 - v47_165->b0001 - (v39_127 - v47_165->b0000 < 0x00);
		*(fp - 0x04) = fp->w0011;
		ptr16 v51_189 = fp->ptr000F;
		*(fp - 0x06) = v51_189;
		*(fp - 0x08) = DPB(bc_70, a_162, 8);
		Eq_12 de_184 = DPB(de_71, a_179, 8);
		*(fp - 0x0A) = (union Eq_12 *) de_184;
		word16 af_180 = DPB(af_74, a_179, 8);
		fn16F7(af_180, a_162, a_157, de_184, v51_189, ix_73);
	}
	else
	{
		byte * hl_102 = DPB(hl_72, 0x03, 0);
		fn0C35(af_79, a_22, a_28, de_71, hl_102, ix_73);
	}
}

// 16F7: void fn16F7(Register word16 af, Register Eq_10 b, Register Eq_10 c, Register Eq_12 de, Register ptr16 hl, Register (ptr16 Eq_14) ix)
void fn16F7(word16 af, Eq_10 b, Eq_10 c, Eq_12 de, ptr16 hl, Eq_14 * ix)
{
	word16 bc_8;
	Eq_793 de_9;
	word16 hl_10;
	struct Eq_14 * ix_11;
	word16 af_18 = DPB(fn02F4(af, b, c, de, hl, ix, out bc_8, out de_9, out hl_10, out ix_11), l, 8);
	if (l != 0x00)
	{
		byte * hl_30 = DPB(hl_10, 0x00, 0);
		fn0C35(af_18, c, b, de_9, hl_30, ix_11);
	}
	else
	{
		byte * hl_28 = DPB(hl_10, 0x03, 0);
		fn0C35(af_18, c, b, de_9, hl_28, ix_11);
	}
}

// 1873: void fn1873(Register word16 af, Register Eq_10 b, Register Eq_10 c, Register Eq_793 de, Register byte h, Register (ptr16 Eq_14) ix, Stack (ptr16 Eq_3032) wArg13)
void fn1873(word16 af, Eq_10 b, Eq_10 c, Eq_793 de, byte h, Eq_14 * ix, Eq_3032 * wArg13)
{
	wArg13->t0000 = c;
	wArg13->t0001 = b;
	byte * hl_13 = DPB(&wArg13->t0001, 0x02, 0);
	fn0C35(af, c, b, de, hl_13, ix);
}

// 1929: void fn1929(Register word16 af, Register Eq_10 b, Register Eq_10 c, Register word16 de, Register (ptr16 Eq_14) ix, Stack ptr16 wArg11, Stack word16 wArg13)
void fn1929(word16 af, Eq_10 b, Eq_10 c, word16 de, Eq_14 * ix, ptr16 wArg11, word16 wArg13)
{
	byte a_13 = d - a - (e - a < 0x00);
	word16 bc_40;
	word16 de_41;
	word16 hl_42;
	struct Eq_3064 * ix_43;
	fn02F4(DPB(af, a_13, 8), b, c, DPB(de, a_13, 8), wArg11, ix, out bc_40, out de_41, out hl_42, out ix_43);
	byte l_29 = (byte) wArg11;
	byte v17_48 = ix_43->bFFFFFFD9;
	if (v17_48 == 0x00 && (v17_48 | l_29) == 0x00)
	{
		if (ix_43->bFFFFFFD9 == 0x00 || l_29 == 0x00)
			;
	}
}

// 1BA4: void fn1BA4(Register byte a, Register word16 bc, Register word16 de, Register ui16 hl, Register (ptr16 Eq_3095) ix, Stack word16 wArg00, Stack word16 wArg10, Stack word16 wArg1D, Stack word16 wArg1F)
void fn1BA4(byte a, word16 bc, word16 de, ui16 hl, Eq_3095 * ix, word16 wArg00, word16 wArg10, word16 wArg1D, word16 wArg1F)
{
	fn0805(a);
	byte l_37 = (byte) wArg1D;
	ui16 hl_16 = hl * 0x08 + DPB(de, h, 8) + bc;
	Eq_3112 de_43 = DPB(wArg00, l_37, 0);
	cu8 a_45 = 0x03 - l_37;
	if (a_45 < 0x00)
		fn1BF9(bc, de_43, ix);
	else
	{
		switch (a_45)
		{
		case 0x00:
			fn0000(a_45, hl_16);
			return;
		}
	}
}

// 1BDE: void fn1BDE(Register word16 bc, Register Eq_3112 de, Register (ptr16 Eq_3095) ix)
void fn1BDE(word16 bc, Eq_3112 de, Eq_3095 * ix)
{
	++ix->bFFFFFFE9;
	ix->bFFFFFFFF = ix->bFFFFFFE9;
	fn1BF9(bc, de, ix);
}

// 1BF9: void fn1BF9(Register word16 bc, Register Eq_3112 de, Register (ptr16 Eq_3095) ix)
void fn1BF9(word16 bc, Eq_3112 de, Eq_3095 * ix)
{
	cu8 v4_4 = ix->bFFFFFFF7;
	ix->bFFFFFFF7 = v4_4 + 0x09;
	ix->bFFFFFFF8 = (bool) (v4_4 < 0x09) + ix->bFFFFFFF8;
	++ix->bFFFFFFF5;
	word16 bc_23;
	Eq_3178 hl_26 = 0x0823;
	do
	{
		*de = *hl_26;
		++hl_26;
		de = (word32) de + 0x01;
		--bc_23;
	} while (bc_23 != 0x00);
}

// 1C54: void fn1C54()
void fn1C54()
{
}

// 1C89: void fn1C89(Register byte a, Register byte c, Stack word16 wArg00)
void fn1C89(byte a, byte c, word16 wArg00)
{
}

// 22A6: void fn22A6(Register word16 bc, Register (ptr16 Eq_3201) ix, Stack word16 wArg03, Stack word16 wArg05, Stack (ptr16 Eq_3204) wArg07, Stack ptr16 wArg0D, Stack word16 wArg10)
void fn22A6(word16 bc, Eq_3201 * ix, word16 wArg03, word16 wArg05, Eq_3204 * wArg07, ptr16 wArg0D, word16 wArg10)
{
	ix->bFFFFFFFC = ix->bFFFFFFF7;
	ix->bFFFFFFFD = 0x00;
	struct Eq_3217 * hl_34 = DPB(wArg10 + (wArg05 + 0x01), 0x00, 8) * 0x08 + DPB(wArg05 + 0x01, 0x00, 8) + bc;
	ix->bFFFFFFF8 = hl_34->b0002;
	ix->bFFFFFFF9 = hl_34->b0003;
	struct Eq_3242 * hl_105 = DPB(wArg10 + (wArg05 + 0x03), 0x00, 8) * 0x08 + DPB(wArg05 + 0x03, 0x00, 8) + DPB(bc, (wArg0D + DPB(bc, SLICE(DPB(wArg10 + (wArg05 + 0x02), 0x00, 8) * 0x02 + DPB(bc, 0x00, 8), byte, 8), 8))->b0001, 8);
	byte v49_136 = hl_105->b0000;
	byte v50_139 = hl_105->b0001;
	fn03AA();
	wArg07->b0000 = v49_136;
	wArg07->b0001 = v50_139;
	++ix->bFFFFFFF7;
	++ix->bFFFFFFF7;
	++ix->bFFFFFFF7;
	++ix->bFFFFFFF7;
	wArg07->b0002 = v50_139;
}

// 291C: void fn291C(Register byte a, Register ptr16 hl)
void fn291C(byte a, ptr16 hl)
{
	Eq_10 a_13 = 0x00 - (__ror(*(hl - 0x01), 0x01) < 0x00);
	byte a_20 = 0x00 - (__ror(a, 0x01) < 0x00);
	__rcl(a_13, 0x01, (bool) cond((a_13 ^ a_20) << 0x01)) >= 0x00;
	fn1C54();
}

// 384A: void fn384A(Register word16 ix)
void fn384A(word16 ix)
{
}

// 3E2D: void fn3E2D(Register word16 bc, Register (ptr16 Eq_3369) ix, Stack word16 wArg03, Stack word16 wArg05, Stack ptr16 wArg0D, Stack word16 wArg10)
void fn3E2D(word16 bc, Eq_3369 * ix, word16 wArg03, word16 wArg05, ptr16 wArg0D, word16 wArg10)
{
	ix->bFFFFFFFC = ix->bFFFFFFF7;
	ix->bFFFFFFFD = 0x00;
	struct Eq_3384 * hl_34 = DPB(wArg10 + (wArg05 + 0x01), 0x00, 8) * 0x08 + DPB(wArg05 + 0x01, 0x00, 8) + bc;
	ix->bFFFFFFF8 = hl_34->b0002;
	ix->bFFFFFFF9 = hl_34->b0003;
	struct Eq_3409 * hl_105 = DPB(wArg10 + (wArg05 + 0x03), 0x00, 8) * 0x08 + DPB(wArg05 + 0x03, 0x00, 8) + DPB(bc, (wArg0D + DPB(bc, SLICE(DPB(wArg10 + (wArg05 + 0x02), 0x00, 8) * 0x02 + DPB(bc, 0x00, 8), byte, 8), 8))->b0001, 8);
	byte v41_114 = hl_105->b0003;
	byte v43_124 = ix->bFFFFFFF9;
	fn3EC2(v43_124, v41_114, ix, wArg01, hl_34, hl_105);
}

// 3EC2: void fn3EC2(Register byte a, Register byte b, Register (ptr16 Eq_3369) ix, Stack word16 wArg03, Stack (ptr16 Eq_3384) wArg05, Stack (ptr16 Eq_3409) wArg07)
void fn3EC2(byte a, byte b, Eq_3369 * ix, word16 wArg03, Eq_3384 * wArg05, Eq_3409 * wArg07)
{
	byte v16_21 = wArg05->b0000;
	byte v17_24 = wArg05->b0001;
	fn03AA();
	wArg07->b0000 = v16_21;
	wArg07->b0001 = v17_24;
	++ix->bFFFFFFF7;
	++ix->bFFFFFFF7;
	++ix->bFFFFFFF7;
	++ix->bFFFFFFF7;
	wArg07->b0002 = v17_24;
}

// 59FE: void fn59FE(Register word16 af, Register word16 bc, Register Eq_12 de, Register byte h, Register byte l, Register (ptr16 Eq_14) ix, Stack word16 wArg0A, Stack word16 wArg10)
void fn59FE(word16 af, word16 bc, Eq_12 de, byte h, byte l, Eq_14 * ix, word16 wArg0A, word16 wArg10)
{
	word16 af_187;
	Eq_10 a_186;
	Eq_3518 C_191;
	fn0BFE();
	byte l_19 = (byte) wArg0A;
	byte h_20 = SLICE(wArg0A, byte, 8);
	Eq_10 c_27 = (byte) bc;
	byte b_28 = SLICE(bc, byte, 8);
	byte a_42 = ix->bFFFFFFFF - ix->b0005 - (ix->bFFFFFFFE - ix->b0004 < 0x00);
	if (OVERFLOW(a_42))
	{
		a_186 = a_42 ^ 0x80;
		af_187 = DPB(af, a_42 ^ 0x80, 8);
		C_191.u0 = false;
		if ((a_42 ^ 0x80) < 0x00)
		{
			fn0B2C(af_187, c_27, de, ix);
			return;
		}
	}
	else
	{
		Eq_10 a_201 = (word16) c_27 + a_42;
		ix->tFFFFFFF6 = a_201;
		a_186 = (bool) (a_201 < 0x00) + ((word16) ix->tFFFFFFF7 + b_28);
		af_187 = DPB(af, a_186, 8);
		C_191.u0 = (bool) cond(a_186);
	}
	ix->tFFFFFFF7 = a_186;
	Eq_10 a_82 = (bool) C_191.u0 + ((word16) ix->tFFFFFFF8 + l_19);
	ix->tFFFFFFF8 = a_82;
	Eq_10 a_88 = (bool) (a_82 < 0x00) + ((word16) ix->tFFFFFFF9 + h_20);
	ix->tFFFFFFF9 = a_88;
	*(fp - 0x02) = DPB(af_187, a_88, 8);
	Eq_10 c_109 = ix->tFFFFFFF6;
	Eq_10 b_110 = ix->tFFFFFFF7;
	ui16 hl_104 = DPB(wArg0A, ix->tFFFFFFF9, 8);
	byte a_107 = 0x04;
	word16 af_108 = DPB(Mem94[fp - 0x02 + 0x00:word16], 0x04, 8);
	do
	{
		c_109 <<= 0x01;
		b_110 = __rcl(b_110, 0x01, (bool) cond(c_109));
		hl_104 = hl_104 * 0x02 + (b_110 < 0x00);
		--a_107;
		byte l_123 = (byte) hl_104;
		byte h_124 = SLICE(hl_104, byte, 8);
		af_108 = DPB(af_220, a_107, 8);
		word16 af_220 = af_108;
	} while (a_107 != 0x00);
	byte a_133 = c_109 + Mem94[ix + -0x0022:byte];
	ix->bFFFFFFFA = a_133;
	byte a_139 = b_110 + Mem136[ix + -33:byte] + (a_133 <u 0x00);
	ix->bFFFFFFFB = a_139;
	uint8 a_145 = (bool) (a_139 < 0x00) + ((word16) ix->tFFFFFFE0 + l_123);
	ix->bFFFFFFFC = a_145;
	ix->bFFFFFFFD = (uint8) ((bool) (a_145 < 0x00) + (h_124 + ix->bFFFFFFE1));
	cu8 a_156 = (word16) ix->tFFFFFFF6 + ix->bFFFFFFEE;
	cu8 a_163 = (bool) (a_156 < 0x00) + ((word16) ix->tFFFFFFF7 + ix->bFFFFFFEF);
	Eq_10 a_171 = (bool) (a_163 < 0x00) + ((word16) ix->tFFFFFFF8 + ix->bFFFFFFF0);
	byte a_178 = (bool) (a_171 < 0x00) + ((word16) ix->tFFFFFFF9 + ix->bFFFFFFF1);
	word16 af_185 = DPB(af_220, ix->bFFFFFFFA, 8);
	fn0AA6(af_185, a_163, a_156, de, a_178, a_171, ix);
}

// 5A49: void fn5A49(Register word16 af, Register word16 bc, Register word16 de, Register word16 hl, Register (ptr16 Eq_14) ix, Stack word16 wArg00, Stack (ptr16 Eq_3747) wArg02, Stack (ptr16 Eq_3748) wArg06, Stack word16 wArg08)
void fn5A49(word16 af, word16 bc, word16 de, word16 hl, Eq_14 * ix, word16 wArg00, Eq_3747 * wArg02, Eq_3748 * wArg06, word16 wArg08)
{
	Eq_12 hl_12 = DPB(hl, (bool) C + (ix->bFFFFFFFD + 0x80), 8) + de;
	byte d_16 = SLICE(hl_12, byte, 8);
	struct Eq_3762 * hl_20 = DPB(de, d_16, 8);
	Eq_10 v16_21 = hl_20->t0000;
	byte v18_24 = hl_20->b0001;
	byte a_30 = v18_24 | v16_21;
	struct Eq_3774 * hl_27 = DPB(&hl_20->b0001, v16_21, 0);
	word16 af_32 = DPB(af, a_30, 8);
	if (a_30 == 0x00)
		fn0AA6(af_32, b, c, hl_12, v18_24, v16_21, ix);
	else
	{
		ix->tFFFFFFF8 = hl_27->t0002;
		ix->tFFFFFFF9 = hl_27->t0003;
		uint8 v26_73 = ix->bFFFFFFFC;
		ix->tFFFFFFF6 = v26_73 + 0x04;
		ix->tFFFFFFF7 = (bool) (v26_73 < 0x04) + ix->bFFFFFFFD;
		byte a_92 = ix->bFFFFFFFF - ix->tFFFFFFF9 - (ix->bFFFFFFFE - ix->tFFFFFFF8 < 0x00);
		word16 af_93 = DPB(af, a_92, 8);
		if (!OVERFLOW(a_92))
			fn0AA6(af_93, b, c, hl_12, v18_24, v16_21, ix);
		else
		{
			word16 af_98 = DPB(af, a_92 ^ 0x80, 8);
			if ((a_92 ^ 0x80) >= 0x00)
				fn0AA6(af_98, b, c, hl_12, v18_24, v16_21, ix);
			else
			{
				ix->tFFFFFFF4 = hl_27->b0000;
				ix->tFFFFFFF5 = hl_27->t0001;
				cu8 c_116 = (byte) (bc - 0x01);
				wArg06->b0000 = c_116;
				cu8 b_117 = SLICE(bc - 0x01, byte, 8);
				wArg06->b0001 = b_117;
				Eq_10 v41_124 = hl_27->t0002;
				Eq_10 l_128 = (byte) (v41_124 - 0x01);
				hl_27->t0002 = l_128;
				byte h_127 = SLICE(v41_124 - 0x01, byte, 8);
				ix->b0001 = h_127;
				byte a_133 = 0x00 - h_127;
				word16 af_134 = DPB(af, a_133, 8);
				if (!OVERFLOW(a_133))
					fn0AA6(af_134, b_117, c_116, hl_12, h_127, l_128, ix);
				else
				{
					word16 af_139 = DPB(af, a_133 ^ 0x80, 8);
					if ((a_133 ^ 0x80) < 0x00)
						fn0AA6(af_139, b_117, c_116, hl_12, h_127, l_128, ix);
					else
					{
						word16 bc_154 = DPB(bc - 0x01, wArg02->b0001, 8);
						fn02C2(*DPB(&wArg02->b0001, d_16, 8));
						*hl_12 = (byte) bc_154;
						*((word32) hl_12 + 0x01) = SLICE(bc_154, byte, 8);
					}
				}
			}
		}
	}
}

