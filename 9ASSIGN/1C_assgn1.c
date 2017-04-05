// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #9

// PROBLEM    : #1-C


#include <stdio.h>
#include <pthread.h>

int balance = 1000000;
pthread_mutex_t mutex;

void *withdraw(void * n)
{
	int temp = (int)n;
	printf("\nWithdraw Called :: %d Debit",temp);
	
	// locking the variable balance
	pthread_mutex_lock(&mutex);
	balance = balance - temp; 
	pthread_mutex_unlock(&mutex);
	
	printf("\nBalance = %d ",balance);
}

void *deposit(void * n)
{
	int temp = (int)n;
	printf("\nDeposit Called :: %d Credit",temp);
	
	balance = balance + temp;	
	printf("\nBalance = %d ",balance);
}

int main()
{
	printf("You have %d Cr. in your bank account\n",balance);

	if(pthread_mutex_init(&mutex,NULL))
		perror("pthread_mutex_init failed");
	int n = 600000;		//amount to be withdrawn
	int m = 500000;		//amount to be deposited

	pthread_t t_ID[2];

	// to withdraw money
		pthread_create(&t_ID[0], NULL, withdraw, (void *)n);
	
	// when main resumes, create another thread to deposit money
		pthread_create(&t_ID[1], NULL, deposit, (void *)m);
	
	// Main shall be suspended till both the threads terminate
		pthread_join(t_ID[0],NULL);
		pthread_join(t_ID[1],NULL);

	printf("\n");
}
