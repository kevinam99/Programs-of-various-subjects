#include<stdio.h>

void main()
{
	int n,i,j,cost[10][10],d[10],visited[10],u,k,source,min;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	for(i=1;i<=n;i++)
		visited[i]=0;
	visited[1]=1;
	source=1;
	for(i=1;i<=n;i++)
	{
		d[i]=cost[source][i];	
	}
	d[source]=0;
	for(j=2;j<=n;j++)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			if(d[i]<min)
			{
				if(visited[i]!=1)
				{
					min=d[i];
					u=i;
				}
			}
		}
		visited[u]=1;
		for(k=1;k<=n;k++)
		{
			if(d[k]>cost[u][k]+d[u])
				d[k]=cost[u][k]+d[u];
		}		
	}
	for(i=1;i<=n;i++)
	{	
		if(i!=source)
			printf("%d to %d = %d\n",source,i,d[i]);
	}


}