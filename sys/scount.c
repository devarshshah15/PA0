/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include<proc.h>
#include<lab0.h>
/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
SYSCALL scount(int sem)
{
extern	struct	sentry	semaph[];
	unsigned long start, run;
	if(syscall_track==1)
	{
		start=ctr1000;
	}
	if (isbadsem(sem) || semaph[sem].sstate==SFREE)
		return(SYSERR);
	if(syscall_track==1){
                        run = ctr1000 - start;
			frequency_call[currpid][10]++;
                        time_call[currpid][10] = time_call[currpid][10] + run;
                       
                }


	return(semaph[sem].semcnt);
}
