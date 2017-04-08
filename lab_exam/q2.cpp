#include<iostream>
using namespace std;
int main()
{
	int p,b;
	cout<<"\n enter the number of processes: ";
	cin>>p;
	cout<<"\n enter the number of blocks: ";
	cin>>b;
	int size[p],block[b];
	for(int i=0;i<p;i++)
	{
		cout<<"\n enter the size of process: "<<i;
		cin>>size[i];
	}
	for(int i=0;i<b;i++)
	{
		cout<<"\n enter the size of block: "<<i;
		cin>>block[i];
	}
	int pos=0;
		for(int i=0;i<p;i++)
		{
			int flag=0;
			for(int j=0;j<b;j++)
			{
				if(block[pos]>=size[i] && flag==0)
				{
					block[pos]=block[pos]-size[i];
					cout<<"\n process: "<<i<<" is stored in block: "<<pos;
					flag=1;
					pos++;
					pos=pos%b;
				}
				if(flag==0)
				{
					pos++;pos=pos%b;
				}
				
			}
			if(flag==0)
			{cout<<"no fit for process: "<<i;}
		}
	
	return 0;
}
