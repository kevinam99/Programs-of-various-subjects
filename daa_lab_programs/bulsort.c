#include<stdio.h>

void main()
{
	int a[10],flag,i,j,n,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}	
		}
		if(flag==0)
		{
			break;	
		}
	}	
	printf("after sort\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}