// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #7
	
// PROBLEM    : #3

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void check_pending()
{
	sigset_t set;
	if( sigpending( &set ) != 0)
		perror("sigpending() error");
	else
	{
		if(sigismember(&set,SIGHUP))
			printf("\t| SIG:1 | SIGHUP is pending\n");	
		if(sigismember(&set,SIGINT))
			printf("\t| SIG:2 | SIGINT is pending\n");
		if(sigismember(&set,SIGABRT))
			printf("\t| SIG:6 | SIGABRT is pending\n");
	}
}

void install_handler()
{
	sigset_t block,empty;
	sigemptyset(&empty);
	sigemptyset(&block);
	sigaddset(&block, SIGINT);
	sigaddset(&block, SIGHUP);
	sigaddset(&block, SIGABRT);

	//BLOCKING SIGINT, SIGHUP,SIGABRT
	sigprocmask(SIG_BLOCK,&block,&empty);
}
void main()
{
	install_handler();
	printf("\t======= INSTRUCTIONS =======\n");
	printf("This process once inititated would block SIGABRT, SIGINT, SIGHUP\n");
	printf("To quit the process or send signals to this process, please open a new tty and find this process's PID by running the command \"ps -x\"\n");
	printf("TO BEGIN PRESS 1\n");
	char op = getchar();
	while(op)
		{
			printf("\n_______________________________________________\n");
			printf("Hello, this is main\n\tPENDING LIST:\n\n");
			check_pending();
			printf("_______________________________________________\n");
			sleep(1);
		}
}
