// SESSION    : 2016-17
// LAB        : PROGRAMMING TOOLS - II
// ASSIGNMENT : #9
//
// PROBLEM    : #1-a


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
	
	// Main shall be suspended till withdraw thread terminates
		pthread_join(t_ID[0],NULL);

	// when main resumes, create another thread to deposit money
		pthread_create(&t_ID[1], NULL, deposit, (void *)m);

	// Main shall be suspended till deposit thread terminates
		pthread_join(t_ID[1],NULL);
	printf("\n");
}
