#include<iostream>
#include<pthread.h>
using namespace std;
int a[10][10],b[10][10],c[10][10],row1,row2,col1,col2;

class thread_mm
{
	public:
	int t_row;
	int t_col;

};

void* mat_mul(void* t1)
{
	thread_mm* t2;
	t2=(thread_mm*)t1;
	for(int i=0;i<col1;i++)
	{	
		c[t2->t_row][t2->t_col]+=a[t2->t_row][i]*b[i][t2->t_col];
	}
	pthread_exit(NULL);
}

int main()
{
	cout<<"\n enter rows and columns of matrix 1";
	cin>>row1>>col1;
	cout<<"\n enter rows and columns of matrix 2";
	cin>>row2>>col2;
	if(col1!=row2)
	{
		cout<<"\n multiplication not possible\n";
	}
	else
	{
		cout<<"\n enter matrix 1 row wise\n";
		for(int i=0;i<row1;i++)
		{
			for(int j=0;j<col1;j++)
			{
				cin>>a[i][j];
			}
		
		}
		cout<<"\n enter matrix 2 row wise\n";
		for(int i=0;i<row2;i++)
		{
			for(int j=0;j<col2;j++)
			{
				cin>>b[i][j];
			}
		
		}
		
		pthread_t tid[col2*row1];
		thread_mm thr[col2*row1];
		int count=0;
		
		for(int i=0;i<col2;i++)
		{
			for(int j=0;j<row1;j++)
			{
				c[i][j]=0;
			}
		}
		
		for(int i=0;i<row1;i++)
		{
			for(int j=0;j<col2;j++)
			{
				thr[count].t_row=i;
				thr[count].t_col=j;
				pthread_create(&tid[count],NULL,mat_mul,(void*)&thr[count]);
				count++;
			}
		}
		for(int l=0;l<count;l++)
		{
			pthread_join(tid[l],NULL);
		}
		
		cout<<"\n resultant matrix:\n";
		for(int i=0;i<col1;i++)
		{
			for(int j=0;j<row2;j++)
			{
				cout<<c[i][j]<<" ";
			}
			cout<<"\n";
		}
		
	}
	return 0;
}
