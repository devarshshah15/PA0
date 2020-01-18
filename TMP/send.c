/* send.c - send */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include<lab0.h>
/*------------------------------------------------------------------------
 *  send  --  send a message to another process
 *------------------------------------------------------------------------
 */
SYSCALL	send(int pid, WORD msg)
{
	STATWORD ps;    
	struct	pentry	*pptr;
	unsigned long start, run;
	if(syscall_track==1)
	{
		start=ctr1000;
	}
	disable(ps);
	if (isbadpid(pid) || ( (pptr= &proctab[pid])->pstate == PRFREE)
	   || pptr->phasmsg != 0) {
		restore(ps);
		if(syscall_track==1){
                        run = ctr1000 - start;
                        time_call[currpid][12] = time_call[currpid][12] + run;
                        frequency_call[currpid][12]++;
                }


		return(SYSERR);
	}
	pptr->pmsg = msg;
	pptr->phasmsg = TRUE;
	if (pptr->pstate == PRRECV)	/* if receiver waits, start it	*/
		ready(pid, RESCHYES);
	else if (pptr->pstate == PRTRECV) {
		unsleep(pid);
		ready(pid, RESCHYES);
	}
	restore(ps);
	if(syscall_track==1){
                        run = ctr1000 - start;
                        time_call[currpid][12] = time_call[currpid][12] + run;
                        frequency_call[currpid][12]++;
                }


	return(OK);
}
