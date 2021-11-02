

# $s0 = &V[0]
# $s1 = N

main:
	add	$t9, $zero, $zero			# $t9= flag = 0
	add	$t0, $zer0, $zero			# $t0= i=0
	addi	$t0, $t0, 1				# $t0= i=1
	add	$t1, $zero, $zero			# $t1= offset (i*4)
	add	$s2, $s1, $zero				# $s2= $s1 = &V[0]

FOR:
	slt	$t2, $t0, $s1				# $t2 = if(t<n) -> $t0 = 1
	beq	$t2, $zero, HANDLE			# t>=n
	lw	$s3, 0($s2)				# $s3 = V[offset]	(prev element, using previous current element)
	sll	$t1, $t0, 2				# offset = i*4 		(current offset)
	add	$s2, $s0, $t1				# $s2 = &V[0] + offset	(go to current array element mem addr)
	lw	$s4, 0($s2)				# $s4 = V[offset]	(current element)
	slt	$t3, $s3, $s4				# $t0= if(V[i-1]<V[i]) -> $t0=1
	bne	$t3, $zer0, SET				# V[i-1]>=V[i]
	addi	$t0, $t0, 1				# i=i+1
	j	FOR					# incond. jump ot FOR

SET:
	addi	$t9, $t9, 1				# $t9 = 1
	j	HANDLE					# incond. jump to HANDLE

HANDLE:
	bne	$t9, $zero, UNORDERED			# unordered list
	# do something so tat that array is ORDERED
	j	EXIT

UNORDERED:
	# do something to say that array is UNORDERED
	j	EXIT



EXIT: ...














