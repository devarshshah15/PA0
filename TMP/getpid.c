/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include<lab0.h>
/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
	unsigned long start, run;
	if(syscall_track==1)
	{
		start=ctr1000;
	}
	if(syscall_track==1){
                        run = ctr1000 - start;
                        time_call[currpid][2] = time_call[currpid][2] + run;
                        frequency_call[currpid][2]++;
                }


	return(currpid);
}
