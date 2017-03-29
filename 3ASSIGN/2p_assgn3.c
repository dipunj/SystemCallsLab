// LAB         : PROGRAMMING TOOLS - II
// DATE        : JAN 12, 2017
// ASSGIGNMENT : #3
// PROBELM     : #2

// STATEMENT   : Write a c program which reads a file in reverse using lseek system call

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
void main()
{	
	// opening the file descriptors for input and output file
	int i,infd = open("/etc/passwd",O_RDONLY);

	// Moving the read pointer to the end of the file
	// returned value is equal to the file size + 1
	int fp = lseek(infd,0,SEEK_END);
	
	//Declaring the buffer size to be equal to 1
	char buf;

	//Restoring the read pointer to the beginning of the file
	lseek(infd,0,SEEK_SET);

	for(i = fp - 1; i>=0 ; i--)
	{
		lseek(infd,(off_t)i,SEEK_SET);
		ssize_t fileread = read(infd,&buf,1);
		write(1,&buf,fileread);
	}
}
