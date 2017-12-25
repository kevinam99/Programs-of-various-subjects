//Dijkstra's
#include<stdio.h>

void dijkstra(int source,int cost[20][20],int visited[20],int d[20],int n)
{
	int i,j,u,min,w;
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
		d[i]=cost[source][i];
	}
	visited[source]=1;
	d[source]=0;
	for(j=2;j<=n;j++)
	{
		min=999;
		for(i=1;i<=n;i++)
			if(!visited[i] && d[i]<min)
			{
				min =d[i];
				u=i;
			}
		visited[u]=1;
		for(w=1;w<=n;w++)
			if(cost[u][w]!=999 && visited[w]==0)
				if(d[w]>cost[u][w]+d[u])
					d[w]=cost[u][w]+d[u];
	}
}

void main()
{
	int j,i,n,visited[20],sum=0,cost[20][20],source,d[20];
	printf("\nEnter No. of Vertices: ");
	scanf("%d",&n);
	printf("\nEnter the Cost Adjacency Matrix:-\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);
	printf("\nEnter the Source Node: ");
	scanf("%d",&source);
	dijkstra(source,cost,visited,d,n);
	for(i=1;i<=n;i++)
		if(i!=source)
			printf("\nShortest path from %d to %d is %d \n",source,i,d[i]);
}
