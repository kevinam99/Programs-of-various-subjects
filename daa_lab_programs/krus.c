#include<stdio.h>

void main()
{
	int ne=1,n,i,j,a[10][10],a1,b1,u,v,min,mincost=0,visited[10],parent[10];
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
		parent[i]=0;
	}
	visited[1]=1;
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i][j]<min)
				{
					if(visited[i]!=0)
					{
						min=a[i][j];
						a1=u=i;
						b1=v=j;
					}
							
				}
			}
		}
		while(parent[u])
			u=parent[u];
		while(parent[v])
			v=parent[v];
		if(u!=v)
		{
					printf("edge %d from %d to %d with wgt %d\n",ne++,a1,b1,min);
					mincost+=min;
					visited[v]=1;
					parent[v]=u;
		}
		a[a1][b1]=a[b1][a1]=999;
			
		
	}
	/*for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}*/

}