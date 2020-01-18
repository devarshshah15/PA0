/* screate.c - screate, newsem */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include<lab0.h>
LOCAL int newsem();

/*------------------------------------------------------------------------
 * screate  --  create and initialize a semaphore, returning its id
 *------------------------------------------------------------------------
 */
SYSCALL screate(int count)
{
	STATWORD ps;    
	int	sem;
	unsigned long start, run;
	if(syscall_track==1)	
	{
		start=ctr1000;
	}
	disable(ps);
	if ( count<0 || (sem=newsem())==SYSERR ) {
		restore(ps);
		if(syscall_track==1){
                        run = ctr1000 - start;
                        frequency_call[currpid][15]++;
                        time_call[currpid][15] = time_call[currpid][15] + run;
}

		return(SYSERR);
	}
	semaph[sem].semcnt = count;
	/* sqhead and sqtail were initialized at system startup */
	restore(ps);
	if(syscall_track==1){
                        run = ctr1000 - start;
                        frequency_call[currpid][15]++;
                        time_call[currpid][15] = time_call[currpid][15] + run;
}

	return(sem);
}

/*------------------------------------------------------------------------
 * newsem  --  allocate an unused semaphore and return its index
 *------------------------------------------------------------------------
 */
LOCAL int newsem()
{
	int	sem;
	int	i;

	for (i=0 ; i<NSEM ; i++) {
		sem=nextsem--;
		if (nextsem < 0)
			nextsem = NSEM-1;
		if (semaph[sem].sstate==SFREE) {
			semaph[sem].sstate = SUSED;
			return(sem);
		}
	}
	return(SYSERR);
}
