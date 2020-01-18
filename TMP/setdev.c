/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include<lab0.h>
/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */
SYSCALL	setdev(int pid, int dev1, int dev2)
{
	short	*nxtdev;
	unsigned long start, run;
	if(syscall_track==1)
	{
	start=ctr1000;
	}
	if (isbadpid(pid))
		if(syscall_track==1){
                        run = ctr1000 - start;
                        frequency_call[currpid][13]++;
                        time_call[currpid][13] = time_call[currpid][13] + run;
}

		return(SYSERR);
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;
	if(syscall_track==1){
                        run = ctr1000 - start;
                        frequency_call[currpid][13]++;
                        time_call[currpid][13] = time_call[currpid][13] + run;
}

	return(OK);
}
