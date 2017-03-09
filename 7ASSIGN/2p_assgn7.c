// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #7
	
// PROBLEM    : #2

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(int sig)
{
	switch (sig)
	{
		case SIGINT:
		{
			printf("\tSIGINT occured\n");
			break;
		}
		case SIGHUP:
		{
			printf("\tSIGHUP occured\n");
			break;
		}
		case SIGTERM:
		{
			printf("\tSIGTERM occured\n");
			break;
		}
	}

	//TO KEEP THE SIGNAL HANDLER BUSY
	long long int t = 9999999;
	while(t--)
	{;}
}
void install_handler()
{
	struct sigaction action;
	sigset_t block_mask;		//CREATING BLOCK SIGNAL SET
	sigemptyset( &block_mask );	//INITIALISING IT AS AN EMPTY SET

	//ADDING NEW ENTRIES TO THE SET
	sigaddset(&block_mask,SIGINT);	
	sigaddset(&block_mask,SIGHUP);
	sigaddset(&block_mask,SIGTERM);

	//DEFINING NEW ACTION FOR THE HANDLER
	action.sa_handler = sig_handler;

	//DEFINING SA_MASK
	action.sa_mask = block_mask;

	//FLAGS
	action.sa_flags = 0;

	//USING sigaction() TO CHANGE BEHAVIOUR ON EACH OF THE FOLLOWING SIGNALS.
	if(sigaction(SIGINT,&action,NULL) || sigaction(SIGHUP,&action,NULL) || sigaction(SIGTERM,&action,NULL))
	{
		//error checking
		perror("sigaction");
		return;
	}
}
void main()
{
	pid_t pid;

	switch(pid = fork())
	{
		case -1: //fork error
			{
				perror("fork");
				break;
			}
		case 0: //CHILD
			{
				install_handler();
				sleep(20);
				printf("\tHello this is child process, PID = %d\n",getpid());
				break;
			}
		default: //PARENT
			{
				printf("This is parent process, PID = %d\n",getpid());
				printf("Which signal should be sent to child(%d)",pid);
				printf("\n\t1.SIGINT\n\t2.SIGHUP\n\t3.SIGTERM\n");
				char op = getchar();
				switch (op)
				{
					case '1':
						{
							kill(pid,SIGINT);
							break;
						}
					case '2':
						{
							kill(pid,SIGHUP);
							break;
						}
					case '3':
						{
							kill(pid,SIGTERM);
							break;
						}
				}
				int t = 99999999;
				while(t--)	
				{;}
			}
	}
}
