//Bubble Sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	long int n,i,j,f;
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
	for(i=0;i<n-1;i++)
	{
		f=1;
		for(j=0;j<n-1-i;j++)
			if(a[j]>a[j+1])
			{
				long int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				f=0;
			}
		if(f)
			break;
	}
	end=clock();
	double totaltime=(double)(end-start)/CLOCKS_PER_SEC;
	printf("\nSorted Array:-\n");
	for(i=0;i<n;i++)
		printf("%ld\t",a[i]);

	printf("\nTotal Time taken = %lf\n",totaltime);
}
