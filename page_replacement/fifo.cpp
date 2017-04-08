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
    int avail,miss=0;
    int j=0;
    for(int i=0;i<num;i++)
    {
        avail=0;
        cout<<"PAGE NUMBER: "<<page[i]<<"\t\t";
        for(int k=0;k<fr;k++)
        {
            if(frame[k]==page[i])
            avail=1;
        }
        cout<<" ALL FRAMES: ";
        if(avail==0)
        {
            frame[j]=page[i];
            j=(j+1)%fr;
            miss++;
            for(int k=0;k<fr;k++)
            {
                cout<<frame[k]<<"  ";
            }
        }
        cout<<"\n";
    }
    cout<<"\nTotal miss: "<<miss;
    cout<<"\nTotal hits: "<<num-miss;
return 0;
}
