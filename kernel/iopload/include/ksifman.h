#ifndef __SIFMAN_H__
#define __SIFMAN_H__

#include <tamtypes.h>

#define SIFMAN_VER 0x101

#define SIF_FROM_IOP 0x0
#define SIF_TO_IOP 0x1
#define SIF_FROM_EE 0x0
#define SIF_TO_EE 0x1

#define SIF_DMA_INT_I 0x2
#define SIF_DMA_INT_O 0x4
#define SIF_DMA_SPR 0x8
#define SIF_DMA_BSN 0x10
#define SIF_DMA_TAG 0x20

struct sifman_DMA
{ //t_sif_dma_transfer
	void* data;
	void* addr;
	int size;
	int attr;
};

void SifDeinit(); //2

void sceSifDma2Init(); //4
void sceSifInit(); //5 (21,25,26)
void sceSifSetDChain(); //6
u32 sceSifSetDma(struct sifman_DMA* psd, int len); //7 (26)
int sceSifDmaStat(u32 id); //8 (26)
void sceSifSetOneDma(struct sifman_DMA sd); //9
void SifSendSync(); //10
int SifIsSending(); //11
void sceSifDma0Transfer(void* data, int size, int attr); //12
void sceSifDma0Sync(); //13
int sceSifDma0Sending(); //14
void sceSifDma1Transfer(void* data, int size, int attr); //15
void sceSifDma1Sync(); //16
int sceSifDma1Sending(); //17
void sceSifDma2Transfer(void* data, int size, int attr); //18
void sceSifDma2Sync(); //19
int sceSifDma2Sending(); //20
int sceSifGetMSFlag(); //21
int sceSifSetMSFlag(int val); //22(21)
int sceSifGetSMFlag(); //23
int sceSifSetSMFlag(int val); //24(28)
int sceSifGetMainAddr(); //25
int sceSifGetSubAddr(); //26
int sceSifSetSubAddr(int val); //27
void sceSifIntrMain(); //28
int sceSifCheckInit(); //29(21,26)
void sceSifSetDmaIntrHandler(int (*_function)(int), int _param); //30
void sceSifResetDmaIntrHandler(); //31

#endif /* __SIFMAN_H__ */
