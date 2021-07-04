#ifndef __DMACMAN_H__
#define __DMACMAN_H__

#define DMACMAN_VER 0x101

//////////////////////////////  D_CHCR - DMA Channel Control Register
#define DMAf_30 0x40000000 // unknown; set on 'to' direction
#define DMAf_TR 0x01000000 // DMA transfer
#define DMAf_LI 0x00000400 // Linked list GPU; also SPU & SIF0
#define DMAf_CO 0x00000200 // Continuous stream
#define DMAf_08 0x00000100 // unknown
#define DMAf_DR 0x00000001 // Direction to=0/from=1
//  31           24 23           16 15            8 7             0
// ÖÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄÒÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄÒÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄÒÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄ·
// º ³?³ ³ ³ ³ ³ ³Tº ³ ³ ³ ³ ³ ³ ³ º ³ ³ ³ ³ ³L³C³?º ³ ³ ³ ³ ³ ³ ³Dº
// º ³?³ ³ ³ ³ ³ ³Rº ³ ³ ³ ³ ³ ³ ³ º ³ ³ ³ ³ ³I³O³?º ³ ³ ³ ³ ³ ³ ³Rº
// ÓÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄÐÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄÐÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄÐÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄ½
//   30          24                          10 9 8               0

//////////////////////////////  DPCR - DMA Primary Control Register
// ÖÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄÒÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄÒÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄÒÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄ·
// º   67  ³ DMA 6 º DMA 5 ³ DMA 4 º DMA 3 ³ DMA 2 º DMA 1 ³ DMA 0 º 0xBF8010F0 DPCR
// ÓÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄÐÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄÐÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄÐÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄ½
// ÖÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄÒÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄÒÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄÒÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄ·
// º       ³ DMA85 º DMA12 ³ DMA11 º DMA10 ³ DMA 9 º DMA 8 ³ DMA 7 º 0xBF801570 DPCR_
// ÓÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄÐÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄÐÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄÐÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄ½
// ÖÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄÒÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄÒÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄÒÄÂÄÂÄÂÄÂÄÂÄÂÄÂÄ·
// º       ³       º       ³       º       ³ DMA15 º DMA14 ³ DMA13 º 0xBF8015F0 DPCR__
// ÓÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄÐÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄÐÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄÐÄÁÄÁÄÁÄÁÄÁÄÁÄÁÄ½

////////// DPCR
#define DMAch_MDECin 0
#define DMAch_MDECout 1
#define DMAch_GPU 2 // SIF2 both directions
#define DMAch_CD 3
#define DMAch_SPU 4
#define DMAch_PIO 5
#define DMAch_GPUotc 6

#define DMAch_67 67 // strange

////////// DPCR_
#define DMAch_SPU2 7
#define DMAch_8 8
#define DMAch_SIF0 9 // SIFout IOP->EE
#define DMAch_SIF1 10 // SIFin  EE->IOP
#define DMAch_SIO2in 11
#define DMAch_SIO2out 12

#define DMAch_85 85 // stange, very strange

////////// DPCR__
#define DMAch_13 13
#define DMAch_14 14
#define DMAch_15 15

int dmacman_start(int argc, char* argv[]); // 0
int dmacman_deinit(); // 2

void dmac_ch_set_madr(unsigned int ch, int value); // 4
int dmac_ch_get_madr(unsigned int ch); // 5
void dmac_ch_set_bcr(unsigned int ch, int value); // 6
int dmac_ch_get_bcr(unsigned int ch); // 7
void dmac_ch_set_chcr(unsigned int ch, int value); // 8
int dmac_ch_get_chcr(unsigned int ch); // 9
void dmac_ch_set_tadr(unsigned int ch, int value); //10
int dmac_ch_get_tadr(unsigned int ch); //11
void dmac_set_4_9_a(unsigned int ch, int value); //12
int dmac_get_4_9_a(unsigned int ch); //13
void dmac_set_dpcr(int value); //14
int dmac_get_dpcr(); //15
void dmac_set_dpcr2(int value); //16
int dmac_get_dpcr2(); //17
void dmac_set_dpcr3(int value); //18
int dmac_get_dpcr3(); //19
void dmac_set_dicr(int value); //20
int dmac_get_dicr(); //21
void dmac_set_dicr2(int value); //22
int dmac_get_dicr2(); //23
void dmac_set_BF80157C(int value); //24
int dmac_get_BF80157C(); //25
void dmac_set_BF801578(int value); //26
int dmac_get_BF801578(); //27
int dmac_request(int ch, int address, int size, int count, int dir); //28
int dmac_set_dma_chained_spu_sif0(int ch, int size, int c); //29
int dmac_set_dma_sif0(int ch, int size, int c); //30
int dmac_set_dma_sif1(int ch, int size); //31
void dmac_transfer(int ch); //32
void dmac_ch_set_dpcr(int ch, int value); //33
void dmac_enable(int ch); //34
void dmac_disable(int ch); //35

//SIF2 DMA ch 2 (GPU)
#define DMAch_SIF2_MADR (*(volatile int*)0xBF8010A0)
#define DMAch_SIF2_BCR (*(volatile int*)0xBF8010A4)
#define DMAch_SIF2_BCR_size (*(volatile short*)0xBF8010A4)
#define DMAch_SIF2_BCR_count (*(volatile short*)0xBF8010A6)
#define DMAch_SIF2_CHCR (*(volatile int*)0xBF8010A8)
//SIF0 DMA ch 9
#define DMAch_SIF9_MADR (*(volatile int*)0xBF801520)
#define DMAch_SIF9_BCR (*(volatile int*)0xBF801524)
#define DMAch_SIF9_BCR_size (*(volatile short*)0xBF801524)
#define DMAch_SIF9_BCR_count (*(volatile short*)0xBF801526)
#define DMAch_SIF9_CHCR (*(volatile int*)0xBF801528)
#define DMAch_SIF9_TADR (*(volatile int*)0xBF80152C)
//SIF1 DMA ch 10 (0xA)
#define DMAch_SIFA_MADR (*(volatile int*)0xBF801530)
#define DMAch_SIFA_BCR (*(volatile int*)0xBF801534)
#define DMAch_SIFA_BCR_size (*(volatile short*)0xBF801534)
#define DMAch_SIFA_BCR_count (*(volatile short*)0xBF801536)
#define DMAch_SIFA_CHCR (*(volatile int*)0xBF801538)

#define DMAch_DPCR (*(volatile int*)0xBF8010F0)
#define DMAch_DPCR2 (*(volatile int*)0xBF801570)

#endif //__DMACMAN_H__
