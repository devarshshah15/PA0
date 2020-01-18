/* signal.c - signal */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include<lab0.h>
/*------------------------------------------------------------------------
 * signal  --  signal a semaphore, releasing one waiting process
 *------------------------------------------------------------------------
 */
SYSCALL signal(int sem)
{
	STATWORD ps;    
	register struct	sentry	*sptr;
	unsigned long start, run;
	if(syscall_track==1)
	{
		start=ctr1000;
	}
	disable(ps);
	if (isbadsem(sem) || (sptr= &semaph[sem])->sstate==SFREE) {
		if(syscall_track==1){
                        run = ctr1000 - start;
                        time_call[currpid][16] = time_call[currpid][16] + run;
}

		restore(ps);
		return(SYSERR);
	}
	if ((sptr->semcnt++) < 0)
		ready(getfirst(sptr->sqhead), RESCHYES);
	if(syscall_track==1){
                        run = ctr1000 - start;
                        frequency_call[currpid][16]++;
                        time_call[currpid][16] = time_call[currpid][16] + run;
}

	restore(ps);
	return(OK);
}
