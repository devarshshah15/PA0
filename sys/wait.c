/* wait.c - wait */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include<lab0.h>
/*------------------------------------------------------------------------
 * wait  --  make current process wait on a semaphore
 *------------------------------------------------------------------------
 */
SYSCALL	wait(int sem)
{
	STATWORD ps;    
	struct	sentry	*sptr;
	struct	pentry	*pptr;
	unsigned long start, run;
	if(syscall_track==1)
	{
		start=ctr1000;
	}
	
	disable(ps);
	if (isbadsem(sem) || (sptr= &semaph[sem])->sstate==SFREE) {
		restore(ps);
		if(syscall_track==1){
                        run = ctr1000 - start;
                        frequency_call[currpid][26]++;
                        time_call[currpid][26] = time_call[currpid][26] + run;
}

		return(SYSERR);
	}
	
	if (--(sptr->semcnt) < 0) {
		(pptr = &proctab[currpid])->pstate = PRWAIT;
		pptr->psem = sem;
		enqueue(currpid,sptr->sqtail);
		pptr->pwaitret = OK;
		resched();
		restore(ps);
		if(syscall_track==1){
                        run = ctr1000 - start;
                        frequency_call[currpid][26]++;
                        time_call[currpid][26] = time_call[currpid][26] + run;
}

		return pptr->pwaitret;
	}
	restore(ps);
	if(syscall_track==1){
                        run = ctr1000 - start;
                        frequency_call[currpid][26]++;
                        time_call[currpid][26] = time_call[currpid][26] + run;
}

	return(OK);
}
