// SEMESTER   :  IVth
// LAB        :  PROGRAMMING TOOLS - II(SYSTEM CALLS)
// DATE       :  FEB 9TH, 2017
// ASSIGNMENT :  5
//
// PROBLEM    :  #1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

//	SERVER FILE

int main()
{
	char s[300];
	char resp_buff[1000];
	int num_read,num_write;
	int fd_c2s,fd_s2c;

	mknod("cl_2_srvr",S_IFIFO|0666,0);
	fd_c2s = open("cl_2_srvr",O_RDWR);

	mknod("srvr_2_cl",S_IFIFO|0666,0);
	fd_s2c = open("srvr_2_cl",O_RDWR);

	printf("SERVER: Ready to Recieve Requests...\n");
	
	//READING CLIENT'S REQUEST
	do{
		if((num_read = read(fd_c2s,s,300)) == -1)
			perror("read");
		else
		{
			s[num_read] = '\0';
			printf("SERVER: bytes written : %d bytes \nSERVER: Requested File is ::\"%s\"\n",num_read,s);
			break;
		}
	}
	while(num_read > 0);

	// PROCESSING THE REQUEST
	printf("\nSERVER: Processing the request...\n");

	int fdfile = open(s,O_RDONLY);
	ssize_t len = read(fdfile,resp_buff,1000);

	int red = write(fd_s2c,resp_buff,len);
	if(red == -1)
		perror("SERVER: No Such File");
	else
		printf("SERVER: Responded Succesfully\nSERVER: Bytes written :: %d B",red);
	return 0;
}
