// NAME       : DIPUNJ GUPTA
// REG        : 20154061
// GROUP      : CSA2
// SEMESTER   : 4TH
// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #6
	
// PROBLEM    : #3

// CODE : -

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

int status;
void sig_handler(int sig)
{
	printf("This is the CUSTOM signal handler\n");
	if ( WIFEXITED(status) )
	{
		printf("Child's Termination was NORMAL.\n");
		printf("The exit status returned by the child is :: %d\n",WEXITSTATUS(status));
	}
	else
		printf("Child's Termination was ABNORMAL\n");

}

int main()
{
	signal(SIGCHLD,sig_handler);
	
	pid_t pid = fork();
	if( pid != 0 )		//PARENT SHALL EXECUTE IN THIS BLOCK
	{
		wait( &status );
		printf("\nThis is PARENT'S process\n");
	}
	else
	{
		//CHILD SHALL EXECUTE IN THIS BLOCK
		printf("\n\nThis is CHILD'S process");
		
		char option;
		printf("\nHow do you wish to terminate the child?\n\t1. Normally\n\t2. Abnormally\nYour Response ::");
		if((option = getchar()) == '1')
		{
			printf("\nWhat (8 bit) value should the child return to the parent? :: ");
			int op;
			scanf("%d",&op);
			kill( getppid(), SIGCHLD);
			exit(op);
		}
		else
			abort();	//abnormal termination
	}
}
