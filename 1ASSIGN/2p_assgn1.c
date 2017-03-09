// LAB        :  PROGRAMMING TOOLS - II(SYSTEM CALLS)
// ASSIGNMENT :  1
//
// PROBLEM    :  #2
// 	      :  Write a Program to create a chain of 5 processes
// CODED IN   :  C

#include <stdio.h>
#include <unistd.h>	//contains fork()
#include <sys/wait.h>	//contains wait()
#include <stdlib.h>	//contains exit()

void main()
{
	pid_t pid = fork();
	if( pid != 0 )
	{
		wait(0);
		printf("PID = %d\n",getpid());
	}
	else
	{
		fork();wait(0);
		fork();wait(0);
		printf("PID = %d\n",getpid());
		exit(0);
	}
}
