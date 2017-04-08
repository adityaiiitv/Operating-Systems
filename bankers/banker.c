#include<stdio.h>

int main()
{
	printf("\n THIS IS THE PROGRAM FOR BANKER'S ALGORITHM \n");
	int k=0,d=0,t=0,i,p_num,j,res, count=0;
	int P[10],output[10],MAX[10][5],need[10][5],allocated[10][5],avail[5],ins[5];

	printf("\n ENTER THE NUMBER OF RESOURCES : ");
	scanf("%d", &res);
	printf("\n ENTER THE MAX NUMBER OF EACH RESOURCE \n");
	for(i=0;i<res;i++)
	{
		avail[i]=0;
		scanf("%d",&ins[i]);
	}
	printf("\n ENTER THE NUMBER OF PROCESSES : ");
	scanf("%d", &p_num);
	printf("\n ENTER THE ALLOC MATRIX \n     ");
 
	for(i=0;i<res;i++)
	printf("\n");
	for(i=0;i <p_num;i++)
	{   P[i]=i;
		printf("\n");
	for(j=0;j<res;j++)
	{
		scanf("%d",&allocated[i][j]);
		avail[j]+=allocated[i][j];
	}
	}
 
 
	printf("\n ENTER THE MAX MATRIX \n     ");
	for(i=0;i<res;i++)
	{     
		avail[i]=ins[i]-avail[i];
	}
	printf("\n");
	for(i=0;i<p_num;i++)
	{
	printf("\n");
	for(j=0;j<res;j++)
	scanf("%d", &MAX[i][j]);
	}
 
	printf("\n");
	A: d=-1;
	for(i=0;i <p_num;i++)
	{ 	count=0;
		t=P[i];
	for(j=0;j<res;j++)
	{
		need[t][j] = MAX[t][j]-allocated[t][j];
		if(need[t][j]<=avail[j])
		count++;
	}
	if(count==res)
	{
		output[k++]=P[i];
		for(j=0;j<res;j++)
		avail[j]+=allocated[t][j];
	}
	else
	P[++d]=P[i];
	}
 
	if(d!=-1)
	{ 	p_num=d+1;
		goto A;
	}
	printf(" A SAFE SEQUENCE IS: ");
	for(i=0;i<k;i++)
	printf(" P[%d] ",output[i]);

	return 0;
	}
