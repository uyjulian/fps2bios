/*
  _____     ___ ____ 
   ____|   |    ____|      PSX2 OpenSource Project
  |     ___|   |____       (C)2002, David Ryan (oobles@hotmail.com)
  ------------------------------------------------------------------------
  iop_dmacman.s		   DMAC library function imports.
			   taken from dmacman in bios.
*/

	.text
	.set	noreorder


/* ############################### DMACMAN STUB ######## */
	.local	dmacman_stub
dmacman_stub:
	.word	0x41e00000
	.word	0
	.word	0x00000101
	.ascii	"dmacman\0"
	.align	2

	.globl	dmac_request			# 028
dmac_request:
	j	$31
	li	$0, 28

	.globl	dmac_transfer	# 032
dmac_transfer:
	j	$31
	li	$0, 32

	.globl	dmac_ch_set_dpcr			# 033
dmac_ch_set_dpcr:
	j	$31
	li	$0, 33

	.globl	dmac_enable		# 034
dmac_enable:
	j	$31
	li	$0, 34

	.globl	dmac_disable	# 035
dmac_disable:
	j	$31
	li	$0, 35


	.word	0
	.word	0


