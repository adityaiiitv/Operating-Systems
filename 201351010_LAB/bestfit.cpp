#include<iostream>
using namespace std;
int main()
{
	int p,b;
	cout<<"\n enter the number of processes: ";
	cin>>p;
	cout<<"\n enter the number of blocks: ";
	cin>>b;
	int pro[p],block[b];
	for(int i=0;i<p;i++)
	{
		cout<<"\n enter the size of process: "<<i;
		cin>>pro[i];
	}
	for(int i=0;i<b;i++)
	{
		cout<<"\n enter the size of block: "<<i;
		cin>>block[i];
	}
	int pos;
	for(int i=0;i<p;i++)
	{
		int min=1000;
		for(int j=0;j<b;j++)
		{
			if(pro[i]<=block[j])
			{
				int t=block[j]-pro[i];
				if(t<min)
				{min=t;pos=j;}
			}
		}
		block[pos]=min;
		if(block[pos]!=1000)
		{
			cout<<"process: "<<i<<" will be stored in block: "<<pos;
			cout<<"\n";
			cout<<"block:"<<pos<<" has"<< block[pos]<<" memory left.\n";
		}
		if(block[pos]==1000)
		{cout<<"\n process: "<<i<<" will not be stored";}
	}
	return 0;
}
