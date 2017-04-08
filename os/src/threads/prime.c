#include<stdio.h>
#include<pthread.h>
int n;
void *half(void *);
int main(){
	printf("Enter the number uptil which you want to generate prime numbers\n");
	scanf("%d",&n);
	int i,j;
	int jump=0;
	pthread_t tid;
	pthread_create(&tid,NULL,half,NULL);
	for(i=n/2;i<n;i=i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				jump=1;
			}
			else if(j==i-1){
				printf("%d\n",i);
			}
		}
		if(jump==1){
			break;
		}
	}
	pthread_join(tid,NULL);

}
void *half(void *arg){
	int i,j;
	int jump=0;
	for(i=2;i<n/2;i=i++){
			for(j=2;j<i;j++){
				if(i%j==0){
					jump=1;
				}
				else if(j==i-1){
					printf("%d\n",i);
				}
			}
			if(jump==1){
				break;
			}
	}
	pthread_exit(NULL);
}
