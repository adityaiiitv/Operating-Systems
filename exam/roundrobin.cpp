#include<iostream>
using namespace std;
int main()
{
	int ts,n;
	cout<<"\n ENTER THE NUMBER OF PROCESSES AND TIMESLICE: \n";
	cin>>n>>ts;
	int p[n],arr[n],pri[n],rem[n],ser[n];
	// ENTERING
	for(int i=0;i<n;i++)
	{
		p[i]=i;
		cout<<"\n ENTER THE ARRIVAL TIME, PRIORITY AND REQUIRED TIME: ";
		cin>>arr[i];
		cout<<"\n";
		cin>>pri[i];
		cout<<"\n";
		cin>>rem[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				int temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
	
				temp=rem[j];
				rem[j]=rem[i];
				rem[i]=temp;
	
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
				
				temp=pri[j];
				pri[j]=pri[i];
				pri[i]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{	
			if(arr[j]==arr[j+1] && pri[j]<pri[j+1])
			{
			int t=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=t;

			t=pri[j];
			pri[j]=pri[j+1];
			pri[j+1]=t;

			t=p[j];
			p[j]=p[j+1];
			p[j+1]=t;

			t=rem[j];
			rem[j]=rem[j+1];
			rem[j+1]=t;

			}
		}	
	}
	
	for(int i=0;i<n;i++)
	{cout<<"pro: "<<p[i]<<"arr: "<<arr[i]<<"rem: "<<rem[i]<<"pri: "<<pri[i]<<"\n";}
	
	int wt_sum=0;
	for(int i=0;i<n;i++)
	{
		wt_sum=wt_sum+rem[i];
	}
	cout<<"sum of wt: "<<wt_sum;
	int count =0,t,t1,t2,t3;
	for(int i=0;i<wt_sum;i+=ts)
	{
		cout<<"\n this is i";
		for(int j=0;j<ts;j++)
		{	cout<<"\n this is j";
			if(rem[0]==1)
			{
				rem[0]--;
				ser[count]=p[0];count++;
				for(int a=0;a<n;a++)
				{	int temp=p[a+1];
					p[a]=temp;
					temp=pri[a+1];
					pri[a]=temp;
					temp=arr[a+1];
					arr[a]=temp;
					temp=rem[a+1];
					rem[a]=temp;
				}
				n--;
				
			}
			else if(rem[0]>1 && j!=ts-1)
			{
				rem[0]--;
			}
			
			else if(rem[0]>1 && j==ts-1)
			{
				rem[0]--;
				t=p[0];t1=pri[0];t2=arr[0];t3=rem[0];
				for(int a=0;a<n;a++)
				{
					int temp=p[a+1];
					p[a]=temp;
					temp=pri[a+1];
					pri[a]=temp;
					temp=arr[a+1];
					arr[a]=temp;
					temp=rem[a+1];
					rem[a]=temp;
				}
				p[n]=t;pri[n]=t1;arr[n]=t2;rem[n]=t3;
			}
			for(int i=0;i<n;i++)
	{cout<<"pro: "<<p[i]<<"arr: "<<arr[i]<<"rem: "<<rem[i]<<"pri: "<<pri[i]<<"\n";}
		}
			
	}
	for(int i=0;i<count;i++)
	{
		cout<<"\n";
		cout<<ser[i]<<" ";
	}
	return 0;
	
}
