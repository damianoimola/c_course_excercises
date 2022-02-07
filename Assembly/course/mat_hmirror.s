
.data

M: .word 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16# 3x3
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
	add	$t9, $0, $0	# $t9 = counter=0
	add	$t0, $0, $0	# $t0 = j=0
	srl	$t1, $s1, 1	# $t1 = ceil(n/2) = mid
	addi	$s1, $s1, -1	# n=n-1

for2:	slt	$t2, $t9, $t1	# $t9 = j<mid ? 1 : 0
	beq	$t2, $0, exit2	# i>=mid -> exit2
	
	sll	$t3, $t0, 2	# $t3 = j*4
	sll	$t4, $s1, 2	# $t4 = (n-1)*4
	add	$t3, $s0, $t3	# &B[i] + j*4
	add	$t4, $s0, $t4	# &B[i] + n*4
	
	lw	$s3, 0($t3)	# $t3 = B[i][j]
	lw	$s4, 0($t4)	# $t4 = B[i][n-1]
	sw	$s3, 0($t4)	# B[i][j] = B[i][n-1]
	sw	$s4, 0($t3)	# B[i][n] = B[i][j]
	addi	$t9, $t9, 1	# counter++
	addi	$t0, $t0, 1	# j++
	addi	$s1, $s1, -1	# n--
	
	j	for2
exit2:	lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
	addi	$sp, $sp, 16
	jr	$ra

	
	

