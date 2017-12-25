//Warshall's Algorithm
#include<stdio.h>

int n,i,j,k;




void warshall(int a[10][10])
{
	for(k=0;k<n;k++)	
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);

	
}	


void main()
{
	
	int a[10][10];
	printf("\nEnter No. of Nodes: ");
	scanf("%d",&n);
	printf("\nEnter Adjacency Matrix:-\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
			
	printf("\nAdjacency Matrix is :-\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}

	warshall(a);
	printf("\nTransitive Closure is:-\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	
		
	
}
