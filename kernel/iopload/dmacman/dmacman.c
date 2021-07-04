//[module]	DMACMAN
//[processor]	IOP
//[type]	ELF-IRX
//[name]	dmacman
//[version]	0x101
//[memory map]	0xBF801080,0xBF801084,0xBF801088,		00 mdec in
//		0xBF801090,0xBF801094,0xBF801098,		01 mdec out
//		0xBF8010A0,0xBF8010A4,0xBF8010A8,		02 gpu
//		0xBF8010B0,0xBF8010B4,0xBF8010B8,		03 cdrom/dvd
//		0xBF8010C0,0xBF8010C4,0xBF8010C8, 0xBF8010CC,	04 spu
//		0xBF8010D0,0xBF8010D4,0xBF8010D8,		05 pio
//		0xBF8010E0,0xBF8010E4,0xBF8010E8,		06 gpu otc
//
//		0xBF8010F0,0xBF8010F4,
//
//		0xBF801500,0xBF801504,0xBF801508,		07 SPU2
//		0xBF801510,0xBF801514,0xBF801518,		08
//		0xBF801520,0xBF801524,0xBF801528, 0xBF80152C,	09 SIF0
//		0xBF801530,0xBF801534,0xBF801538,		10 SIF1
//		0xBF801540,0xBF801544,0xBF801548,		11 SIO2in
//		0xBF801550,0xBF801554,0xBF801558,		12 SIO2out
//
//		0xBF801560,0xBF801564,0xBF801568,		   //sifman
//                    sif0	sif1	   spu
//
//		0xBF801570, 0xBF801574,0xBF801578,0xBF80157C,	   //sifman
//		0xBF8015F0
//[handlers]	-
//[entry point]	dmacman_start, dmacman_stub
//[made by]	[RO]man (roman_ps2dev@hotmail.com)

#include <tamtypes.h>

#include "kloadcore.h"
#include "kintrman.h"
#include "kdmacman.h"


int _start(int argc, char* argv[]);

///////////////////////////////////////////////////////////////////////
void _setBF801080(unsigned int ch, int value)
{
	*(int*)0xBF801080 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801090(unsigned int ch, int value)
{
	*(int*)0xBF801090 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010A0(unsigned int ch, int value)
{
	*(int*)0xBF8010A0 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010B0(unsigned int ch, int value)
{
	*(int*)0xBF8010B0 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010C0(unsigned int ch, int value)
{
	*(int*)0xBF8010C0 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010D0(unsigned int ch, int value)
{
	*(int*)0xBF8010D0 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010E0(unsigned int ch, int value)
{
	*(int*)0xBF8010E0 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801500(unsigned int ch, int value)
{
	*(int*)0xBF801500 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801510(unsigned int ch, int value)
{
	*(int*)0xBF801510 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801520(unsigned int ch, int value)
{
	*(int*)0xBF801520 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801530(unsigned int ch, int value)
{
	*(int*)0xBF801530 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801540(unsigned int ch, int value)
{
	*(int*)0xBF801540 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801550(unsigned int ch, int value)
{
	*(int*)0xBF801550 = value;
}

///////////////////////////////////////////////////////////////////////
int _getBF801080(unsigned int ch)
{
	return *(int*)0xBF801080;
}

///////////////////////////////////////////////////////////////////////
int _getBF801090(unsigned int ch)
{
	return *(int*)0xBF801090;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010A0(unsigned int ch)
{
	return *(int*)0xBF8010A0;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010B0(unsigned int ch)
{
	return *(int*)0xBF8010B0;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010C0(unsigned int ch)
{
	return *(int*)0xBF8010C0;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010D0(unsigned int ch)
{
	return *(int*)0xBF8010D0;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010E0(unsigned int ch)
{
	return *(int*)0xBF8010E0;
}

///////////////////////////////////////////////////////////////////////
int _getBF801500(unsigned int ch)
{
	return *(int*)0xBF801500;
}

///////////////////////////////////////////////////////////////////////
int _getBF801510(unsigned int ch)
{
	return *(int*)0xBF801510;
}

///////////////////////////////////////////////////////////////////////
int _getBF801520(unsigned int ch)
{
	return *(int*)0xBF801520;
}

///////////////////////////////////////////////////////////////////////
int _getBF801530(unsigned int ch)
{
	return *(int*)0xBF801530;
}

///////////////////////////////////////////////////////////////////////
int _getBF801540(unsigned int ch)
{
	return *(int*)0xBF801540;
}

///////////////////////////////////////////////////////////////////////
int _getBF801550(unsigned int ch)
{
	return *(int*)0xBF801550;
}

///////////////////////////////////////////////////////////////////////
void _setBF801084(unsigned int ch, int value)
{
	*(int*)0xBF801084 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801094(unsigned int ch, int value)
{
	*(int*)0xBF801094 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010A4(unsigned int ch, int value)
{
	*(int*)0xBF8010A4 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010B4(unsigned int ch, int value)
{
	*(int*)0xBF8010B4 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010C4(unsigned int ch, int value)
{
	*(int*)0xBF8010C4 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010D4(unsigned int ch, int value)
{
	*(int*)0xBF8010D4 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010E4(unsigned int ch, int value)
{
	*(int*)0xBF8010E4 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801504(unsigned int ch, int value)
{
	*(int*)0xBF801504 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801514(unsigned int ch, int value)
{
	*(int*)0xBF801514 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801524(unsigned int ch, int value)
{
	*(int*)0xBF801524 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801534(unsigned int ch, int value)
{
	*(int*)0xBF801534 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801544(unsigned int ch, int value)
{
	*(int*)0xBF801544 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801554(unsigned int ch, int value)
{
	*(int*)0xBF801554 = value;
}

///////////////////////////////////////////////////////////////////////
int _getBF801084(unsigned int ch)
{
	return *(int*)0xBF801084;
}

///////////////////////////////////////////////////////////////////////
int _getBF801094(unsigned int ch)
{
	return *(int*)0xBF801094;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010A4(unsigned int ch)
{
	return *(int*)0xBF8010A4;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010B4(unsigned int ch)
{
	return *(int*)0xBF8010B4;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010C4(unsigned int ch)
{
	return *(int*)0xBF8010C4;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010D4(unsigned int ch)
{
	return *(int*)0xBF8010D4;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010E4(unsigned int ch)
{
	return *(int*)0xBF8010E4;
}

///////////////////////////////////////////////////////////////////////
int _getBF801504(unsigned int ch)
{
	return *(int*)0xBF801504;
}

///////////////////////////////////////////////////////////////////////
int _getBF801514(unsigned int ch)
{
	return *(int*)0xBF801514;
}

///////////////////////////////////////////////////////////////////////
int _getBF801524(unsigned int ch)
{
	return *(int*)0xBF801524;
}

///////////////////////////////////////////////////////////////////////
int _getBF801534(unsigned int ch)
{
	return *(int*)0xBF801534;
}

///////////////////////////////////////////////////////////////////////
int _getBF801544(unsigned int ch)
{
	return *(int*)0xBF801544;
}

///////////////////////////////////////////////////////////////////////
int _getBF801554(unsigned int ch)
{
	return *(int*)0xBF801554;
}

///////////////////////////////////////////////////////////////////////
void _setBF801088(unsigned int ch, int value)
{
	*(int*)0xBF801088 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801098(unsigned int ch, int value)
{
	*(int*)0xBF801098 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010A8(unsigned int ch, int value)
{
	*(int*)0xBF8010A8 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010B8(unsigned int ch, int value)
{
	*(int*)0xBF8010B8 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010C8(unsigned int ch, int value)
{
	*(int*)0xBF8010C8 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010D8(unsigned int ch, int value)
{
	*(int*)0xBF8010D8 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF8010E8(unsigned int ch, int value)
{
	*(int*)0xBF8010E8 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801508(unsigned int ch, int value)
{
	*(int*)0xBF801508 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801518(unsigned int ch, int value)
{
	*(int*)0xBF801518 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801528(unsigned int ch, int value)
{
	*(int*)0xBF801528 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801538(unsigned int ch, int value)
{
	*(int*)0xBF801538 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801548(unsigned int ch, int value)
{
	*(int*)0xBF801548 = value;
}

///////////////////////////////////////////////////////////////////////
void _setBF801558(unsigned int ch, int value)
{
	*(int*)0xBF801558 = value;
}

///////////////////////////////////////////////////////////////////////
int _getBF801088(unsigned int ch)
{
	return *(int*)0xBF801088;
}

///////////////////////////////////////////////////////////////////////
int _getBF801098(unsigned int ch)
{
	return *(int*)0xBF801098;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010A8(unsigned int ch)
{
	return *(int*)0xBF8010A8;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010B8(unsigned int ch)
{
	return *(int*)0xBF8010B8;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010C8(unsigned int ch)
{
	return *(int*)0xBF8010C8;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010D8(unsigned int ch)
{
	return *(int*)0xBF8010D8;
}

///////////////////////////////////////////////////////////////////////
int _getBF8010E8(unsigned int ch)
{
	return *(int*)0xBF8010E8;
}

///////////////////////////////////////////////////////////////////////
int _getBF801508(unsigned int ch)
{
	return *(int*)0xBF801508;
}

///////////////////////////////////////////////////////////////////////
int _getBF801518(unsigned int ch)
{
	return *(int*)0xBF801518;
}

///////////////////////////////////////////////////////////////////////
int _getBF801528(unsigned int ch)
{
	return *(int*)0xBF801528;
}

///////////////////////////////////////////////////////////////////////
int _getBF801538(unsigned int ch)
{
	return *(int*)0xBF801538;
}

///////////////////////////////////////////////////////////////////////
int _getBF801548(unsigned int ch)
{
	return *(int*)0xBF801548;
}

///////////////////////////////////////////////////////////////////////
int _getBF801558(unsigned int ch)
{
	return *(int*)0xBF801558;
}

///////////////////////////////////////////////////////////////////////
void dmac_ch_set_tadr(unsigned int ch, int value)
{
	if (ch == DMAch_SPU)
		*(int*)0xBF8010CC = value;
	else if (ch == DMAch_SIF0)
		*(int*)0xBF80152C = value;
}

///////////////////////////////////////////////////////////////////////
int dmac_ch_get_tadr(unsigned int ch)
{
	if (ch == DMAch_SPU)
		return *(int*)0xBF8010CC;
	if (ch == DMAch_SIF0)
		return *(int*)0xBF80152C;
	return 0;
}

///////////////////////////////////////////////////////////////////////
void dmac_set_4_9_a(u32 ch, u32 value)
{
	if (ch == DMAch_SPU)
		*(int*)0xBF801568 = value;
	else if (ch == DMAch_SIF0)
		*(int*)0xBF801560 = value;
	else if (ch == DMAch_SIF1)
		*(int*)0xBF801564 = value;
}

///////////////////////////////////////////////////////////////////////
u32 dmac_get_4_9_a(u32 ch)
{
	if (ch == DMAch_SPU)
		return *(int*)0xBF801568;
	if (ch == DMAch_SIF0)
		return *(int*)0xBF801560;
	if (ch == DMAch_SIF1)
		return *(int*)0xBF801564;
	return 0;
}

///////////////////////////////////////////////////////////////////////
void dmac_set_dpcr(int value)
{
	*(int*)0xBF8010F0 = value;
}

///////////////////////////////////////////////////////////////////////
int dmac_get_dpcr()
{
	return *(int*)0xBF8010F0;
}

///////////////////////////////////////////////////////////////////////
void dmac_set_dpcr2(int value)
{
	*(int*)0xBF801570 = value;
}

///////////////////////////////////////////////////////////////////////
int dmac_get_dpcr2()
{
	return *(int*)0xBF801570;
}

///////////////////////////////////////////////////////////////////////
void dmac_set_dpcr3(int value)
{
	*(int*)0xBF8015F0 = value;
}

///////////////////////////////////////////////////////////////////////
int dmac_get_dpcr3()
{
	return *(int*)0xBF8015F0;
}

///////////////////////////////////////////////////////////////////////
void dmac_set_dicr(int value)
{
	*(int*)0xBF8010F4 = value;
}

///////////////////////////////////////////////////////////////////////
int dmac_get_dicr()
{
	return *(int*)0xBF8010F4;
}

///////////////////////////////////////////////////////////////////////
void dmac_set_dicr2(int value)
{
	*(int*)0xBF801574 = value;
}

///////////////////////////////////////////////////////////////////////
int dmac_get_dicr2()
{
	return *(int*)0xBF801574;
}

///////////////////////////////////////////////////////////////////////
void dmac_set_BF80157C(int value)
{
	*(int*)0xBF80157C = value;
}

///////////////////////////////////////////////////////////////////////
int dmac_get_BF80157C()
{
	return *(int*)0xBF80157C;
}

///////////////////////////////////////////////////////////////////////
void dmac_set_BF801578(int value)
{
	*(int*)0xBF801578 = value;
}

///////////////////////////////////////////////////////////////////////
int dmac_get_BF801578()
{
	return *(int*)0xBF801578;
}

func setD_MADR[] = {
	(func)_setBF801080, (func)_setBF801090, (func)_setBF8010A0, (func)_setBF8010B0,
	(func)_setBF8010C0, (func)_setBF8010D0, (func)_setBF8010E0,
	(func)_setBF801500, (func)_setBF801510, (func)_setBF801520,
	(func)_setBF801530, (func)_setBF801540, (func)_setBF801550, 0};

func getD_MADR[] = {
	(func)_getBF801080, (func)_getBF801090, (func)_getBF8010A0, (func)_getBF8010B0,
	(func)_getBF8010C0, (func)_getBF8010D0, (func)_getBF8010E0,
	(func)_getBF801500, (func)_getBF801510, (func)_getBF801520,
	(func)_getBF801530, (func)_getBF801540, (func)_getBF801550, 0};

func setD_BCR[] = {
	(func)_setBF801084, (func)_setBF801094, (func)_setBF8010A4, (func)_setBF8010B4,
	(func)_setBF8010C4, (func)_setBF8010D4, (func)_setBF8010E4,
	(func)_setBF801504, (func)_setBF801514, (func)_setBF801524,
	(func)_setBF801534, (func)_setBF801544, (func)_setBF801554, 0};

func getD_BCR[] = {
	(func)_getBF801084, (func)_getBF801094, (func)_getBF8010A4, (func)_getBF8010B4,
	(func)_getBF8010C4, (func)_getBF8010D4, (func)_getBF8010E4,
	(func)_getBF801504, (func)_getBF801514, (func)_getBF801524,
	(func)_getBF801534, (func)_getBF801544, (func)_getBF801554, 0};

func setD_CHCR[] = {
	(func)_setBF801088, (func)_setBF801098, (func)_setBF8010A8, (func)_setBF8010B8,
	(func)_setBF8010C8, (func)_setBF8010D8, (func)_setBF8010E8,
	(func)_setBF801508, (func)_setBF801518, (func)_setBF801528,
	(func)_setBF801538, (func)_setBF801548, (func)_setBF801558, 0};

func getD_CHCR[] = {
	(func)_getBF801088, (func)_getBF801098, (func)_getBF8010A8, (func)_getBF8010B8,
	(func)_getBF8010C8, (func)_getBF8010D8, (func)_getBF8010E8,
	(func)_getBF801508, (func)_getBF801518, (func)_getBF801528,
	(func)_getBF801538, (func)_getBF801548, (func)_getBF801558, 0};

///////////////////////////////////////////////////////////////////////
void dmac_ch_set_madr(unsigned int ch, int value)
{
	if (ch < 13)
		setD_MADR[ch](ch, value); //function call
}

///////////////////////////////////////////////////////////////////////
int dmac_ch_get_madr(unsigned int ch)
{
	if (ch < 13)
		return getD_MADR[ch](ch); //function call
	return 0;
}

///////////////////////////////////////////////////////////////////////
void dmac_ch_set_bcr(unsigned int ch, int value)
{
	if (ch < 13)
		setD_BCR[ch](ch, value); //function call
}

///////////////////////////////////////////////////////////////////////
int dmac_ch_get_bcr(unsigned int ch)
{
	if (ch < 13)
		return getD_BCR[ch](ch); //function call
	return 0;
}

///////////////////////////////////////////////////////////////////////
void dmac_ch_set_chcr(unsigned int ch, int value)
{
	if (ch < 13)
		setD_CHCR[ch](ch, value); //function call
}

///////////////////////////////////////////////////////////////////////
int dmac_ch_get_chcr(unsigned int ch)
{
	if (ch < 13)
		return getD_CHCR[ch](ch); //function call
	return 0;
}



///////////////////////////////////////////////////////////////////////
int dmacDeinit()
{
	int x;
	register int ch, value;

	CpuSuspendIntr(&x); //intrman

	dmac_set_BF801578(0);
	for (ch = 0; ch < 13; ch++)
	{
		value = dmac_ch_get_chcr(ch);
		if (value & DMAf_TR) //sysmem
			Kprintf("WARNING:DMA %dch has been continued until shutdown\n", ch);
		dmac_ch_set_chcr(ch, value & 0xFEFFFFFF);
	}

	CpuResumeIntr(x); //intrman
	return 1;
}

///////////////////////////////////////////////////////////////////////
int dmac_request(int ch, int address, int size, int count, int dir)
{
	if (ch < 13 && ch != DMAch_GPUotc)
	{
		dmac_ch_set_madr(ch, 0x00FFFFFF & address);
		dmac_ch_set_bcr(ch, (count << 16) | (size & 0xFFFF));
		dmac_ch_set_chcr(ch, (dir & DMAf_DR) | DMAf_CO |
							  (dir == 0 ? DMAf_30 : 0));
		return 1;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////
int dmac_set_dma_chained_spu_sif0(int ch, int size, int tadr)
{
	if (ch != DMAch_SPU && ch != DMAch_SIF0)
		return 0;
	dmac_ch_set_bcr(ch, size & 0x0000FFFF);
	dmac_ch_set_chcr(ch, DMAf_LI | DMAf_CO | DMAf_DR); //0x601
	dmac_ch_set_tadr(ch, tadr & 0x00FFFFFF);
	return 1;
}

///////////////////////////////////////////////////////////////////////
int dmac_set_dma_sif0(int ch, int size, int tadr)
{
	if (ch != DMAch_SIF0)
		return 0;
	dmac_ch_set_bcr(DMAch_SIF0, size & 0x0000FFFF);
	dmac_ch_set_chcr(DMAch_SIF0, DMAf_LI | DMAf_CO | DMAf_08 | DMAf_DR); //0x701
	dmac_ch_set_tadr(DMAch_SIF0, tadr & 0x00FFFFFF);
	return 1;
}

///////////////////////////////////////////////////////////////////////
int dmac_set_dma_sif1(int ch, int size)
{
	if (ch != DMAch_SIF1)
		return 0;
	dmac_ch_set_bcr(DMAch_SIF1, size & 0x0000FFFF);
	dmac_ch_set_chcr(DMAch_SIF1, DMAf_30 | DMAf_CO | DMAf_08); //0x40000300
	return 1;
}

///////////////////////////////////////////////////////////////////////
void dmac_transfer(int ch)
{
	if (ch < 15)
		dmac_ch_set_chcr(ch, DMAf_TR | dmac_ch_get_chcr(ch));
}

///////////////////////////////////////////////////////////////////////
// set 3-bit value of channel
void dmac_ch_set_dpcr(int ch, int value)
{
	int x;
	CpuSuspendIntr(&x); //intrman

	switch (ch)
	{
		case DMAch_MDECin:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0xFFFFFFF8) |
				(value & 7));
			break;
		case DMAch_MDECout:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0xFFFFFF8F) |
				((value & 7) << 4));
			break;
		case DMAch_GPU:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0xFFFFF8FF) |
				((value & 7) << 8));
			break;
		case DMAch_CD:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0xFFFF8FFF) |
				((value & 7) << 12));
			break;
		case DMAch_SPU:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0xFFF8FFFF) |
				((value & 7) << 16));
			break;
		case DMAch_PIO:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0xFF8FFFFF) |
				((value & 7) << 20));
			break;
		case DMAch_GPUotc:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0xF8FFFFFF) |
				((value & 7) << 24));
			break;
		case DMAch_SPU2:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() & 0xFFFFFFF8) |
				(value & 7));
			break;
		case DMAch_8:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() & 0xFFFFFF8F) |
				((value & 7) << 4));
			break;
		case DMAch_SIF0:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() & 0xFFFFF8FF) |
				((value & 7) << 8));
			break;
		case DMAch_SIF1:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() & 0xFFFF8FFF) |
				((value & 7) << 12));
			break;
		case DMAch_SIO2in:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() & 0xFFF8FFFF) |
				((value & 7) << 16));
			break;
		case DMAch_SIO2out:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() & 0xFF8FFFFF) |
				((value & 7) << 20));
			break;
		case DMAch_13:
			dmac_set_dpcr3(
				(dmac_get_dpcr3() & 0xFFFFFFF8) |
				(value & 7));
			break;
		case DMAch_14:
			dmac_set_dpcr3(
				(dmac_get_dpcr3() & 0xFFFFFF8F) |
				((value & 7) << 4));
			break;
		case DMAch_15:
			dmac_set_dpcr3(
				(dmac_get_dpcr3() & 0xFFFFF8FF) |
				((value & 7) << 8));
			break;
		case DMAch_67:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0x8FFFFFFF) |
				((value & 7) << 28));
			break;
		case DMAch_85:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() & 0xF8FFFFFF) |
				((value & 7) << 24));
			break;
	}

	CpuResumeIntr(x); //intrman
}

///////////////////////////////////////////////////////////////////////
// set 4th bit of channel
void dmac_enable(int ch)
{
	int x;
	CpuSuspendIntr(&x); //intrman

	switch (ch)
	{
		case DMAch_MDECin:
			dmac_set_dpcr(
				(dmac_get_dpcr() | 0x00000008));
			break;
		case DMAch_MDECout:
			dmac_set_dpcr(
				(dmac_get_dpcr() | 0x00000080));
			break;
		case DMAch_GPU:
			dmac_set_dpcr(
				(dmac_get_dpcr() | 0x00000800));
			break;
		case DMAch_CD:
			dmac_set_dpcr(
				(dmac_get_dpcr() | 0x00008000));
			break;
		case DMAch_SPU:
			dmac_set_dpcr(
				(dmac_get_dpcr() | 0x00080000));
			break;
		case DMAch_PIO:
			dmac_set_dpcr(
				(dmac_get_dpcr() | 0x00800000));
			break;
		case DMAch_GPUotc:
			dmac_set_dpcr(
				(dmac_get_dpcr() | 0x08000000));
			break;
		case DMAch_SPU2:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() | 0x00000008));
			break;
		case DMAch_8:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() | 0x00000080));
			break;
		case DMAch_SIF0:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() | 0x00000800));
			break;
		case DMAch_SIF1:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() | 0x00008000));
			break;
		case DMAch_SIO2in:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() | 0x00080000));
			break;
		case DMAch_SIO2out:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() | 0x00800000));
			break;
		case DMAch_13:
			dmac_set_dpcr3(
				(dmac_get_dpcr3() | 0x00000008));
			break;
		case DMAch_14:
			dmac_set_dpcr3(
				(dmac_get_dpcr3() | 0x00000080));
			break;
		case DMAch_15:
			dmac_set_dpcr3(
				(dmac_get_dpcr3() | 0x00000800));
			break;
		case DMAch_85:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() | 0x08000000));
			break;
	}

	CpuResumeIntr(x); //intrman
}

///////////////////////////////////////////////////////////////////////
// reset 4th bit of channel
void dmac_disable(int ch)
{
	int x;
	CpuSuspendIntr(&x); //intrman

	switch (ch)
	{
		case DMAch_MDECin:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0xFFFFFFF7));
			break;
		case DMAch_MDECout:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0xFFFFFF7F));
			break;
		case DMAch_GPU:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0xFFFFF7FF));
			break;
		case DMAch_CD:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0xFFFF7FFF));
			break;
		case DMAch_SPU:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0xFFF7FFFF));
			break;
		case DMAch_PIO:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0xFF7FFFFF));
			break;
		case DMAch_GPUotc:
			dmac_set_dpcr(
				(dmac_get_dpcr() & 0xF7FFFFFF));
			break;
		case DMAch_SPU2:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() & 0xFFFFFFF7));
			break;
		case DMAch_8:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() & 0xFFFFFF7F));
			break;
		case DMAch_SIF0:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() & 0xFFFFF7FF));
			break;
		case DMAch_SIF1:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() & 0xFFFF7FFF));
			break;
		case DMAch_SIO2in:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() & 0xFFF7FFFF));
			break;
		case DMAch_SIO2out:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() & 0xFF7FFFFF));
			break;
		case DMAch_13:
			dmac_set_dpcr3(
				(dmac_get_dpcr3() & 0xFFFFFFF7));
			break;
		case DMAch_14:
			dmac_set_dpcr3(
				(dmac_get_dpcr3() & 0xFFFFFF7F));
			break;
		case DMAch_15:
			dmac_set_dpcr3(
				(dmac_get_dpcr3() & 0xFFFFF7FF));
			break;
		case DMAch_85:
			dmac_set_dpcr2(
				(dmac_get_dpcr2() & 0xF7FFFFFF));
			break;
	}

	CpuResumeIntr(x); //intrman
}

void _retonly() {}

//////////////////////////////entrypoint///////////////////////////////
struct export dmacman_stub = {
	0x41C00000,
	0,
	VER(1, 2), // 1.2 => 0x102
	0,
	"dmacman",
	(func)_start, // entrypoint
	(func)_retonly,
	(func)dmacDeinit,
	(func)_retonly,
	(func)dmac_ch_set_madr,
	(func)dmac_ch_get_madr,
	(func)dmac_ch_set_bcr,
	(func)dmac_ch_get_bcr,
	(func)dmac_ch_set_chcr,
	(func)dmac_ch_get_chcr,
	(func)dmac_ch_set_tadr,
	(func)dmac_ch_get_tadr,
	(func)dmac_set_4_9_a,
	(func)dmac_get_4_9_a,
	(func)dmac_set_dpcr,
	(func)dmac_get_dpcr,
	(func)dmac_set_dpcr2,
	(func)dmac_get_dpcr2,
	(func)dmac_set_dpcr3,
	(func)dmac_get_dpcr3,
	(func)dmac_set_dicr,
	(func)dmac_get_dicr,
	(func)dmac_set_dicr2,
	(func)dmac_get_dicr2,
	(func)dmac_set_BF80157C,
	(func)dmac_get_BF80157C,
	(func)dmac_set_BF801578,
	(func)dmac_get_BF801578,
	(func)dmac_request,
	(func)dmac_set_dma_chained_spu_sif0,
	(func)dmac_set_dma_sif0,
	(func)dmac_set_dma_sif1,
	(func)dmac_transfer,
	(func)dmac_ch_set_dpcr,
	(func)dmac_enable,
	(func)dmac_disable,
	0};

//////////////////////////////entrypoint///////////////////////////////
int _start(int argc, char* argv[])
{
	int x;
	register int ch;

	if (RegisterLibraryEntries(&dmacman_stub)) //loadcore
		return 1;

	CpuSuspendIntr(&x); //intrman

	dmac_set_dpcr(0x07777777);
	dmac_set_dpcr2(0x07777777);
	dmac_set_dpcr3(0x00000777);
	for (ch = 0; ch < 13; ch++)
	{
		dmac_ch_set_madr(ch, 0);
		dmac_ch_set_bcr(ch, 0);
		dmac_ch_set_chcr(ch, 0);
	}
	dmac_ch_set_tadr(DMAch_SPU, 0);
	dmac_ch_set_tadr(DMAch_SIF0, 0);
	dmac_set_4_9_a(DMAch_SPU, 0);
	dmac_set_4_9_a(DMAch_SIF0, 0);
	dmac_set_4_9_a(DMAch_SIF1, 0);
	dmac_set_BF801578(1);

	CpuResumeIntr(x); //intrman
	return 0;
}
