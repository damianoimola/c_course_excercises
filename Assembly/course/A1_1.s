

.data
X: .word 10
Y: .word 5

.text
.globl main

main:
	la	$s0, X				# $s0=&X
	lw	$s0, 0($s0)			# $s0=X
	la	$s1, Y				# $s1=&Y
	lw	$s1, 0($s1)			# $s1=Y

	slt	$t0, $s0, $s1			# if($s0<$s1)=if(x<y) -> $t0=1
	beq	$t0, $zero, cond		# $t0 = (x>=y)
	add	$t1, $zero, $s0			# $t1=min(x,y)= x = $s0
	j	resume				# incond. jump to resume

resume:	
	addi	$t1, $t1, 1			# min=min+1
	sub	$s2, $s0, $t1			# x=x-(min{x,y}+1)
	#add	$s0, $zero, $v0			# $v0 = x = $s0
	j	exit

cond:
	add	$t1, $zero, $s1			# $t1=min(x,y) = y = $s1
	j	resume				# incond. jump to RESUME
		
exit:	jr	$ra				# return
	
