#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig)
{
	switch (sig)
	{
		case SIGINT:
		{
			printf("SIGINT occured");
			break;
		}
		case SIGHUP:
		{
			printf("SIGHUP occured");
			break;
		}
		case SIGTERM:
		{
			printf("SIGTERM occured");
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
