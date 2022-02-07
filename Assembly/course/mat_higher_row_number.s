.data

M: .word 1 2 3 4 5 6 7 8 9 10 11 12 # 3x3
n: .word 4

.text
.globl main

main:
	add	$sp, $sp, -4
	sw	$ra, 0($sp)
	la	$s0, M		# $s0 = &M
	la	$s1, n		# $s1 = &n
	lw	$s1, 0($s1)	# $s1 = n
	add	$a0, $0, $s0	# $a0 = &M
	add	$a1, $0, $s1	# $a1 = n
	jal	proc1
	lw	$ra, 0($sp)
	add	$sp, $sp, 4
	jr 	$ra

# $a0 <- indirizzo M
# $a1 <- grandezza M
proc1:
	add	$sp, $sp, -12
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	add	$s0, $0, $a0	# $s0 = &M
	add	$s1, $0, $a1	# $s1 = n
	add	$s2, $0, $0	# $s2 = i = 0
for1:	slt	$t1, $s2, $a1	# $t1 = i<n ? 1 : 0
	beq	$t1, $0, exit1	# i>=n -> exit1
	add	$a0, $0, $s0	# $a0 = &M[i]
	add	$a1, $0, $s1	# $a1 = n
	jal	proc2
	addi	$s2, $s2, 1	# i++
	addi	$t2, $0, 4	# $t2 = 4
	mult	$t2, $s1	# $Lo = n*4
	mflo	$t2
	#mult	$t2, $s2	# $Lo = (n*4)*i
	#mflo	$t2
	add	$s0, $s0, $t2	# $s0 = &M[i][0]
	j	for1	
exit1:	lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	addi	$sp, $sp, 12
	jr	$ra


# $a0 <- indirizzo i-esima riga (B)
# $a1 <- elementi nella riga
proc2: # leaf
	add	$sp, $sp, -16
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	sw	$s2, 12($sp)
	add	$s0, $0, $a0	# $s0 = &B[i]
	add	$s1, $0, $a1	# $s1 = n
	addi	$s2, $0, 1	# $s2 = j = 1
	lw	$s3, 0($s0)	# $s3 = max = B[i][0]
	addi	$s5, $s0, 4	# $s5 = &B+4
for2:	slt	$t0, $s2, $s1	# $t0 = j<n ? 1 : 0
	beq	$t0, $0, exit2  # j>=n -> exit2
	lw	$s4, 0($s5)	# $s4 = B[i][j]
	slt	$t1, $s3, $s4	# $t1 = max<B[i][j] = 1 : 0
	beq	$t1, $0, inc2	# max>=B[i][j] -> inc2
	add	$s3, $0, $s4	# max = B[i][j]
	j	inc2
inc2:	addi	$s5, $s5, 4	# &B+4
	addi	$s2, $s2, 1	# i++
	j	for2
exit2:	sw	$s3, 0($s0)	# B[i][0] = max
	lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
	addi	$sp, $sp, 16
	jr	$ra

	
	

