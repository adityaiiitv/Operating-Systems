#include<iostream>
using namespace std;
int main()
{
	int n,ts;
	cout<<"\n enter number of processes and timeslice: \n";
	cin>>n>>ts;
	int arr[n],req[n],p[n],total_time;
	for(int i=0;i<n;i++)
	{
		cout<<"\n enter the arrival time and required time for process : "<<i<<"\n";
		cin>>arr[i]>>req[i];
		p[i]=i;
		total_time = total_time + req[i];
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
	
				temp=req[j];
				req[j]=req[i];
				req[i]=temp;
				
				temp=p[j];
				p[j]=p[i];
				p[i]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<"\n process: "<<p[i]<<" arrival: "<<arr[i]<<"required time: "<<req[i];
	}
	// LOGIC
	int t=0,order[n],num=n;
	for(int i=0;i<total_time;i+=ts)
	{
		
			if(ts>req[0] && t<num)
			{
				
			}
			
			if(ts==req[0] && t<num)
			{
				order[t]=p[0];t++;
				n--;
				for(int j=0;j<n;j++)
				{p[j]=p[j+1];arr[j]=arr[j+1];rem[j]=rem[j+1];}
			}
			
			if(ts<req[0] && t< num)
			{
				req[0]=req[0]-ts;
				
				temp=req[0];
				req[0]=req[n];
				req[n]=temp;
				
				temp=p[0];
				p[0]=p[n];
				p[n]=temp;
				
				temp=arr[0];
				arr[0]=arr[n];
				arr[n]=temp;
				
			}
			
	}
	
	return 0;
}
