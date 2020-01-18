/* user.c - main */
#include<conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
int prX;
void halt();
prch(c)
char c;
{
	int i;
	sleep(5);	
}
int main()
{
	kprintf("\n");
	printsegaddress();
	printtos();
	printprocstks(10);
	syscallsummary_start();
	resume(create(prch,2000,20,"proc X",1,'A'));
	sleep(10);
	syscallsummary_stop();
	printsyscallsummary();
	return 0;
}
