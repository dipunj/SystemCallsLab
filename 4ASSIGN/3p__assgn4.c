// SEMESTER   : 4TH
// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #4
	
// PROBLEM    : #3

// CODE : -

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
	int fdes[2];
	if(pipe(fdes) == 0)
	{	
		pid_t pid = fork();
		if(pid == 0)
		{
			char temp[20];
			close(fdes[0]);
			printf("Enter the command for which man page is required\n");
			scanf("%s",temp);
			write(fdes[1],temp,strlen(temp));
		}
		else
		{
			wait(0);
			char buff[20] = {'\0'};
			close(fdes[1]);
			int length = read(fdes[0],buff,sizeof(buff));
			execl("/usr/bin/xterm","/usr/bin/xterm","-e","man",buff,NULL);
		}
	}
	else
		printf("Pipe error\n");

}
