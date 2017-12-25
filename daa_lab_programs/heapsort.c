#include<stdio.h>

void heapsort(int h[],int n)
{
	int i,n1,j,v,k,heap;
	n1=n;
	for(i=n1/2;i>=1;i--)
	{
		k=i;
		v=h[k];
		heap=0;
		while(!heap && (2*k)<=n1)
		{
			j=2*k;
			if(j<n1 && h[j]<h[j+1])
				j=j+1;
			if(v>h[j])
				heap=1;
			else
			{
				h[k]=h[j];
				k=j;		
			}
			h[k]=v;
		}
	}

}

void main()
{

	int h[10],i,n,t,size;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}
	heapsort(h,n);
	size=n;
	for(i=n;i>=1;i--)
	{
		t=h[1];
		h[1]=h[i];
		h[i]=t;
		size=size-1;
		heapsort(h,size);
	}
	for(i=1;i<=n;i++)
	{
		printf("%d ",h[i]);
	}
	
}