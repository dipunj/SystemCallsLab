// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #4
	
// PROBLEM    : #1

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
		if(pid != 0)
		{
		//parent block
			printf("THIS IS PARENT BLOCK\n");

			char buff[15] = "Hello World\n";

			printf("Message sent :: %s\n",buff);
			write(fdes[1],buff,sizeof(buff));
		}
		else
		{
		// Child block
		// NOTE :: Child cannot access buff, as it is declared for parent only.
			
			printf("THIS IS CHILD BLOCK\n");
			char arr[20];
			
			// CHILD PROCESS READS FROM THE READ END OF THE PIPE INTO THE arr[].
			ssize_t length = read(fdes[0],arr,100);
			
			//THEN WRITES TO THE STDOUT(FD == 1)
			write(1,arr,length);
		}
	}
	else
		printf("Fork Error...\n");

	return 0;
}
