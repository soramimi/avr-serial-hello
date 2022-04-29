
	.text

.global	waitloop
	.type	waitloop, @function
waitloop:
	nop
	nop
	nop
	nop
	sbiw r24,1
	brne waitloop
	ret


