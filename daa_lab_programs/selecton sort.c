//Selection Sort
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
	int n,i,j;
	clock_t start,end;
	printf("\nEnter No. of Elements: ");
	scanf("%d",&n);
	int a[n];
	//printf("\nEnter the Elements in the Array:-\n");
	for(i=0;i<n;i++)
		a[i]=rand();
	printf("\nUnsorted Array:-\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	start=clock();
	for(i=0;i<n;i++)
	{
		
		for(j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				
			}
	}
	end=clock();
	double totaltime=(double)(end-start)/CLOCKS_PER_SEC;
	
	printf("\nSorted Array:-\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\nTotal Time taken= %lf\n",totaltime);

}

