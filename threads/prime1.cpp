#include<iostream>
#include<pthread.h>
using namespace std;
int prime[100],count=0,n;

void* prime_func(void *N)
{
	int i,num,flag=0;
	num=(int)N;
	for(i=2;i<num;i++)
	{	
		if(num%i==0)
		{flag=1;}
	}
	if(flag==0)
	{count++;}
	pthread_exit(NULL);
}

int main()
{
	cout<<"\n enter the number upto which you want to get prime numbers: \n";
	cin>>n;
	pthread_t tid[n];
	 
	for(int i=2;i<=n;i++)
	{
		pthread_create(&tid[i],NULL,prime_func,(void*)i);
	}
	for(int i=2;i<=n;i++)
	{pthread_join(tid[i],NULL);}
	cout<<"\n number of prime numbers: "<<count;
	return 0;
}
