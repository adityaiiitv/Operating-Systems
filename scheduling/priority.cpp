#include<iostream>
using namespace std;
class priority
{
int id,arrive,burst,prior,waiting,turnaround;
public:
void get()
{
cout<<"\nEnter process ID: ";
cin>>id; 
cout<<"\nEnter the Priority: ";
cin>>prior;
cout<<"\nEnter the arrival time: ";
cin>>arrive;
cout<<"\nEnter the execution time: ";
cin>>burst;
}

void display()
{
cout<<id<<"\t   "<<prior<<"\t    "<<arrive<<"\t          "<<burst<<"\n";
}

void displayp()
{
cout<<id<<"\t  "<<prior<<"\t        "<<waiting<<"\t       "<<turnaround<<"\n";
}

int return_arrive()
{
return arrive;
}

int return_burst()
{
return burst;
}

int return_priority()
{
return prior;
}

void setwaiting(int wait)
{
waiting=wait;
}

void setturn(int ta)
{
turnaround=ta;
}

}ob[10],temp;

void swap(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if((ob[j].return_arrive())==(ob[j+1].return_arrive()))
			{
				if((ob[j].return_priority())>(ob[j+1].return_priority()))
				{
					temp=ob[j];
					ob[j]=ob[j+1];
					ob[j+1]=temp;
				}
			}
			else if((ob[j].return_arrive())>(ob[j+1].return_arrive()))
			{
				temp=ob[j];
				ob[j]=ob[j+1];
				ob[j+1]=temp;
			}
		}
	}
}


void swap_main(int n)
{
int time;
int i,k,j;
time=ob[0].return_burst();
int startcounter=1;
int endcounter=1;
int clone;
for(i=1;i<n;i++)
{
clone=i;
startcounter=i;
endcounter=i;
while(endcounter<n)
{
if(ob[clone].return_arrive()<=time)
{
++endcounter;
++clone;
}
else
break;
}

for(j=startcounter;j<endcounter;j++)
{
   for(k=startcounter;k<endcounter-1;k++)
	{
		if(ob[k].return_priority()>ob[k+1].return_priority())
		{
				temp=ob[k];
				ob[k]=ob[k+1];
				ob[k+1]=temp;
		}
	}
}

time+=ob[i].return_burst();
}
}


void calc(int n)
{
int sum=0;
int i,k;
for(i=0;i<n;i++)
{
sum=0;
for(k=0;k<i;k++)
{
sum+=ob[k].return_burst();
}
sum=sum-ob[i].return_arrive();
ob[i].setwaiting(sum);
}


for(i=0;i<n;i++)
{
sum=0;
for(k=0;k<=i;k++)
{
sum+=ob[k].return_burst();
}
sum=sum-ob[i].return_arrive();
ob[i].setturn(sum);
}
}



int main()
{
	int i,no;
	cout<<"Priority Scheduling (Non Preemptive)\n";
	cout<<"Enter the no. of processes: ";
	cin>>no;
	cout<<"\nEnter the processes:\n";
	for(i=0;i<no;i++)
	{
		ob[i].get();
		cout<<"\n";
	}
	cout<<"\nThe Processes entered are \n";
	cout<<"ID    Priority    Arrival time   Execute time\n";
	for(i=0;i<no;i++)
	{
		ob[i].display();
	}
	swap(no);
	cout<<"\nThe Processes entered are \n";
        cout<<"ID    Priority    Arrival time   Execute time\n";
	for(i=0;i<no;i++)
	{
		ob[i].display();
	}
	swap_main(no);
	cout<<"ID    Priority    Arrival time   Execute time\n";
	for(i=0;i<no;i++)
	{
		ob[i].display();
	}
	calc(no);
        cout<<"\nThe Processes entered are \n";
        cout<<"ID    Priority    Waiting Time   Turnaround time\n";
	for(i=0;i<no;i++)
	{
		ob[i].displayp();
	}


	
}
	

