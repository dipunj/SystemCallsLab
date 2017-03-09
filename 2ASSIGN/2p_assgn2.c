// SEMESTER   : 4TH
// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #2
	
// PROBLEM    : #2
// STATEMENT  : Write a program in C to demonstrate Zombie processes.
// 		Create an orphan process to distinguish between them.


// CODE : -

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main()
{
	printf("P.S. :: View the processes created by a.out from another tty using the command :: ps -vf\n\n");
	pid_t pid = fork();
	if( pid > 0 )
	{
		printf("This is PARENT'S block,PID = %d...Sleeping for 10s\n",getpid());
		sleep(10);
	}
	else
	{
		printf("This is CHILD'S block,PID = %d",getpid());
		exit(0);
	}

	printf("Now creating orphan\n");
	pid = fork();
	if(pid > 0)
		printf("This is PARENT'S block,PID = %d\n",getpid());
	else
	{
		sleep(1);
		printf("This is ORPHAN CHILD'S block,PID = %d,press a key to exit",getpid());
		getchar();
	}
}

