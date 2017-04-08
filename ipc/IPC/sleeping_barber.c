/*
 * sleeping_barber.c
 *
 *  Created on: 16-Oct-2014
 *      Author: anjul
 */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
sem_t customer,barber,awake;
pthread_t cust[10],bar;
int n=4;
void *nai(void *arg){
	while(n>=0){
		sem_wait(&awake);
		sem_post(&barber);
		sleep(2);
		printf("Barber finished cutting hair of customer\n");
		n++;
	}
	pthread_exit(NULL);
}
void *grahak(void *arg){
	if(n<4 && n>0){
		sem_wait(&customer);
		sem_wait(&barber);
		printf("Customer number %d entered \n",(int) arg);
		n--;
		sem_post(&customer);
	}
	else if(n==4){
		sem_wait(&customer);
		sem_post(&awake);
		sem_wait(&barber);
		printf("Customer number %d entered\n",(int) arg);
		n--;
		sem_post(&customer);
	}
	pthread_exit(NULL);
}
int main(){
	int i;
	sem_init(&awake,0,1);
	sem_init(&customer,0,1);
	sem_init(&barber,0,1);
	for(i=0;i<10;i++){
		pthread_create(&cust[i],NULL,grahak,(void *)i);
	}
	pthread_create(&bar,NULL,nai,(void *)i);
	for(i=0;i<10;i++){
		pthread_join(cust[i],NULL);
	}
	pthread_join(bar,NULL);
	if(n==4){
		exit(0);
	}
}
