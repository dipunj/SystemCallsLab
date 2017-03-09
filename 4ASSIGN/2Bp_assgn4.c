// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #4
	
// PROBLEM    : #2-B

// CODE : -



//NOTE : THE PROGRAM EXPECTS *EXACTLY* 3 COMMAND LINE ARGUMENTS( exclusive of the ./a.out ).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	char cmd[20];
	snprintf(cmd,sizeof(cmd),"%s %s",argv[1],argv[2]);

	int fdes[2];
	if(pipe(fdes) == 0)
	{	
		pid_t pid = fork();
		if(pid == 0)
		{
			dup2(fdes[1],1);	//changing the stdout file descriptor from 1 to fdes[1] a.k.a the write end of the pipe
			close(fdes[0]);
			system(cmd);
		}
		else
		{
			dup2(fdes[0],0);	//changing the stdin file descriptor from 0 to fdes[0] a.k.a the read end of the pipe
			close(fdes[1]);
			system(argv[3]);
		}
	}
	else
		printf("Pipe error\n");

}
