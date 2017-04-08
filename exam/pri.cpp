/* 201351010 ADITYA PRAKASH */
#include<iostream>
using namespace std;

int main()
{
int p[10],arr[10],pri[10],req[10],n,t;
cout<<" \n enter the number of processes \n";
cin>>n;
// TO INPUT THE DETAILS OF PROCESSES
for(int i=0;i<n;i++)
{
cout<<"\n enter the arrival time, priority and frequency for process "<<i+1<<"\n"; 
cin>>arr[i]>>pri[i]>>req[i];
p[i]=i+1;
}

// SORTING BASED ON ARRIVAL TIME

for(int i=0;i<n;i++)
{
for(int j=i;j<n;j++)
{
if(arr[j]>arr[j+1])
{
t=arr[j];
arr[j]=arr[j+1];
arr[j+1]=t;

t=pri[j];
pri[j]=pri[j+1];
pri[j+1]=t;

t=p[j];
p[j]=p[j+1];
p[j+1]=t;

t=req[j];
req[j]=req[j+1];
req[j+1]=t;

}

// CONDITIONAL SORTING BASED ON PRIORITY

else if(arr[j]==arr[j+1] && pri[j]<pri[j+1])
{
t=arr[j];
arr[j]=arr[j+1];
arr[j+1]=t;

t=pri[j];
pri[j]=pri[j+1];
pri[j+1]=t;

t=p[j];
p[j]=p[j+1];
p[j+1]=t;

t=req[j];
req[j]=req[j+1];
req[j+1]=t;

}
}
}


// TO SHOW THE PROCESSES

for(int l=0 ;l<n;l++)
{ cout<<"\n process number: "<<p[l]<<"priority: "<<pri[l]<<"arrival: "<<arr[l]<<"req: "<<req[l];
}

int w=0;
for(int i=0;i<n;i++)
{
// CALCULATING WAITING TIME AND ARRIVAL TIME
cout<<"\n waiting time for process "<<p[i]<<" = "<<((w)-(arr[i]));
cout<<"\n turnaround time for process "<<p[i]<<" = "<<((req[i])+(w)-(arr[i]));
w+=req[i];
}


return 0;
}
