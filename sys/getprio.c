/* getprio.c - getprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include<lab0.h>

/*------------------------------------------------------------------------
 * getprio -- return the scheduling priority of a given process
 *------------------------------------------------------------------------
 */
SYSCALL getprio(int pid)
{
	STATWORD ps;    
	struct	pentry	*pptr;
	unsigned long start, run;
	if(syscall_track==1)
	{
		start=ctr1000;
	}
	disable(ps);
	if (isbadpid(pid) || (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		if(syscall_track==1){
                        run = ctr1000 - start;
                        time_call[currpid][3] = time_call[currpid][3] + run;
                        frequency_call[currpid][3]++;
                }


		return(SYSERR);
	}
	restore(ps);
	if(syscall_track==1){
                        run = ctr1000 - start;
                        time_call[currpid][3] = time_call[currpid][3] + run;
                        frequency_call[currpid][3]++;
                }
	return(pptr->pprio);
}
