// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #4
	
// PROBLEM    : #2-A

// CODE : -

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
			close(1);		//close STDOUT
			fdes[1] = dup(fdes[1]);	//As the lowest available file descriptor is 1 so fdes[1] now is same as STDOUT
			close(fdes[0]);
			execl("/bin/ls","/bin/ls","-l",NULL);	// add a 3rd arg with directory of your choice
		}
		else
		{
			close(0);		// close STDIN
			fdes[0] = dup(fdes[0]);	//As the lowest available file descriptor is 0 so fdes[1] now is same as STDIN
			close(fdes[1]);
			execl("/bin/sort","/bin/sort",NULL);
		}
	}
	else
		printf("Pipe error\n");

}
