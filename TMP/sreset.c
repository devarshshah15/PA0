/* sreset.c - sreset */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include<lab0.h>
/*------------------------------------------------------------------------
 *  sreset  --  reset the count and queue of a semaphore
 *------------------------------------------------------------------------
 */
SYSCALL sreset(int sem, int count)
{
	STATWORD ps;    
	struct	sentry	*sptr;
	int	pid;
	int	slist;
	unsigned long start, run;
	if(syscall_track==1)
	{
		start=ctr1000;
	}
	disable(ps);
	if (isbadsem(sem) || count<0 || semaph[sem].sstate==SFREE) {
		restore(ps);
		if(syscall_track==1){
                        run = ctr1000 - start;
			frequency_call[currpid][22]++;
                        time_call[currpid][22] = time_call[currpid][22] + run;
}

		return(SYSERR);
	}
	sptr = &semaph[sem];
	slist = sptr->sqhead;
	while ((pid=getfirst(slist)) != EMPTY)
		ready(pid,RESCHNO);
	sptr->semcnt = count;
	resched();
	restore(ps);
	if(syscall_track==1){
                        run = ctr1000 - start;
                        frequency_call[currpid][22]++;
                        time_call[currpid][22] = time_call[currpid][22] + run;
}

	return(OK);
}
