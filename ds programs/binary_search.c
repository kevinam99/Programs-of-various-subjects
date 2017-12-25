#include<stdio.h>
int flag=0,s,mid=0;

void bs(int a[10],int c,int first,int last)
{
	
	if(mid==(first+last)/2)
		return;
	mid=(first+last)/2;
	if(c==a[mid])
	{
		printf("\nElement found At position %d\n",mid+1);
		flag++;
		return;
	}
	if(first==last)
		return;
	else if(c<a[mid])
		bs(a,c,first,mid);
	else if(c>a[mid])
		bs(a,c,mid,last);
}

void main()
{
	int i,x;
	printf("\nEnter Size of Array:");
	scanf("%d",&s);
	printf("\nEnter Elements in Ascending Order:-\n");
	int b[s];
	for(i=0;i<s;i++)
		scanf("%d",&b[i]);
	printf("\nEnter element to be searched:");
	scanf("%d",&x);
	bs(b,x,0,s);
	if(!flag)
		printf("\nElement NOT found\n");
}

