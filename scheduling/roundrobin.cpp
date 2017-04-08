#include<iostream>
using namespace std;

class roundrobin
{
int id,arrive,execute,waiting,turnaround,rt;
public:

void get()
{
cout<<"\nEnter process ID: ";
cin>>id;
cout<<"\nEnter Arrival time: ";
cin>>arrive;
cout<<"\nEnter Execute time: ";
cin>>execute;
rt=execute;
}

void display()
{
cout<<id<<"\t    "<<arrive<<"\t          "<<execute<<"\n";
}

void displayrr()
{
cout<<id<<"\t     "<<waiting<<"\t        "<<turnaround<<"\n";
}

int return_arrive()
{
return arrive;
}

int return_execute()
{
return execute;
}

int return_remain()
{
return rt;
}

void setwaiting(int wait)
{
waiting=wait;
}

void setturn(int ta)
{
turnaround=ta;
}

void setremain(int r)
{
rt=r;
}

}ob[10],temp;



void calc(int,int);

void swap(int no)
{
int j,k;
for(j=0;j<no;j++)
{
for(k=0;k<no-1;k++)
{
if(ob[k].return_arrive() > ob[k+1].return_arrive())
{
temp=ob[k];
ob[k]=ob[k+1];
ob[k+1]=temp;
}
}
}
}


int main()
{
int n;
int i;
int timeslice;
cout<<"Round Robin Process Scheduling\n";
cout<<"Enter the time slice for this Scheduling: ";
cin>>timeslice;
cout<<"Enter the no. of processes: ";
cin>>n;
cout<<"\nThe processes are: \n";
for(i=0;i<n;i++)
{
ob[i].get();
}
 
cout<<"The processes entered are: \n";
cout<<"Id   Arrival time   Execution time\n";
for(i=0;i<n;i++)
{
ob[i].display();
}
swap(n);
cout<<"\n";
cout<<"Id   Arrival time   Execution time\n";
for(i=0;i<n;i++)
{
ob[i].display();
}

calc(n,timeslice);
cout<<"Id   Waiting time   Turnaround time\n";
for(i=0;i<n;i++)
{
ob[i].displayrr();
}

return 0;
}



void calc(int no,int ts)
{
int i=0;
int remain=no;
int flag;
int time;
for(time=0,i=0;remain!=0;)
{
if(ob[i].return_remain()<=ts && ob[i].return_remain()>0)
{
time+=ob[i].return_remain();
ob[i].setremain(0);
flag=1;
}
else if(ob[i].return_remain()>0)
{
ob[i].setremain(ob[i].return_remain()-ts);
time+=ts;
}
if(ob[i].return_remain()==0 && flag==1)
{
remain--;
ob[i].setturn(time-ob[i].return_arrive());
ob[i].setwaiting(time-ob[i].return_arrive()-ob[i].return_execute());
flag=0;
}
if(i==no-1)
i=0;
else if(ob[i+1].return_arrive()<=time)
i++;
else 
i=0;
}
}


