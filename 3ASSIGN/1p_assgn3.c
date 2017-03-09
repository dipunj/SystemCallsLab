// LAB  	: PROGRAMMING TOOLS - II
// DATE 	: JAN 12, 2017
// ASSGIGNMENT  : #3
// PROBLEM      : #1
// STATEMENT    : Write a c program which copies the file  /etc/passwd to passwd.bak in the user's current directory.
// 		  The source file is opened in read only mode.The destination file is opened in the write mode.
// 		  Also find the file descriptor values for each file open. Print all the content of file on standard output .


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
void main()
{
	// opening the file descriptors for input and output file
	int outfd = open("password.bak",O_RDWR|O_CREAT,S_IRWXU);
	int infd = open("/etc/passwd",O_RDONLY);

	// Moving the read pointer to the end of the file
	// returned value is equal to the file size
	int fp = lseek(infd,0,SEEK_END);
	
	//Declaring the buffer size to be exactly equal to the file size
	//specified by the infd file descriptor
	char buf[fp];

	//Restoring the read pointer to the beginning of the file
	lseek(infd,0,SEEK_SET);


	//reading the file specified by the infd file descriptor
	ssize_t fileread = read(infd,buf,sizeof(buf));

	//writing the contents of buffer buf to the file specified by the outfd
	//file descriptor
	write(outfd,buf,fileread);
	
	//writing to STDOUT (FD == 1)	
	write(1,buf,fileread);
	
	//Values of file descriptors
	printf("\n\n\nThe value of FD for  input file is :: %d\n",infd);
	printf("The value of FD for output file is :: %d\n",outfd);

	//closing the file descriptors.
	close(infd);
	close(outfd);
}
