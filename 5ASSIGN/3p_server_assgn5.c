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
#define CLS 2
//	SERVER FILE

int main()
{
	char s[1000];
	int num_read = 0;	
	int i = 0
	int fd_WK,fd_CL[CLS];

	mknod("WELL_KNOWN", S_IFIFO|0666, 0);
	fd_WK = open("WELL_KNOWN",O_RDONLY);

	mknod("SRVR_2_CLA",S_IFIFO|0666, 0);
	fd_CL[0] = open("SRVR_2_CLA",O_WRONLY);	
	mknod("SRVR_2_CLB",S_IFIFO|0666, 0);
	fd_CL[1] = open("SRVR_2_CLB",O_WRONLY);

	printf("SERVER: Ready to Recieve Requests...\n");

	do
	{
		//READING CLIENT'S REQUEST
		if((num_read = num_read + read(fd_WK,&s[num_read],1000)) == -1)
				perror("read");
		else
		{
			i++;
			printf("SERVER: %d B written\nSERVER: Client Text Recieved ::\"%s\"\n",num_read,s);
			s[num_read++] = '\n';
		}
	}
	while(num_read > 0 && i < CLS)

		s[num_read] = '\0';
	//RESPONSE TO BOTH CLIENT-A, CLIENT-B
	for(i=0;i<CLS;i++)
		write(fd_CL[i],resp_buff,len);
	return 0;
}
