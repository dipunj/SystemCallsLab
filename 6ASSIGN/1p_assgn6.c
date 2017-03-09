// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #6
	
// PROBLEM    : #1

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig)
{
	switch (sig)
	{
		case SIGINT:
		{
			printf("SIGINT occured\n");
			break;
		}
		case SIGHUP:
		{
			printf("SIGHUP occured\n");
			break;
		}
		case SIGTERM:
		{
			printf("SIGTERM occured\n");
			break;
		}
	}
}
void main()
{
	signal(SIGINT,sig_handler);
	signal(SIGHUP,sig_handler);
	signal(SIGTERM,sig_handler);
	while(1)
		{
			printf("Hello, this is main\n");
			sleep(1);
		}
}
