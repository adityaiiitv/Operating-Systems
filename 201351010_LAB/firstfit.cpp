#include<iostream>
using namespace std;
int main()
{
	int p,b;
	cout<<"\n enter the number of processes: ";
	cin>>p;
	cout<<"\n enter the number of blocks: ";
	cin>>b;
	int size[p],block[b],flag=0;
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
	
		for(int i=0;i<p;i++)
		{
			flag=0;
			for(int j=0;j<b;j++)
			{
				if(block[j]>=size[i] && flag==0)
				{
					block[j]=block[j]-size[i];
					flag=1;
					cout<<"\n process: "<<i<<" is stored in block: "<<j;
					break;
				}
			}
			if(flag==0)
			{cout<<"no fit";}
		}
	
	return 0;
}
