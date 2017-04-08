#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int fr,num;
    cout<<"ENTER THE NUMBER OF FRAMES: ";
    cin>>fr;
    int frame[fr];
    for(int i=0;i<fr;i++)
    {
        frame[i]=-1;
    }
    cout<<"\nENTER THE NUMBER OF PAGES: ";
    cin>>num;
    int page[num];
    cout<<"\nENTER THE PAGE INDICES: \n";
    for(int i=0;i<num;i++)
    {
        cin>>page[i];
    }
    int miss=0;
    for(int i=0;i<num;i++)
    {
		int found=0;
		for(int j=0;j<fr;j++)
		{
			if(page[i]==frame[j])
			{found=1;}
		}
		int minus=0;
		for(int j=0;j<fr;j++)
		{
			if(frame[j]==-1 && found ==0)
			{
				miss++;
				minus=1;
				frame[j]=page[i];
				break;
			}
		}
		//
		if(minus==0 && found ==0)
		{
			int match=0;
			for(int j=0;j<fr;j++)
			{
				if(page[i]==frame[j])
				{
					match=1;
				}
			}
			if(match==0)
			{
				miss++;
				int dist[fr];
				for(int j=0;j<fr;j++)
				{dist[j]=0;}
				for(int k=0;k<fr;k++)
				{
					int flag=0;
					for(int j=i-1;j>=0;j--)
					{
						if(page[j]==frame[k] && flag==0)
						{dist[k]=(i-j);flag=1;}
					}
				}
				int max=dist[0],pos=0;
				for(int j=0;j<fr;j++)
				{
					if(dist[j]>max)
					{
						max=dist[j];pos=j;
					}
				}
		
				frame[pos]=page[i];
			}}
			for(int l=0;l<fr;l++)
			{
				cout<<frame[l]<<" ";
			}
			cout<<"\n";
		//
		}
		cout<<"\n misses are: "<<miss;
	
return 0;
}
