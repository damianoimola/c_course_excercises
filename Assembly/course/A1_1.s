

main:
	lw	$s0, X				# $s0=x=X
	lw	$s1, Y				# $s1=y=Y
	slt	$t0, $s0, $s1			# if($s0<$s1)=if(x<y) -> $t0=1
	bne	$t0, $zero, COND		# $t0 = (x>=y)
	lw	$t1, $s0			# $t1=min(x,y)= x = $s0
RESUME:	
	addi	$t1, $t1, 1			# min=min+1
	sub	$s0, $s0, $t2			# x=x-(min{x,y}+1)
	sw	$s0, $v0			# $v0 = x = $s0
	j	EXIT
COND:
	lw	$t1, $s1			# $t1=min(x,y) = y = $s1
	j	RESUME				# incond. jump to RESUME
		
EXIT	...
	
