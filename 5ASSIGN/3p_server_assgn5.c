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
	int i = 0; 	// SO THAT SERVER ONLY PROCESSES ONE REQUEST FROM EACH OF THE CLIENTS.
	int fd_WK,fd_CL[CLS];

	// CREATING PIPE FOR UPLINK.
	mknod("WELL_KNOWN", S_IFIFO|0666, 0);
	printf("Waiting for clients...\n");
	fd_WK = open("WELL_KNOWN",O_RDONLY);

	// CREATING PIPE FOR DOWNLINK FOR 2 CLIENTS.
	mknod("SRVR_2_CLA", S_IFIFO | 0666, 0);
	fd_CL[0] = open("SRVR_2_CLA",O_WRONLY);	
	mknod("SRVR_2_CLB", S_IFIFO | 0666, 0);
	fd_CL[1] = open("SRVR_2_CLB",O_WRONLY);
	printf("All clients online...\n");

	printf("\nSERVER: Ready to Recieve Requests...\n");

	do
	{
		//READING CLIENT'S REQUEST
		if((num_read = num_read + read(fd_WK,&s[num_read],1000)) == -1)
			perror("read");
		else
		{
			i++;
			printf("SERVER: %d B written\nSERVER: Client Text Recieved ::%s\n",num_read,s);
			s[num_read++] = '\n';
		}
	}
	while(num_read > 0 && i < CLS);

	// TERMINATING THE BUFFER WITH NULL.
	s[num_read] = '\0';

	//RESPONSE TO BOTH CLIENT-A, CLIENT-B
	for(i=0;i<CLS;i++)
		write(fd_CL[i],s,num_read);

	// REMOVING THE PIPES AFTER USE
	system("rm WELL_KNOWN SRVR_2_CLA SRVR_2_CLB");
	return 0;
}
