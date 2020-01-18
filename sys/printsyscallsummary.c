#include<conf.h>
#include<kernel.h>
#include<proc.h>
#include<stdio.h>
#include<lab0.h>

int frequency_call[NPROC][27];
int time_call[NPROC][27];
int syscall_track=1;

char mapping_syscall[27][21]={"syscall_freemen","syscall_chprio","syscall_getpid","syscall_getprio","syscall_gettime","syscall_kill","syscall_receive","syscall_recvclr","syscall_recvtim","syscall_resume","syscall_scount","syscall_sdelete","syscall_send","syscall_setdev","syscall_setnok","syscall_screate","syscall_signal","syscall_signaln","syscall_sleep","syscall_sleep10","syscall_sleep100","syscall_sleep1000","syscall_sreset","syscall_stacktrace","syscall_suspend","syscall_unsleep","syscall_wait"};

void syscallsummary_start()
{
	int i=0,j=0;
	for(i=0;i<NPROC;i++)
	{
		for(j=0;j<27;j++)
		{
			frequency_call[i][j]=0;
		}
	}
	for(i=0;i<NPROC;i++)
        {
                for(j=0;j<27;j++)
                {
                        time_call[i][j]=0;
                }
        }
	syscall_track=1;
}

void syscallsummary_stop()
{
	syscall_track=0;
}

void printsyscallsummary()
{
	int i=0,j=0;
	kprintf("\nvoid printsyscallsummary()\n");
	for(i=0;i<NPROC;i++)
	{
		int temp=1;
		for(j=0;j<27;j++)
		{
		if(frequency_call[i][j]>0)
		{
			if(temp==1)
			{
			kprintf("Process [pid:%d]\n",i);
			temp=0;
			}
			kprintf("\tSyscall: %s, count: %d, average execution time: %d (ms)\n",mapping_syscall[j],frequency_call[i][j],time_call[i][j]/frequency_call[i][j]);
		}
	}
}
}
	
	
