// incomplete

#include <stdio.h>
#include <pthread.h>

void* add(void *n)
{
	race += 3;
}

void* sub(void *n)
{
	race -= 1;
}

int main()
{
	pthread_t TID[3];
	int i;

	pthread_create(TID[0], NULL, add, NULL)
	pthread_create(TID[1], NULL, sub, NULL)
	pthread_create(TID[2], NULL, wait, NULL)
	
}
