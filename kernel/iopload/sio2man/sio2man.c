//[module]	SIO2MAN
//[processor]	IOP
//[type]	ELF-IRX
//[size]	?(0x?)
//[bios]	?(0x?-0x?)
//[iopboot2]	21
//[loaded @]	?
//[name]	sio2man
//[version]	0x101
//[memory map]	0xBF808200,0xBF808204,0xBF808208,0xBF80820C,
//		0xBF808210,0xBF808214,0xBF808218,0xBF80821C,  16 entries
//		0xBF808220,0xBF808224,0xBF808228,0xBF80822C,     array
//		0xBF808230,0xBF808234,0xBF808238,0xBF80823C,
//		0xBF808240,0xBF808244,0xBF808248,0xBF80824C,
//		0xBF808250,0xBF808254,0xBF808258,0xBF80825C,
//		0xBF808260,           0xBF808268,0xBF80826C,
//		0xBF808270,0xBF808274,0xBF808278,0xBF80827C,
//		0xBF808280
//[handlers]	-
//[entry point]	_start, (export_stub)
//[made by]	Herben

#include <tamtypes.h>
#include <stdio.h>

#include "kdmacman.h"
#include "kloadcore.h"
#include "kintrman.h"
#include <thbase.h>
#include <thevent.h>

struct sio2_packet
{
	u32 recvVal1; // 0x00
	u32 sendArray1[4]; // 0x04-0x10
	u32 sendArray2[4]; // 0x14-0x20

	u32 recvVal2; // 0x24

	u32 sendArray3[16]; // 0x28-0x64

	u32 recvVal3; // 0x68

	int sendSize; // 0x6C
	int recvSize; // 0x70

	u8* sendBuf; // 0x74
	u8* recvBuf; // 0x78

	u32 dmacAddress1;
	u32 dmacSize1;
	u32 dmacCount1;
	u32 dmacAddress2;
	u32 dmacSize2;
	u32 dmacCount2;
};

struct sio2common
{
	int evid;
	int thid;
};

struct sio2common common;
int sio2_initialized = 0;
struct sio2_packet* packetAddr;
int debug = 1;

#define _dprintf(fmt, args...) \
	if (debug > 0) \
	printf(fmt, ##args)

//	if (debug > 0) printf("\033[0;32m" "sio2man: " "\033[0m" fmt, ## args)

int _start(void);
void nullSub(void);
int sio2_init(void);
void sio2_deInit(void);
void sio2_ctrl_set(u32 arg0);
u32 sio2_ctrl_get(void);
u32 sio2_stat6c_get(void);
void sio2_portN_ctrl1_set(int entryNum, u32 val);
u32 sio2_portN_ctrl1_get(int entryNum);
void sio2_portN_ctrl2_set(int entryNum, u32 val);
u32 sio2_portN_ctrl2_get(int entryNum);
u32 sio2_stat70_get(void);
void sio2_regN_set(int entryNum, u32 val);
u32 sio2_regN_get(int entryNum);
u32 sio2_stat74_get(void);
void sio2_unkn78_set(u32 arg0);
u32 sio2_unkn78_get(void);
void sio2_unkn7c_set(u32 arg0);
u32 sio2_unkn7c_get(void);
void sio2_data_out(u8 arg0);
u8 sio2_data_in(void);
void sio2_stat_set(u32 arg0);
u32 sio2_stat_get(void);
void sio2_pad_transfer_init(void);
void sio2_mc_transfer_init(void);
int sio2_transfer(struct sio2_packet* packet);

struct export sio2man_stub = {
	0x41C00000,
	0,
	VER(1, 2), // 1.2 => 0x102
	0,
	"sio2man",
	(func)_start, // 0
	(func)nullSub,
	(func)sio2_deInit,
	(func)nullSub,
	(func)sio2_ctrl_set, // 4
	(func)sio2_ctrl_get,
	(func)sio2_stat6c_get,
	(func)sio2_portN_ctrl1_set,
	(func)sio2_portN_ctrl1_get, // 8
	(func)sio2_portN_ctrl2_set,
	(func)sio2_portN_ctrl2_get,
	(func)sio2_stat70_get,
	(func)sio2_regN_set, // 12
	(func)sio2_regN_get,
	(func)sio2_stat74_get,
	(func)sio2_unkn78_set,
	(func)sio2_unkn78_get, // 16
	(func)sio2_unkn7c_set,
	(func)sio2_unkn7c_get,
	(func)sio2_data_out,
	(func)sio2_data_in, // 20
	(func)sio2_stat_set,
	(func)sio2_stat_get,
	(func)sio2_pad_transfer_init,
	(func)sio2_mc_transfer_init, // 24
	(func)sio2_transfer,
	0};

#define INUM_sio2 17
#define HTYPE_C 1


int _start(void)
{
	return sio2_init();
}

void nullSub(void) { return; }

void sio2_ctrl_set(u32 arg0)
{
	*(u32*)(0xBF808268) = arg0;
}

u32 sio2_ctrl_get(void)
{
	return (*(u32*)(0xBF808268));
}

u32 sio2_stat6c_get(void)
{
	return (*(u32*)(0xBF80826C));
}

void sio2_portN_ctrl1_set(int entryNum, u32 val)
{
	switch (entryNum)
	{
		case 0:
			*(u32*)(0xBF808240) = val;
			break;
		case 1:
			*(u32*)(0xBF808248) = val;
			break;
		case 2:
			*(u32*)(0xBF808250) = val;
			break;
		case 3:
			*(u32*)(0xBF808258) = val;
			break;
	}
}

u32 sio2_portN_ctrl1_get(int entryNum)
{
	switch (entryNum)
	{
		case 0:
			return (*(u32*)(0xBF808240));
		case 1:
			return (*(u32*)(0xBF808248));
		case 2:
			return (*(u32*)(0xBF808250));
		case 3:
			return (*(u32*)(0xBF808258));
	}

	return (0);
}

void sio2_portN_ctrl2_set(int entryNum, u32 val)
{
	switch (entryNum)
	{
		case 0:
			*(u32*)(0xBF808244) = val;
			break;
		case 1:
			*(u32*)(0xBF80824C) = val;
			break;
		case 2:
			*(u32*)(0xBF808254) = val;
			break;
		case 3:
			*(u32*)(0xBF80825C) = val;
			break;
	}
}

u32 sio2_portN_ctrl2_get(int entryNum)
{
	switch (entryNum)
	{
		case 0:
			return (*(u32*)(0xBF808244));
		case 1:
			return (*(u32*)(0xBF80824C));
		case 2:
			return (*(u32*)(0xBF808254));
		case 3:
			return (*(u32*)(0xBF80825C));
	}

	return (0);
}

u32 sio2_stat70_get(void)
{
	return (*(u32*)(0xBF808270));
}

void sio2_regN_set(int entryNum, u32 val)
{
	if (entryNum < 16)
		*(u32*)(0xBF808200 + (entryNum * 4)) = val;
}

u32 sio2_regN_get(int entryNum)
{
	if (entryNum < 16)
		return (*(u32*)(0xBF808200 + (entryNum * 4)));

	return (-1);
}

u32 sio2_stat74_get(void)
{
	return (*(u32*)(0xBF808274));
}

void sio2_unkn78_set(u32 arg0)
{
	*(u32*)(0xBF808278) = arg0;
}

u32 sio2_unkn78_get(void)
{
	return (*(u32*)(0xBF808278));
}

void sio2_unkn7c_set(u32 arg0)
{
	*(u32*)(0xBF80827C) = arg0;
}

u32 sio2_unkn7c_get(void)
{
	return (*(u32*)(0xBF80827C));
}

void sio2_data_out(u8 arg0)
{
	*(u8*)(0xBF808260) = arg0;
}

u8 sio2_data_in(void)
{
	return (*(u8*)(0xBF808264));
}

void sio2_stat_set(u32 arg0)
{
	*(u32*)(0xBF808280) = arg0;
}

u32 sio2_stat_get(void)
{
	return (*(u32*)(0xBF808280));
}

int sio2_createEventFlag(void)
{
	iop_event_t param;

	param.attr = 2;
	param.option = 0;
	param.bits = 0;
	return (CreateEventFlag(&param));
}

void dumpbuf(u8* buf, int size)
{
	/*	char str[1024];
	char tmp[256];
	int i;

	str[0] = 0;
	for(i = 0; i < size; i++) {
		sprintf(tmp, "%x, ", buf[i]);
		strcat(str, tmp);
	}
	printf("%s\n", str);
	*/
}

void sio2_sendPacket(struct sio2_packet* p)
{
	int i;

	//	_dprintf("%s: sendSize=%d\n", __FUNCTION__, p->sendSize);

	for (i = 0; i < 4; i++)
	{
		sio2_portN_ctrl1_set(i, p->sendArray1[i]);
		sio2_portN_ctrl2_set(i, p->sendArray2[i]);
	}

	for (i = 0; i < 16; i++)
		sio2_regN_set(i, p->sendArray3[i]);

	if (p->sendSize)
	{
		_dprintf("sendBuf: ");
		dumpbuf(p->sendBuf, p->sendSize);

		for (i = 0; i < p->sendSize; i++)
		{
			*(u8*)(0xBF808260) = p->sendBuf[i];
		}
	}

	if (p->dmacAddress1 != 0)
	{
		_dprintf("dmaAddress1=%x, dmacSize1=%x, dmacCount1=%x\n", p->dmacAddress1, p->dmacSize1, p->dmacCount1);
		dumpbuf((u8*)p->dmacAddress1, p->dmacSize1 * p->dmacCount1);
		dmac_request(DMAch_SIO2in, p->dmacAddress1, p->dmacSize1, p->dmacCount1, 1); // from memory
		dmac_transfer(DMAch_SIO2in);
	}

	if (p->dmacAddress2 != 0)
	{
		dmac_request(DMAch_SIO2out, p->dmacAddress2, p->dmacSize2, p->dmacCount2, 0); // to memory
		dmac_transfer(DMAch_SIO2out);
	}
}

void sio2_recvPacket(struct sio2_packet* p)
{
	int i;

	//	_dprintf("%s: recvSize=%d\n", __FUNCTION__, p->recvSize);

	p->recvVal1 = *(u32*)(0xBF80826C);
	p->recvVal2 = *(u32*)(0xBF808270);
	p->recvVal3 = *(u32*)(0xBF808274);

	if (p->recvSize)
	{
		_dprintf("recvBuf: ");
		for (i = 0; i < p->recvSize; i++)
		{
			p->recvBuf[i] = *(u8*)(0xBF808264);
			printf("%x, ", p->recvBuf[i]);
		}
		//	printf("\n");
	}

	if (p->dmacAddress2 != 0)
	{
		dumpbuf((u8*)p->dmacAddress2, p->dmacSize2 * p->dmacCount2);
	}
}

void sio2_basicThread(void* data)
{
	unsigned long result[4];

	//_dprintf("%s\n", __FUNCTION__);

	while (1)
	{
		WaitEventFlag(common.evid, 0x5, 0x01, result);

		if (result[0] & 0x01)
		{
			ClearEventFlag(common.evid, ~0x1);
			SetEventFlag(common.evid, 0x02);
		}
		else if (result[0] & 0x04)
		{
			ClearEventFlag(common.evid, ~0x4);
			SetEventFlag(common.evid, 0x08);
		}
		else
		{
			printf("sio2MAN: Woke up for unknown event(%08X)!\n", result[0]);
			return;
		}

		// Wait for application to call our export 25
		WaitEventFlag(common.evid, 0x10, 0, NULL);
		ClearEventFlag(common.evid, ~0x10);

		*(u32*)(0xBF808268) = (*(u32*)(0xBF808268)) | 0x0C;
		sio2_sendPacket(packetAddr);
		*(u32*)(0xBF808268) = (*(u32*)(0xBF808268)) | 0x01;

		// Wait for the sio2 interrupt to occur
		WaitEventFlag(common.evid, 0x80, 0, NULL);
		ClearEventFlag(common.evid, ~0x80);

		// Recieve the reply packet
		sio2_recvPacket(packetAddr);

		SetEventFlag(common.evid, 0x20);

		WaitEventFlag(common.evid, 0x40, 0, NULL);
		ClearEventFlag(common.evid, ~0x40);
	}
}

int sio2_createBasicThread(void)
{
	iop_thread_t param;

	param.attr = TH_C;
	param.option = 0;
	param.thread = &sio2_basicThread;
	param.stacksize = 0x2000;
	param.priority = 0x18;

	return (CreateThread(&param));
}


int sio2_interruptHandler(struct sio2common* c)
{
	sio2_stat_set(sio2_stat_get());

	iSetEventFlag(c->evid, 0x80);

	return (1);
}

// Export 0
int sio2_init(void)
{
	int oldStat;

	//	_dprintf("%s\n", __FUNCTION__);

	if (RegisterLibraryEntries(&sio2man_stub) != 0)
	{
		//printf("sio2MAN: Unable to register library entries!\n");
		return (MODULE_NO_RESIDENT_END); //==1
	}

	if (sio2_initialized != 0)
	{
		//printf("sio2MAN: Already initialized!\n");
		return (MODULE_NO_RESIDENT_END);
	}

	sio2_initialized = 1;

	*(u32*)(0xBF808268) = 0x3BC;

	common.evid = sio2_createEventFlag();
	common.thid = sio2_createBasicThread();

	CpuSuspendIntr(&oldStat);

	RegisterIntrHandler(INUM_sio2, HTYPE_C, &sio2_interruptHandler, &common);
	EnableIntr(INUM_sio2);

	CpuResumeIntr(oldStat);

	dmac_ch_set_dpcr(DMAch_SIO2in, 0x03);
	dmac_ch_set_dpcr(DMAch_SIO2out, 0x03);
	dmac_enable(DMAch_SIO2in);
	dmac_enable(DMAch_SIO2out);

	StartThread(common.thid, 0); // Start the "basicThread"

	return MODULE_RESIDENT_END;
}

void sio2_deInit(void)
{
	int oldStat;

	//	_dprintf("%s\n", __FUNCTION__);

	CpuSuspendIntr(&oldStat);

	DisableIntr(INUM_sio2, 0);
	ReleaseIntrHandler(INUM_sio2);

	CpuResumeIntr(oldStat);

	dmac_disable(DMAch_SIO2in);
	dmac_disable(DMAch_SIO2out);
}

void sio2_pad_transfer_init(void)
{
	//	_dprintf("%s\n", __FUNCTION__);

	// Signal the basic thread to let it know we want to do an exchange.
	SetEventFlag(common.evid, 0x01);
	// Wait for basic thread to acknowledge then clear the flag.
	WaitEventFlag(common.evid, 0x02, 0, NULL);
	ClearEventFlag(common.evid, ~0x2);
}

void sio2_mc_transfer_init(void)
{
	//	_dprintf("%s\n", __FUNCTION__);

	// Signal the basic thread to let it know we want to do an exchange.
	SetEventFlag(common.evid, 0x04);
	// Wait for basic thread to acknowledge then clear the flag.
	WaitEventFlag(common.evid, 0x08, 0, NULL);
	ClearEventFlag(common.evid, ~0x8);
}

int sio2_transfer(struct sio2_packet* packet)
{
	//	_dprintf("%s: %x\n", __FUNCTION__, packet);

	// Set the address of the packet.
	packetAddr = packet;

	// Let the basic thread know we have the address set for the exchange.
	SetEventFlag(common.evid, 0x10);

	// Wait for the basic thread to finish it's stuff.
	WaitEventFlag(common.evid, 0x20, 0, NULL);
	ClearEventFlag(common.evid, ~0x20);

	SetEventFlag(common.evid, 0x40);

	return 1;
}
