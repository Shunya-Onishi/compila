
	INITIAL_GP = 0x10008000		# initial value of global pointer
	INITIAL_SP = 0x7ffffffc		# initial value of stack pointer
	stop_service = 99

	.text	0x00001000

init:
	la	$gp, INITIAL_GP
	la	$sp, INITIAL_SP
	jal	main
	nop
	li	$v0, stop_service
	syscall
	nop
main:
	la	$t0, _sum
	li	$t1,0
	nop
	sw	$t1, 0($t0)
	nop
	la	$t0, _i
	li	$t1,1
	nop
	sw	$t1, 0($t0)
	nop
L1:
	la	$t1,_i
	nop
	lw	$t2,0($t1)
	nop
	li	$t3,11
	nop
	slt	$t0, $t2, $t3
	beq	$t0, $zero, L2
	nop
	la	$t1,_i
	nop
	lw	$t2, 0($t1)
	nop
	la	$t3,_sum
	nop
	lw	$t4,0($t3)
	nop
	addu	$t4, $t4, $t2
	sw	$t4, 0($t3)
	nop
	addi	$t2, $t2, 1
	sw	$t2, 0($t1)
	j	L1
	nop
L2:
	jr	$ra
	nop

.data	0x10004000
_i:	.word	0x0000
_sum:	.word	0x0000
