// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #7
	
// PROBLEM    : #1

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void enQ(int )
void sig_handler(int sig)
{
	switch (sig)
	{
		case SIGINT:
		{
			enQ(SIGINT);
			printf("SIGINT occured\n");
			break;
		}
		case SIGHUP:
		{
			enQ(SIGHUP);
			printf("SIGHUP occured\n");
			break;
		}
		case SIGABRT:
		{
			enQ(SIGABRT);
			printf("SIGABRT occured\n");
			break;
		}
	}
}
void install_handler()
{
	signal(SIGINT,sig_handler);
	signal(SIGHUP,sig_handler);
	signal(SIGTERM,sig_handler);

	sigset_t block,empty;
	sigemptyset(empty);
	sigemptyset(block);
	sigaddset(block, SIGINT);
	sigaddset(block, SIGHUP);
	sigaddset(block, SIGABRT);

	//BLOCKING SIGINT, SIGHUP,SIGABRT
	sigprocmask(SIG_BLOCK,block,empty);
}
void main()
{
	install_handler();
	while(1)
		{
			printf("Hello, this is main\n");
			sleep(1);
		}
}
