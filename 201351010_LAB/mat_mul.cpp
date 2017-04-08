#include <iostream>
#include <cstdlib>
#include <pthread.h>
using namespace std;
#define N_THREADS 5

void *print(void *id)
{
		long tid;
		tid = (long)id;
		cout<<"\n hello with thread id: \n"<<tid;
		pthread_exit(NULL);
}

int main()
{
	int rc;
	pthread_t threads[N_THREADS];
	for(int i=0;i<N_THREADS;i++)
	{
		rc = pthread_create(&threads[i],NULL,print,(void* )i);
	
		if(rc==1)
		{
			cout<<"\n Thread not created. Thread number:"<<i+1;
			exit(-1);
		}
	}
	pthread_exit(NULL);
	return 0;
}

