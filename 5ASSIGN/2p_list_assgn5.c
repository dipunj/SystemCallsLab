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
	// To store directory name, if user enters it.
	char dir_name[50] = {'\0'};
	dir_name[0] = '.'; // default directory

	printf("LIST : Initiating a named pipe\n");

	mknod("mypipe",S_IFIFO|0666,0);
	printf("LIST : Waiting for SORT to begin\n");

	// file descriptor to "mypipe"
	int fd_write = open("mypipe",O_WRONLY);	
	
	printf("Enter a directory name for ls command to take \n(default : pwd, to skip this press (ctrl+D)) :: ");
	scanf("%s",dir_name);
	
	// changing STDOUT's file descriptor to fd_write
	dup2(fd_write,1);

	//changing process image to ls
	execl("/bin/ls","/bin/ls","-l",dir_name,NULL);
}
