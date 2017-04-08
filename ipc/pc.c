#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

int buf[1000],count;
sem_t mutex,full,empty;

void *consumer(void *arg)
{	int i;
	int m=(int)arg;
	sleep(1);
	for(i=0;i<m;i++)
	{
		printf("CONSUMER EXECUTING\n");
		sem_wait(&full);
		sem_wait(&mutex);
		i=buf[i];
		printf("CONSUMER ENTERING CS\n");
		printf("CONSUMER LEAVING CS\n");
		sem_post(&mutex);
		sem_post(&empty);
		printf("%d ITEM CONSUMED\n",i);
	}
}

void *producer(void *arg)
{
	int i;
	int m=(int)arg;
	for(i=0;i<m;i++)
	{
	buf[i]=i;
	sleep(1);
	sem_wait(&empty);
	printf("PRODUCER EXECUTING\n");
	printf("PRODUCER IS IN CS\n");
	sem_wait(&mutex);
	printf("PRODUCER LEAVING CS\n");
	sem_post(&mutex);
	sem_post(&full);
	}
}


int main()
{
	int x,m;
	pthread_t tid1,tid2;
	printf("PRODUCER CONSUMER PROBLEM\n");
	printf("ENTER THE BUFFER SIZE\n");
	scanf("%d",&x);

	sem_init(&mutex ,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,x);

	pthread_create(&tid1,NULL,producer,(void*)x);
	pthread_create(&tid2,NULL,consumer,(void *)x);

	pthread_join(&tid1,NULL);
	pthread_join(&tid2,NULL);

	pthread_exit(NULL);
} 






