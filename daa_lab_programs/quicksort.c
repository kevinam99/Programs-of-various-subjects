#include<stdio.h>


int partition(int a[],int l,int h)
{
	int i,j,k,temp,v;
	i=l+1;
	j=h;
	v=a[l];
	while(i<=j)
	{
		while(a[i]<=v)
			i++;
		while(a[j]>v)
			j--;	
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[l];
	a[l]=a[j];
	a[j]=temp;
	return j;
}

void quicksort(int a[],int l,int h)
{
	int p;
	if(l<h)	
	{			
		p=partition(a,l,h);
		quicksort(a,l,p-1);
		quicksort(a,p+1,h);
		
	}
}
void main()
{
	int a[10],flag,i,j,n,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("after sort\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}