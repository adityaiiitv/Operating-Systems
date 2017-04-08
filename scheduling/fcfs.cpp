#include<iostream>
using namespace std;
int main()
{
int p[10],arr[10],req[10],n;
cout<<"\n enter the num of pro";
cin>>n;
// TO INPUT THE DETAILS OF PROCESSES
for (int i =0;i<n;i++)
{
 cout<<"\n for process "<<i+1<<" enter arrival time and required time \n";
 cin>>arr[i]>>req[i];
 p[i]=i+1;
}

// SORTING BASED ON ARRIVAL TIME

for(int i=0;i<n;i++)
{
for(int j=i;j<n;j++)
{
if(arr[j]>arr[j+1])
{
int t=arr[j];
arr[j]=arr[j+1];
arr[j+1]=t;

t=req[j];
req[j]=req[j+1];
req[j+1]=t;

t=p[j];
p[j]=p[j+1];
p[j+1]=t;
}
}
}
// TO SHOW THE PROCESSES
for(int i=0;i<n;i++)
{
cout<<"\n order =\n process "<<p[i]<<"arrival "<<arr[i]<<"req time "<<req[i];
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

