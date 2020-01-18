/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include<proc.h>
#include<lab0.h>
extern int getutim(unsigned long *);

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
    unsigned long start, run;
    if(syscall_track==1)
    {
	start=ctr1000;
    }
	

    /* long	now; */

	/* FIXME -- no getutim */

    if(syscall_track==1){
                        run = ctr1000 - start;
                        time_call[currpid][4] = time_call[currpid][4] + run;
                        frequency_call[currpid][4]++;
                }


    return OK;
}
