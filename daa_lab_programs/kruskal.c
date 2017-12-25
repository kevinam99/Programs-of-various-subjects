//Kruskal's Algorithm
#include<stdio.h>

int a,b,u,v,n,i,j,ne=1;

int visited[10]={0},min,min_cost=0,cost[10][10];
int parent[10]={0};
void main()

{

	//clrscr();

	printf("\nEnter the number of nodes:");
 	scanf("%d",&n);
 	printf("\nEnter the Weight matrix:\n");
 	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
 		{
 			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
 				cost[i][j]=999;
 		}
	for(i=1;i<=n;i++)
		parent[i]=0;
	printf("\nMinimum Spanning Tree is:-\n");
	while(ne<n)
	{
		min=999;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
		while(parent[u])
			u=parent[u];
		while(parent[v])
			v=parent[v];
		if(u!=v)
		{
			printf("Edge %d\t (%d -> %d)= %d\n",ne++,a,b,min);
			min_cost=min_cost+min;
			parent[v]=u;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\nMinimum Cost = %d\n",min_cost);
}




