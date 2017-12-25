#include<stdio.h>

int rear=-1,front=-1,queue[10];
int a[10][10],v[10];
int isempty()
{
	if(front==-1)
		return 1;
	return 0;
}

void insert(int i)
{
	if(front==-1)
		front++;
	//rear++;
	queue[++rear]=i;	
}

void delete()
{
	//int x;
	if(front==rear)
		front=rear=-1;
	else
		front++;
	//return x;
}

void bfs(int z,int n)
{
	int k;
//	printf("%d ",z);
	v[z]=1;
	insert(z);	
	while(!isempty())
	{	int y=queue[front];
		for(k=1;k<=n;k++)
		{
			if(a[y][k]==1 && v[k]==0)
			{	
				v[k]=1;
				//printf("%d ",k);
				insert(k);
			}
		}		
		delete();
	}
	
}
		
void main()
{
	int n,i,j;
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
		v[i]=0;
	}
	/*for(i=1;i<=n;i++)
	{
		if(v[i]==0)
			bfs(i,n);
	}*/	
	printf("\n\n");
	//for(i=1;i<=n;i++)
	//{
	//	if(v[i]==0)
			bfs(3,n);
	//}
	for(i=1;i<=n;i++)
	{
		if(v[i]==1)
			printf("%d is reachable\n",i);
		else
			printf("%d is not reachable\n",i);
	}
}
