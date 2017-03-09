// SEMESTER   :  IVth
// LAB        :  PROGRAMMING TOOLS - II(SYSTEM CALLS)
// DATE       :  FEB 9TH, 2017
// ASSIGNMENT :  5
//
// PROBLEM    :  #2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main()
{
	printf("SORT : Waiting for LIST\n");
	printf("SORT : The sorted output is::\n");
	mknod("mypipe",S_IFIFO|0666,0);

	int fd_read = open("mypipe",O_RDONLY);
	
	// changing STDIN's file descriptor to fd_read
	dup2(fd_read,0);

	//changing process image to sort
	execl("/bin/sort","/bin/sort",NULL);
}
