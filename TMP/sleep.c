/* sleep.c - sleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include<lab0.h>
/*------------------------------------------------------------------------
 * sleep  --  delay the calling process n seconds
 *------------------------------------------------------------------------
 */
SYSCALL	sleep(int n)
{
	STATWORD ps;
	unsigned long start, run;
	if(syscall_track==1)
	{
		start=ctr1000;
	}
	    
	if (n<0 || clkruns==0)
{
		if(syscall_track==1){
                        run = ctr1000 - start;
                        frequency_call[currpid][18]++;
                        time_call[currpid][18] = time_call[currpid][18] + run;
}


		return(SYSERR);
}
	if (n == 0) {
	        disable(ps);
		resched();
		restore(ps);
		if(syscall_track==1){
                        run = ctr1000 - start;
                        frequency_call[currpid][18]++;
                        time_call[currpid][18] = time_call[currpid][18] + run;
}

		return(OK);
	}
	while (n >= 1000) {
		sleep10(10000);
		n -= 1000;
	}
	if (n > 0)
		sleep10(10*n);
	if(syscall_track==1){
                        run = ctr1000 - start;
                        frequency_call[currpid][18]++;
                        time_call[currpid][18] = time_call[currpid][18] + run;
}

	return(OK);
}
