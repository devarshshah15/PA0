#include<stdio.h>
static unsigned long *esp,*ebp;
void printtos()
{
        kprintf("\nvoid printtos()\n");
	asm("movl %esp, esp");
	asm("movl %ebp, ebp");
	kprintf("Before[0x%08x]: 0x%08x",ebp+2,*(ebp+2));
	kprintf("\nAfter[0x%08x]: 0x%08x\n",ebp,*(ebp));
	int j;
	for(j=0;j<4;j++)
	{
		kprintf("\telement[0x%08x]: 0x%08x\n",esp+j,*(esp+j));
	}
	kprintf("\n\n");

}
		


