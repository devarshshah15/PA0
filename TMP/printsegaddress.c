#include<stdio.h>
extern int etext,edata,end;
void printsegaddress()
{
	kprintf("void printsegaddress()\n\n");
	kprintf("Current:");
	kprintf(" etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x",&etext,etext,&edata,edata,&end,end);
	kprintf("\nPreceding:");
	kprintf(" etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x",&etext-1,*(&etext-1),&edata-1,*(&edata-1),&end-1,*(&end-1));
	kprintf("\nAfter:");
	kprintf(" etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x",&etext+1,*(&etext+1),&edata+1,*(&edata+1),&end+1,*(&end+1));
	kprintf("\n");
}
	
