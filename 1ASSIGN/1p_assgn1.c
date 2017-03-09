// SEMESTER   :  IVth
// LAB        :  PROGRAMMING TOOLS - II(SYSTEM CALLS)
// ASSIGNMENT :  1
//
// PROBLEM    :  #1
// 	      :  To Demonstrate usage of fork(). To use wait() in parent's block.
// CODED IN   :  C

#include <stdio.h>
#include <unistd.h>	//contains fork()
#include <sys/wait.h>	//contains wait()
#include <stdlib.h>	//contains exit()

void main()
{
	pid_t pid = fork();
	if(pid != 0)						//this block shall only be executed when fork returns a non 0(child's PID) TO THE PARENT
	{							//on succesful creation of a child process
		wait(0);
		printf("\nThis is PARENT BLOCK");
		printf("\n\t* MY PID          = %d",getpid());
		printf("\n\t* MY CHILD'S PID  = %d",pid);
		printf("\n\t* MY OWNER'S PID  = %d\n\n",getppid());
	}
	else							//this block shall only be executed when fork() returns a 0 value(to the CHILD)
	{
		printf("\nTHIS IS CHILD'S BLOCK");
		printf("\n\t* MY PARENT'S PID = %d",getppid());
		printf("\n\t* MY PID          = %d\n",getpid());
		exit(0);
	
	}
}
