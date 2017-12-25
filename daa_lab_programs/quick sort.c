#include<stdio.h>
#include<time.h>


long int partition(long int a[],long int l,long int r)
{
	long int i,j,p;
	i=l+1;
	j=r;
	p=a[l];
	while(i<=j)
	{
		while(a[i]<=p && i<=r)
			i++;
		while(a[j]>p && j>=l)
			j--;
		if(i<j)
		{
			long int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}

	long int temp=a[l];
	a[l]=a[j];
	a[j]=temp;

	return j;
}
			
			

void quicksort(long int a[],long int l,long int r)
{
	long int s;
	if(l<r)
	{
		s=partition(a,l,r);
		quicksort(a,l,s-1);
		quicksort(a,s+1,r);
	}
}

void main()
{
	long int n,i;
	clock_t start,end;
	printf("\nEnter No. of Elements:");
	scanf("%ld",&n);
	long int a[n];
	//printf("\nEnter Elements in the Array:-\n");
	for(i=0;i<n;i++)
		a[i]=rand();
	start=clock();
	quicksort(a,0,n-1);
	end=clock();
	double totaltime=(double)(end-start)/CLOCKS_PER_SEC;
/*	printf("\nSorted Array:-\n");
	for(i=0;i<n;i++)
		printf("%ld\t",a[i]);

*/	printf("\n\nTotal Time= %lf\n",totaltime);	
}
