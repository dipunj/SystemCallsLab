// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #9
//
// PROBLEM    : #1-b



// CONCLUSION :: Yes, the relative order in which the calls are made is different, however the end balance is the same.



#include <stdio.h>
#include <pthread.h>

int balance = 1000000;
void *withdraw(void * n)
{
	int temp = (int)n;
	printf("\nWithdraw Called :: %d Debit",temp);
	balance = balance - temp; 
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
	printf("You have %d CR. in your bank account\n",balance);

	int n = 600000;
	int m = 500000;
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
