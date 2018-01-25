	.file	1 "memo.c"

 # -G value = 0, Cpu = r2000, ISA = 1
 # GNU C version 2.96-mips3264-000710 (mipsel-linux) compiled by GNU C version 2.96 20000731 (Red Hat Linux 7.2 2.96-112.7.2).
 # [AL 1.1, MM 40] BSD Mips
 # options passed:  -mno-abicalls -mrnames -mmips-as
 # -mno-check-zero-division -mcpu=r2000 -O0 -fleading-underscore
 # -finhibit-size-directive -fverbose-asm
 # options enabled:  -fpeephole -fkeep-static-consts -fpcc-struct-return
 # -fsched-interblock -fsched-spec -fnew-exceptions -fcommon
 # -finhibit-size-directive -fverbose-asm -fgnu-linker -flive-range-gdb
 # -fargument-alias -fleading-underscore -fdelay-postincrement -fident
 # -fmath-errno -msplit-addresses -mrnames -mno-check-zero-division
 # -mdebugf -mdebugi -mno-div-checks -mcpu=r2000


	.text
	.align	2
	.set	nomips16
main:
	subu	$sp,$sp,16
	sw	$fp,8($sp)
	move	$fp,$sp
	sw	$zero,4($fp)
	li	$v0,1			# 0x1
	sw	$v0,0($fp)
$L3:
	lw	$v0,0($fp)
	slt	$v0,$v0,11
	bne	$v0,$zero,$L5
	b	$L4
$L5:
	lw	$v1,4($fp)
	lw	$v0,0($fp)
	addu	$v0,$v1,$v0
	sw	$v0,4($fp)
	lw	$v0,0($fp)
	addu	$v0,$v0,1
	sw	$v0,0($fp)
	b	$L3
$L4:
	move	$v0,$zero
	move	$sp,$fp
	lw	$fp,8($sp)
	addu	$sp,$sp,16
	j	$ra
