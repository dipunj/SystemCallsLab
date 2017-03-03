#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
int count;
unsigned int alrm;
void sig_handler(int sig)
{	
	count++;
	printf("SIGALRM activated, this is signal handler\n");
	alarm(alrm);
	if(count == 5)
		exit(1);
}

void main()
{
	printf("Enter the alarm duration in seconds\n");
	scanf("%u",&alrm);
	
	alarm(alrm);
	signal(SIGALRM,sig_handler);
	while(1)
		{
			;
			//printf("Hello, this is main\n");
		}
}
