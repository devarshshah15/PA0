/* receive.c - receive */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include<lab0.h>
/*------------------------------------------------------------------------
 *  receive  -  wait for a message and return it
 *------------------------------------------------------------------------
 */
SYSCALL	receive()
{
	STATWORD ps;    
	struct	pentry	*pptr;
	unsigned long start,run;
	if(syscall_track==1)
	{
		start=ctr1000;
	}
	WORD msg;
	disable(ps);
	pptr = &proctab[currpid];
	if ( !pptr->phasmsg ) {		/* if no message, wait for one	*/
		pptr->pstate = PRRECV;
		resched();
	}
	msg = pptr->pmsg;		/* retrieve message		*/
	pptr->phasmsg = FALSE;
	restore(ps);
	if(syscall_track==1){
                        run = ctr1000 - start;
                        time_call[currpid][6] = time_call[currpid][6] + run;
                        frequency_call[currpid][6]++;
                }


	return(msg);
}
