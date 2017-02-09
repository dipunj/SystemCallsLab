// NAME       : DIPUNJ GUPTA
// REG.       : 20154061
// GROUP      : CS-A2
// SEMESTER   : 4TH
// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #2
	


// PROBLEM    : #3

/* STATEMENT  : Use fork-exec combination where child exec the new program while parent continue to execute
 * 		the original code.
 * 		The new program here is ls command with command-line argument -l.
		
 * EXTENSION  : Execute your code from a directory that has lot of files ( e.g /etc) 
 * 		and execute ls -l command. 
 * 		What happens if you enter ctrl+c as soon as the listing start to display.
 * 		Try to display the exit status of child process as it has been interrupted by ctrl+c.
*/


// CODE : -



// On sending the SIGINT i.e ctrl+c , the program continues to run and ignores the SIGINT
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

char * argv[] = {"/bin/ls","-l",0,0};
char *temp[100];
void main()
{
	int i,status;
	pid_t pid;

	printf("Input the absolute-directory name to be used for EXTENDED-VERSION OF Q3\n");
	scanf("%s",&temp);
	argv[2]=temp;

	if ((pid = fork()) >  0 )
	{
		wait(&status);
		int i;
		for(i=0;i<100;i++)
			printf("This is parent's block...it shall be printing for 100 times\n");
		if(WIFEXITED(status))
			printf("NORMAL TERMINATION :: The value returned by the child is :: %d\n",WEXITSTATUS(status));
		else
			printf("ABNORMAL TERMINATION :: The value returned by the child is :: %d\n",WIFSIGNALED(status));
	}
	else
	{
		if ( pid ==  0 )
		{
			execv(argv[0],argv);
			printf("exec-error\n");
			exit(1);
		}
		else
		{
			printf("fork() error");
			exit(1);
		}
	}
}
