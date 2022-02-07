.data

M: .word 1 2 3 4 5 6 7 8 9 10 11 12
n: .word 4
.text
.globl main

main:
.data

M: .word 1 2 3 4 5 6 7 8 9 10 11 12
n: .word 4
.text
.globl main

main:
	add	$sp, $sp, -4
	sw	$ra, 0($sp)
	la	$a0, M
	la	$a1, n
	lw	$a1, 0($s1)
	add	$a2, $0, $0
	jal	proc
	sw	$ra, 0($sp)
	add	$sp, $sp, -4
	jr $ra


# <- $a0 indirizzo matrice
# <- $a1 dimensione
# <- $a2 indice corrente
procmat:
	add	$sp, $sp, -16
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	sw	$s2, 12($sp)
	beq	$a1, $a2, ret1		# può essere messo all'inizio della funzione (+ ottimizzata)
	add	$s0, $0, $a0		# $s0 = &M
	add	$s1, $0, $a1		# $s1 = n
	add	$s2, $0, $a2		# $s2 = indice
	addi	$t0, $0, 4		# $t0 = 4
	mult	$s1, $t0		# $Lo = n*4
	mflo	$t0			# $t0 = n*4
	add	$a0, $s0, $t0		# $a0 = &M+(n*4)
	add	$s1, $0, $0		# $a1 = 0
	add	$a2, $0, $s1		# $a2 = n
	jal	procrow			# procrow(&M+(n*4), n)
	addi	$a2, $s2, 1		# indice++
	jal	procmat			# procmat(&M+(n*4), n)
ret1:	lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
	add	$sp, $sp, 16
	jr	$ra


# <- $a0 indirizzo riga
# <- $a1 indice inizio
# <- $a2 indice fine
procrow:
	add	$sp, $sp, -16
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	sw	$s2, 12($sp)
	addi	$t0, $s2, 4		# $t0 = end index + 4
	slt	$t0, $s1, $t0		# $t0 = start index < end index + 4 = 1 : 0  # condizione START<=END (per interi)
	beq	$t0, $0, ret2 		# start index >= end index -> ret2
	add	$s0, $0, $a0		# $s0 = &M[i][0]
	add	$s1, $0, $a1		# $s1 = start index
	add	$s2, $0, $a2		# $s2 = end index
	add	$s3, $s0, $s1		# $s3 = &M + start index
	add	$s4, $s0, $s3		# $s4 = &M + end index
	lw	$t3, 0($s3)		# $t3 = M[start index]
	lw	$t4, 0($s4)		# $t4 = M[end index]
	sw	$t3, 0($s4)		# M[end index] = M[start index]
	sw	$t4, 0($s3)		# M[start index] = M[end index]
	add	$a0, $0, $s0		# $a0 = &M[i][0]
	addi	$a1, $s1, 4		# start index++
	addi	$a2, $s2, 4		# end index++
	jal	procrow
ret2:	lw	$ra, 0($sp)
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
	add	$sp, $sp, 16
	jr	$ra

	














