#include<kernel.h>
#include<proc.h>
#include<stdio.h>
#include<lab0.h>


static unsigned long *esp;

void printprocstks(int priority)
{
	kprintf("\nvoid printprocstks(int %d)",priority);
	struct pentry *temp;
	int id;
	for(id=0;id<NPROC;id++)
	{
		temp=&proctab[id];
		if(temp->pstate!=PRFREE && temp->pprio > priority)
		{
			kprintf("\n");
			kprintf("Process [%s]\n", temp->pname);
			kprintf("\tpid: %d\n",id);
			kprintf("\tpriority: %d\n",temp->pprio);
			kprintf("\tbase: 0x%08x\n", temp->pbase);
			kprintf("\tlimit: 0x%08x\n",temp->plimit);
			kprintf("\tlen: %d\n",temp->pstklen);
			if(id==currpid)
			{
				asm("movl %esp,esp");
				kprintf("\tpointer: 0x%08x\n",esp);
			}
			else
			{
				kprintf("\tpointer: 0x%08x\n",temp->pesp);
			}
		}
	}
}
