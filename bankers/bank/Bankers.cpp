#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
  {
     int i,l,j,n,flag,m,pnum,count,safe=0,completed,counter=0;

     cout<<"This is the code for bankers algorithm\n";
     cout<<"----------------------------------------\n";
     cout<<"Enter the number of processes\n";
     cin>>n;
     cout<<"Enter the number of resource types\n";
     cin>>m;
     int tot_ins_res[m],rnum[m],k[m],Available[m],Work[m],Finish[n],safe_sequence[n];
     int Max[n][m],Alloc[n][m],Need[n][m];
     for(j=0;j<m;j++)
       {
          cout<<"Please enter the total number of instances of resource"<<j<<endl;
          cin>>tot_ins_res[j];
          Available[j]=0;
           }  
     cout<<"Please enter the maximum number of resources required by each process\n";
     for(i=0;i<n;i++)
       {
          for(j=0;j<m;j++)
            {
               cout<<"Enter the max number of instances required by process"<<i<<"of resource \n"<<j; 
               cin>>Max[i][j];
                 }
            } 
     for(i=0;i<n;i++)
       {
          for(j=0;j<m;j++)
            {
               cout<<"Enter the allocated number of instances to  process"<<i<<"of resource \n"<<j; 
               cin>>Alloc[i][j];
                 }
            } 
     for( i=0;i<n;i++)
       {
          for(j=0;j<m;j++)
            {
              Need[i][j]=Max[i][j]-Alloc[i][j];
                }
            }
     for( j=0;j<m;j++)
       {
          int sum=0;
          for(i=0;i<n;i++)
            {
              sum=sum+Alloc[i][j];
               }
          
              if(tot_ins_res[j]-sum>=0)
                Available[j]=tot_ins_res[j]-sum;
              else  
                Available[j]=0;
                 
            } 
     for(j=0;j<m;j++)
       {
          cout<<"Available instances of resource"<<j<<"are \n";
          cout<<Available[j];
            }
    cout<<"Enter the process number for which you want to make a request\n";
    cin>>pnum;
    for(i=0;i<m;i++)
      {
         cout<<"Enter the resource number\n";
         cin>>rnum[i];
         cout<<"Enter the number of instances required\n";
         cin>>k[i];
          }
    for(l=0;l<m;l++)
     {
        flag=1;
    if(k[l]>Need[pnum][rnum[l]])
      {
         cout<<"Error\n";
         flag=0;
          }
    else if(k[l]>Available[rnum[l]])
           {
             cout<<"You will have to wait\n";
             flag=0;
              }
    if(flag==1)    
      {
        Available[rnum[l]]-=k[l];
        Alloc[pnum][rnum[l]]+=k[l];
        Need[pnum][rnum[l]]-=k[l];
         
    for(i=0;i<m;i++)
      Work[i]=Available[i];
    for(i=0;i<n;i++)     
      Finish[i]=1;
    count=n;  
   while(count) 
     {
        safe=0;
        for(i=0;i<n;i++) 
          {
            if(Finish[i])
              { 
                 completed=1;
                 for(j=0;j<m;j++)
                   { 
                 
                  if(Need[i][j]>Work[j])
                     {
                       completed=0;
                       break; 
                        }
                          }
            if(completed)
              {
                 Finish[i]=0;
                 safe=1;
                 safe_sequence[counter]=i;
                 counter++; 
                 count--;
                 for(j=0;j<m;j++)
                   {
                      Work[j]+=Alloc[i][j];
                     
                        }
                  }
                 }
                }
          if(!safe)
          break;
           }
         
          }
         
         if(!completed)
         cout<<"Not in safe state\n";
           break;
        }
      if(safe)
        { 
          cout<<"System is in safe state\n";
          cout<<"Safe sequence is\n";
          for(i=0;i<counter;i++)
            {
              cout<<safe_sequence[i]<<endl;
                }
            } 
     return 0;
      }

