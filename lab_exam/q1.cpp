#include<iostream>
using namespace std;
class queue1
{

	public:
	int arrival;
	int service;
	int pri;
	
	queue1 *next,*front;
	queue1()
	{
		front = NULL;
	}
};

int main()
{
	int arr[]={0,0,0,1,1,3,4};
	int ser[]={4,6,1,8,4,6,2};
	int pri[]={0,1,2,1,2,0,1};

	queue1 p[2],*ptr,*temp1,*temp2,*temp3;
	// SEPARATION OF 3 QUEUES
	for(int i=0;i<7;i++)
	{
		if(pri[i]==0)
		{
			if(p[0].front==NULL)
			{
				p[0].front->arrival=arr[i];
				p[0].front->service=ser[i];
				p[0].front->pri=pri[i];
				temp1=p[0].front;
			}
			if(p[0].front != NULL)
			{
				ptr=new queue1;
				ptr->arrival=arr[i];
				ptr->service=ser[i];
				ptr->pri=pri[i];
				temp1->next=ptr;
				temp1=ptr;
				
			}
		}
		if(pri[i]==1)
		{
			if(p[1].front==NULL)
			{
				p[1].front->arrival=arr[i];
				p[1].front->service=ser[i];
				p[1].front->pri=pri[i];
				temp2=p[1].front;
			}
			if(p[1].front != NULL)
			{
				ptr=new queue1;
				ptr->arrival=arr[i];
				ptr->service=ser[i];
				ptr->pri=pri[i];
				temp2->next=ptr;
				temp2=ptr;
			}
		}
		if(pri[i]==2)
		{
			if(p[2].front==NULL)
			{
				p[2].front->arrival=arr[i];
				p[2].front->service=ser[i];
				p[2].front->pri=pri[i];
				temp3=p[2].front;
			}
			if(p[2].front != NULL)
			{
				ptr=new queue1;
				ptr->arrival=arr[i];
				ptr->service=ser[i];
				ptr->pri=pri[i];
				temp3->next=ptr;
				temp3=ptr;
			}
		}
	}
	// SEPARATION OF 3 QUEUES
	
	// LOGIC
	// QUEUE1
	int ts1=1;
	temp3=p[0].front;int t1=0;
	while(temp3!=NULL)
	{
		t1=t1+temp3->service;
	}
	for(int i=0;i<2*t1;i+=2*ts1)
	{}
	// QUEUE1
	
	
	// LOGIC ENDS
	return 0;
}





















