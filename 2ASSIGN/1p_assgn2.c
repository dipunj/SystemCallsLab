// NAME       : DIPUNJ GUPTA
// REG        : 20154061
// GROUP      : CSA2
// SEMESTER   : 4TH
// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #2
	
// PROBLEM    : #1
/* 
 * STATEMENT  : 
 * 		Write a C program to create a child process using fork() system call.
 * 		Also use wait() system call in parent process such that 
 * 		it gets the return status of is child, return status must be printed on console.
 *
 * Hint:	Use
 
		(i) WIFEXITED
		(ii) WEXITSTATUS
		(iii) WIFSIGNALED
		POSIX macros to print the exit status of child process.
*/

// CODE : -

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void main()
{
	int status;

	pid_t pid = fork();
	if( pid != 0 )		//PARENT SHALL EXECUTE IN THIS BLOCK
	{
		wait( &status );
		printf("\n-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P");
		printf("\n\nThis is PARENT'S block");
		if ( WIFEXITED(status) )
		{
			printf("\n\nChild's Termination was NORMAL.\n\tWIFEXITED returned : %d");
			printf("\nThe exit status returned by the child is :: %d\n",WEXITSTATUS(status));
		}
		else
		{
			printf("\nChild's Termination was ABNORMAL\n\n");
			printf("The value of WIFSIGNALED is :: %d\n",WIFSIGNALED(status));
		}
		printf("\n-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P-P\n");
	}
	else
	{
		//CHILD SHALL EXECUTE IN THIS BLOCK
		printf("\n-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C");
		printf("\n\nThis is CHILD'S block");
		
		char option;
		printf("\nHow do you wish to terminate the child?\n\t1. NORMALLY\n\t(Not)1. ABNORMALLY\nYour Response ::");
		if((option = getchar()) == '1')
		{
			printf("\nWhat (8 bit) value should the child return to the parent?\n");
			int op;
			scanf("%d",&op);
			printf("\n-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C");
			exit(op);
		}
		else
		{
			printf("\n-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C-C");
			abort();
		}
	}
}
