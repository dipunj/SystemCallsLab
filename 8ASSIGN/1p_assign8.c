// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #8
//
// PROBLEM    : #1


// CODE : -
	

#include <stdio.h>
#include <pthread.h>

#define NUM 5

void *printHello(void *m)
{
	int i;
	int n = (int)m;
	for(i=0;i<5;++i)
		printf("Hello World (thread %ld)\n",n+1);
	pthread_exit(NULL);
}

int main()
{
	int arg;
	pthread_t thread[NUM];
	for(arg = 0; arg < NUM ; ++arg)
	{
		printf("In main, creating thread #%d\n",arg+1);
		int rc = pthread_create ( &thread[arg], NULL, printHello, (void *)arg);
		if(rc)
			perror("pthread_create()");
	}
	pthread_exit(NULL);
}
