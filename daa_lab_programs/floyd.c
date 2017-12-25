#include<stdio.h>

int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}
void warshall(int a[10][10],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				a[i][j]= min(a[i][j],(a[i][k]+a[k][j]));
			}
		}
	}

}

void main()
{
	int a[10][10],n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	warshall(a,n);

	printf("after sorting \n ");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}