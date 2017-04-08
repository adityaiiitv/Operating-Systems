#include<pthread.h>
#include<stdio.h>

int mat1[5][5];
int mat2[5][5];
int mat3[5][5];

int r1,c1,r2,c2;
int temp1[5],temp2[5];

void *thread(void *){
	int i,sum;
	sum = 0;
	for(i=0;i<c1;i++){
		sum += temp1[i]*temp2[i];
	}
	printf("thread finished ...");
	pthread_exit(NULL);
}

int main(){
	printf("Enter Number of Rows For Matrix 1 :");
	    scanf("%d",&r1);

	    printf("Enter Number of Columns For Matrix 1 :");
	    scanf("%d",&c1);
	    int i,j,k;
	    for(i=0;i<r1;i++)
	    {
	        for(j=0;j<c1;j++)
	        {
	            printf("Enter Mat1[%d][%d] :",i,j);
	            scanf("%d",&mat1[i][j]);
	        }
	    }

	    printf("\n");

	    printf("Enter Numer of Rows For Matrix 2 :");
	    scanf("%d",&r2);

	    printf("Enter Number of Columns For Matrix 2 :");
	    scanf("%d",&c2);

	    for(i=0;i<r2;i++)
	    {
	        for(j=0;j<c2;j++)
	        {
	            printf("Enter Mat2[%d][%d] :",i,j);
	            scanf("%d",&mat2[i][j]);
	        }
	    }
	    pthread_t arr[r1][c2];
	    if(c2 != r1){
	    	printf("Matrix multiplication is not possible\n");
	    }
	    else
	    	for(i=0;i<r1;i++){
	    		for(j=0;j<c2;j++){
	    			for(k=0;k<c1;k++){
	    				temp1[k]=mat1[i][k];
	    				temp2[k]=mat2[k][j];
	    				pthread_create(arr[i][j],NULL,thread,NULL);
	    			}
	    			mat[i][j]=
	    		}
	    	}
	    }
}

