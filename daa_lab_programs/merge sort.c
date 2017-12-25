//Merge Sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(long int a[],long int low,long int mid,long int high)
{
	long int i=low,j=mid+1,k=low;
	long int b[100000];
	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=high)
		b[k++]=a[j++];
	for(k=low;k<=high;k++)
		a[k]=b[k];
}

void mergesort(long int a[],long int low,long int high)
{
	long int mid;
	if(low>=high)
		return;
	mid=(low+high)/2;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a,low,mid,high);
}


void main()
{
	long int n,i,j;
	clock_t start,end;
	printf("\nEnter No. of Elements: ");
	scanf("%ld",&n);
	long int a[n];
	printf("\nEnter the Elements in the Array:-\n");
	for(i=0;i<n;i++)
		a[i]=rand();
	printf("\nUnsorted Array:-\n");
	for(i=0;i<n;i++)
		printf("%ld\t",a[i]);
	start=clock();
	mergesort(a,0,n-1);
	end=clock();
	double totaltime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("\nSorted Array:-\n");
	for(i=0;i<n;i++)
		printf("%ld\t",a[i]);
	printf("\n");
	printf("\nTotal Time taken= %lf\n",totaltime);

	


}

