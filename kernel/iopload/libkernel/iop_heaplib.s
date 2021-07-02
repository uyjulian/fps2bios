/*
  _____     ___ ____ 
   ____|   |    ____|      PSX2 OpenSource Project
  |     ___|   |____       (C)2002, David Ryan (oobles@hotmail.com)
  ------------------------------------------------------------------------
  iop_heaplib.s		   Heap library function imports.
			   taken from heaplib in bios.
*/

	.text
	.set	noreorder


/* ############################### SYSMEM STUB ######## */
	.local	sysmem_stub
sysmem_stub:
	.word	0x41e00000
	.word	0
	.word	0x00000101
	.ascii	"heaplib\0"
	.align	2

	.globl	CreateHeap			# 004
CreateHeap:
	j	$31
	li	$0, 4

	.globl	DeleteHeap			# 005
DeleteHeap:
	j	$31
	li	$0, 5

	.globl	AllocHeapMemory			# 006
AllocHeapMemory:
	j	$31
	li	$0, 6

	.globl	FreeHeapMemory			# 007
FreeHeapMemory:
	j	$31
	li	$0, 7

	.globl	HeapTotalFreeSize			# 008 
HeapTotalFreeSize:
	j	$31
	li	$0, 8 

	.word	0
	.word	0


