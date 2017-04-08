/*
 * producer_consumer.c
 *
 *  Created on: 19-Oct-2014
 *      Author: anjul
 */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t empty,mutex,full;
int n;
void *producer(void *arg){
	int f = (int)arg;
	sem_wait(&empty);
	sem_wait(&mutex);
	sleep(1);
	printf("Data number %d is produced\n",f);
	n=f;
	sem_post(&mutex);
	sem_post(&full);
	pthread_exit(NULL);
}
void *consumer(void *arg){
	int f = (int)arg;
	sem_wait(&full);
	sem_wait(&mutex);
	sleep(1);
	printf("Data number %d is consumed\n",n);
	sem_post(&mutex);
	sem_post(&empty);
	pthread_exit(NULL);
}
int main(){
	pthread_t pro,con;
	sem_init(&empty,0,7);
	sem_init(&full,0,0);
	sem_init(&mutex,0,1);
	int i;
	for(i=0;i<20;i++){
		pthread_create(&pro,NULL,producer,(void *)i);
		pthread_create(&con,NULL,consumer,(void *)i);
	}
	for(i=0;i<20;i++){
		pthread_join(pro,NULL);
		pthread_join(con,NULL);
	}
}
