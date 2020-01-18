.global zfunction
zfunction:
	pushl %ebp
	movl %esp,%ebp
	movl 8(%ebp),%eax 
	andl $0xFF803FFF,%eax 
	shll $0x4,%eax 
	popl %ebp
	ret

