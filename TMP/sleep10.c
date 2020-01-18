/* sleep10.c - sleep10 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include<lab0.h>
/*------------------------------------------------------------------------
 * sleep10  --  delay the caller for a time specified in tenths of seconds
 *------------------------------------------------------------------------
 */
SYSCALL	sleep10(int n)
{
	STATWORD ps;
	unsigned long start, run;
	if(syscall_track==1)
	{
		start=ctr1000;
	}    
	if (n < 0  || clkruns==0)
	{
			if(syscall_track==1){
                        run = ctr1000 - start;
			frequency_call[currpid][19]++;
                        time_call[currpid][19] = time_call[currpid][19] + run;
}

	         return(SYSERR);
}
	disable(ps);
	if (n == 0) {		/* sleep10(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n*100);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);
	if(syscall_track==1){
                        run = ctr1000 - start;
                        frequency_call[currpid][19]++;
                        time_call[currpid][19] = time_call[currpid][19] + run;
}

	return(OK);
}
