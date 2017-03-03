// NAME       : DIPUNJ GUPTA
// REG        : 20154061
// GROUP      : CSA2
// SEMESTER   : 4TH
// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #6
	
// PROBLEM    : #4

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
			printf("SIGINT occured\n");
			break;
		}
		case SIGHUP:
		{
			printf("SIGHUP occured\n");
			break;
		}
		case SIGTERM:
		{
			printf("SIGTERM occured\n");
			break;
		}
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
				signal(SIGINT,sig_handler);
				signal(SIGHUP,sig_handler);
				signal(SIGTERM,sig_handler);
			
				sleep(20);
				printf("Hello this is child process, PID = %d\n",getpid());
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
					/*default :
						{
							printf("Please choose from the above signals!!\n");
							exit(0);
						}
					*/
				}
			
	
			}
	}
}
