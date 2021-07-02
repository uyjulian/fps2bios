/*
  _____     ___ ____ 
   ____|   |    ____|      PSX2 OpenSource Project
  |     ___|   |____       (C)2001, Gustavo Scotti (gustavo@scotti.com)
  ------------------------------------------------------------------------
  iop_sifman.s		   Serial Interface Manager Functions.
			   taken from .irx files with symbol table.
*/

	.text
	.set	noreorder


/* ############################### SIFMAN STUB ######## */
/* # Added by Oobles, 7th March 2002                  # */

	.local	sifman_stub
sifman_stub:
	.word	0x41e00000
	.word	0
	.word	0x00000101
	.ascii	"sifman\0\0"
	.align	2

	.globl  SifDeinit			# 0x03
SifDeinit:
	j	$31
	li	$0, 0x03

	.globl  sceSifDma2Init			# 0x04
sceSifDma2Init:
	j	$31
	li	$0, 0x04

	.globl  sceSifInit				# 0x05
sceSifInit:
	j	$31
	li	$0, 0x05

	.globl	sceSifSetDChain			# 0x06
sceSifSetDChain:
	j	$31
	li	$0, 0x06

	.globl	sceSifSetDma			# 0x07
sceSifSetDma:
	j	$31
	li	$0, 0x07

	.globl	sceSifDmaStat			# 0x08
sceSifDmaStat:
	j	$31
	li	$0, 0x08

	.globl	sceSifSetOneDma				# 0x09
sceSifSetOneDma:
	j	$31
	li	$0, 0x09

	.globl	SifSendSync			# 0x0A
SifSendSync:
	j	$31
	li	$0, 0x0A

	.globl	SifIsSending			# 0x0B
SifIsSending:
	j	$31
	li	$0, 0x0B

	.globl	sceSifDma0Transfer			# 0x0C
sceSifDma0Transfer:
	j	$31
	li	$0, 0x0C

	.globl	sceSifDma0Sync			# 0x0D
sceSifDma0Sync:
	j	$31
	li	$0, 0x0D

	.globl	sceSifDma0Sending			# 0x0E
sceSifDma0Sending:
	j	$31
	li	$0, 0x0E

	.globl	sceSifDma1Transfer			# 0x0F
sceSifDma1Transfer:
	j	$31
	li	$0, 0x0F

	.globl	sceSifDma1Sync			# 0x10
sceSifDma1Sync:
	j	$31
	li	$0, 0x10

	.globl	sceSifDma1Sending			# 0x11
sceSifDma1Sending:
	j	$31
	li	$0, 0x11

	.globl	sceSifDma2Transfer			# 0x12
sceSifDma2Transfer:
	j	$31
	li	$0, 0x12

	.globl	sceSifDma2Sync			# 0x13
sceSifDma2Sync:
	j	$31
	li	$0, 0x13

	.globl	sceSifDma2Sending			# 0x14
sceSifDma2Sending:
	j	$31
	li	$0, 0x14

	.globl	sceSifGetMSFlag		# 0x15
sceSifGetMSFlag:
	j	$31
	li	$0, 0x15

	.globl	sceSifSetMSFlag		# 0x16
sceSifSetMSFlag:
	j	$31
	li	$0, 0x16

	.globl	sceSifGetSMFlag		# 0x17
sceSifGetSMFlag:
	j	$31
	li	$0, 0x17

	.globl	sceSifSetSMFlag		# 0x18
sceSifSetSMFlag:
	j	$31
	li	$0, 0x18

	.globl	sceSifGetMainAddr			# 0x19
sceSifGetMainAddr:
	j	$31
	li	$0, 0x19

	.globl	sceSifGetSubAddr		# 0x1A
sceSifGetSubAddr:
	j	$31
	li	$0, 0x1A

	.globl	sceSifSetSubAddr		# 0x1B
sceSifSetSubAddr:
	j	$31
	li	$0, 0x1B

	.globl	sceSifIntrMain			# 0x1C
sceSifIntrMain:
	j	$31
	li	$0, 0x1C

	.globl	sceSifCheckInit			# 0x1D
sceSifCheckInit:
	j	$31
	li	$0, 0x1D

	.globl	sceSifSetDmaIntrHandler			# 0x1E
sceSifSetDmaIntrHandler:
	j	$31
	li	$0, 0x1E

	.globl	sceSifResetDmaIntrHandler			# 0x1F
sceSifResetDmaIntrHandler:
	j	$31
	li	$0, 0x1F

	.globl	SifSetDmaIntr			# 0x20
SifSetDmaIntr:
	j	$31
	li	$0, 0x20

	.word	0
	.word	0


