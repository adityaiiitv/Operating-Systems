#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t read,write;
int read_count ;

void *Writer(void *arg)
{
	int temp = (int)arg;
	printf("\nwriter %d is trying to enter the critical section\n",temp);
	sem_wait(&write);
	printf("writer %d is writing to the critical section\n",temp);
	printf("writer %d is leaving \n",temp);
	sem_post(&write);
}


void *Reader(void *arg)
{
	int temp = (int)arg;
	printf("reader %d is trying to enter the critical section\n",temp);
	sem_wait(&read);
	read_count++;
	if(read_count==1)
	{
		sem_wait(&write);
		printf("reader %d is reading\n",temp);
	}
	sem_post(&read);
	sem_wait(&read);
	read_count--;
	if(read_count == 0)
	{
		printf("reader %d is leaving the critical section\n",temp);
		sem_post(&write);
	}
	sem_post(&read);
}


int main()
{
	int i,num_readers,num_writers;
	pthread_t writer[10],reader[10];
	sem_init(&read,0,1);
	sem_init(&write,0,1);
	printf("Enter the number of readers");
	scanf("%d",&num_readers);
	printf("Enter the number of writers");
	scanf("%d",&num_writers);
	for(i=0;i<num_readers;i++)
	{
		pthread_create(&reader[i],NULL,Reader,(void *)i);
		pthread_join(reader[i],NULL);
	}
	for(i=0;i<num_writers;i++)
	{
		pthread_create(&writer[i],NULL,Writer,(void *)i);
		pthread_join(writer[i],NULL);
	}
}


