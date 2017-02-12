// NAME       :  DIPUNJ GUPTA
// REG. NO.   :  20154061
// GROUP      :  CS-A2
// SEMESTER   :  IVth
// LAB        :  PROGRAMMING TOOLS - II(SYSTEM CALLS)
// DATE       :  FEB 9TH, 2017
// ASSIGNMENT :  5
//
// PROBLEM    :  #3-SERVER

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
	int fd_WK,fd_CLA,fd_CLB;

	mknod("WELL_KNOWN",S_IFIFO|0666,0);
	fd_WK = open("WELL_KNOWN",O_RDWR);


	mknod("SRVR_2_CLA",S_IFIFO|0666,0);
	fd_CLA = open("SRVR_2_CLA",O_RDWR);
	
	mknod("SRVR_2_CLB",S_IFIFO|0666,0);
	fd_CLB = open("SRVR_2_CLB",O_RDWR);

	printf("SERVER: Ready to Recieve Requests...\n");


	//READING CLIENT'S REQUEST
	do{
		if((num_read = read(fd_WK,s,300)) == -1)
			perror("read");
		else
		{
			s[num_read] = '\0';
			printf("SERVER: bytes written : %d bytes\nSERVER: Client Text Recieved ::\"%s\"\n",num_read,s);
			ssize_t len = read(fd_WK,resp_buff,1000);
			write(fd_WK,resp_buff,len);
		}
	}
	while(num_read > 0);

	//RESPONSE TO BOTH CLIENT-A, CLIENT-B
	
	
	return 0;
}
