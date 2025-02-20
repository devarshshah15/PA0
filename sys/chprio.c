/* chprio.c - chprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <stdio.h>
#include<lab0.h>
/*------------------------------------------------------------------------
 * chprio  --  change the scheduling priority of a process
 *------------------------------------------------------------------------
 */
SYSCALL chprio(int pid, int newprio)
{
	STATWORD ps;    
	struct	pentry	*pptr;
	unsigned long start,run;
	if(syscall_track==1)
	{
		start=ctr1000;
	}
	disable(ps);
	if (isbadpid(pid) || newprio<=0 ||
	    (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		if(syscall_track==1){
                        run = ctr1000 - start;
                        time_call[currpid][1] = time_call[currpid][1] + run;
                        frequency_call[currpid][1]++;
                }


		return(SYSERR);
	}
	pptr->pprio = newprio;
	restore(ps);
	if(syscall_track==1){
                        run = ctr1000 - start;
                        time_call[currpid][1] = time_call[currpid][1] + run;
                        frequency_call[currpid][1]++;
                }


	return(newprio);
}
