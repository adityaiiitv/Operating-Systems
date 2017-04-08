#include<iostream>
#include<pthread.h>
#include<stdio.h>
using namespace std;
int prime[100],product=1,n;

void* pro(void *N)
{
	int num;
	num=(int)N;
	product=product*num;
	printf("\n thread: %d results in product: %d",num,product );
	pthread_exit(NULL);
}

int main()
{
	cout<<"\n ENTER THE NUMBER UPTO WHICH YOU WANT THE PRODUCT: \n";
	cin>>n;
	pthread_t tid[n];
	 
	for(int i=1;i<=n;i++)
	{
		pthread_create(&tid[i],NULL,pro,(void *)i);
	}
	for(int i=1;i<=n;i++)
	{pthread_join(tid[i],NULL);}
	cout<<"\n PRODUCT: "<<product;
	return 0;
}
