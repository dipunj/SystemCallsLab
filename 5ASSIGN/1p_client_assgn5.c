// NAME       :  DIPUNJ GUPTA
// REG. NO.   :  20154061
// GROUP      :  CS-A2
// SEMESTER   :  IVth
// LAB        :  PROGRAMMING TOOLS - II(SYSTEM CALLS)
// DATE       :  FEB 9TH, 2017
// ASSIGNMENT :  5
//
// PROBLEM    :  #1
// CODED IN   :  C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

//	CLIENT FILE
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

	printf("Created the pipe...\nEnter the filename:: ");

	// SEND REQUEST
	while (gets(s),!feof(stdin))
	{
		if((num_read = write(fd_c2s,s,strlen(s))) == -1)
			perror("write");
		else
		{
			printf("CLIENT: Request sent to server :::bytes written :: %dBytes\n",num_read);
			break;
		}
	}	
	
	// OUTPUT THE RESPONSE FROM SERVER
	do
	{
		if((num_write = read(fd_s2c,resp_buff,1000)) == -1)
			perror("read");
		else
		{
			s[num_write] = '\0';
			printf("CLIENT: Recieved : %dBytes\n\n\t\t=======SERVER RESPONSE========\n\n %s \n\n",num_write,resp_buff);
			break;
		}
	}
	while(num_write > 0);
	return 0;
}
