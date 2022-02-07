.data

M: .word 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
n: .word 4

.text
.globl main

main:
	addi	$sp, $sp, -4
	sw	$ra, 0($sp)
	la	$s0, M		# $s0 = &M
	la	$s1, n		# $s1 = &n
	lw	$s1, 0($s1)	# $s1 = n
	add	$a0, $0, $s0	# $a0 = &M
	add	$a1, $0, $s1	# $a1 = n
	jal	inv
	lw	$ra, 0($sp)
	addi	$sp, $sp, 4
	jr	$ra


# <- $a0 indirizzo matrice
# <- $a1 dimennsione matrice
inv:
	addi	$sp, $sp, -12
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	add	$t9, $0, $0	# $t9 = counter=0
	add	$t0, $0, $0	# $t0 = i=0
	addi	$t1, $a1, -1	# $t1 = j=n-1
for:	slt	$t2, $t9, $a1	# $t2 = i<n ? 1 : 0
	beq	$t2, $0, exit	# i>=n -> exit
	sll	$s0, $t0, 2	# $s0 = i*4
	sll	$s1, $t1, 2	# $s1 = (n-1)*4
	add	$s3, $a0, $s0	# $s3 = &M + i*4
	add	$s4, $a0, $s1	# $s4 = &M + i*4
	lw	$t3, 0($s3)	# 
	lw	$t4, 0($s4)
	sw	$t3, 0($s4)
	sw	$t4, 0($s3)
	#lw	$s3, 0($s3)	# $s3 = M[i]
	#lw	$s5, 0($s3)	# $s5 = M[i]
	#lw	$s4, 0($s4)	# $s4 = M[n-1]
	#sw	$s3, 0($s4)	# $s3 = M[n-1]
	#sw	$s4, 0($s5)	# $s4 = M[i]
	add	$t0, $t0, $a1	# i+=n
	addi	$t0, $t0, 1	# j-=1
	add	$t1, $t1, $a1	# j+=n
	addi	$t1, $t1, -1	# j-=1
	addi	$t9, $t9, 1	# counter++
	j	for
exit:	lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	addi	$sp, $sp, 12
	jr	$ra

	
