#include<stdio.h>


void merge(int a[],int l,int mid,int h)
{
	int i,j,k,b[1000];
	i=l;
	j=mid;
	k=l;
	while(i<=mid && j<=h)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];	
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=h)
		b[k++]=a[j++];
	for(k=l;k<h;k++)
		a[k]=b[k];
}

void mergesort(int a[],int l,int h)
{
	int mid;
	if(l>h)	
		return;		
	mid=(l+h)/2;
	mergesort(a,l,mid);
	mergesort(a,mid+1,h);
	merge(a,l,mid,h);

}
void main()
{
	int a[10],flag,i,j,n,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n);
	printf("after sort\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}