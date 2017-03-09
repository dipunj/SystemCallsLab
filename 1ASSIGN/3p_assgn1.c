// LAB        :  PROGRAMMING TOOLS - II(SYSTEM CALLS)
// ASSIGNMENT :  1
//
// PROBLEM    :  #3
// 	      :  To Create a process tree consisting of 8 processes with height 3.
// CODED IN   :  C


#include <stdio.h>
#include <unistd.h>	//contains fork()
#include <sys/wait.h>	//contains wait()
#include <stdlib.h>	//contains exit()

void main()
{
	int i;
	for(i=0;i<3;i++)
	{
		fork();
		wait(0);
	}
	printf("PID = %d\n",getpid());
	exit(0);
}
