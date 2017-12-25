#include<stdio.h>

int board[10],n;

void print()
{	
	int i,j;
	printf("the solution is \n");
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			if(board[i]==j)
				printf("Q ");
			else
				printf("- ");
		}
		printf("\n");
	}

}

void print1()
{
	int k;
	printf("inside print1 %d \n",n);
	for(k=1;k<=n;k++)
	{
		printf("inside for");
	}	
	printf("outside print1");
}

int place(int row,int column)
{
 int i;
  for(i=1;i<=row-1;++i)
 {
  //checking column and digonal conflicts
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
 }
 
 return 1; //no conflicts
}


void queen(int row,int n)
{
	int i;
	for(i=1;i<=n;++i)
	{
		if(place(row,i))
		{
			board[row]=i;
			if(row==n)
			{	
				//printf("inside print %d ", n);
				//print1();
				print();
			}
			else
				queen(row+1,n);
		}
	
	}

}


void main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		board[i]=0;
	queen(1,n);
}
