#include <stdio.h>

int weight[10],values[10],k[10][100];
int max(int x,int y)
{
    if(x>y)
        return x;
    return y;        
}
int knapsack(int i,int j)
{
    if(k[i][j]<0)
    {
        if(j<weight[i])
        {
            k[i][j]=knapsack(i-1,j);
        }
        else
        {
            k[i][j]=max(knapsack(i-1,j),knapsack(i-1,j-weight[i])+values[i]);
        }
    }
    return k[i][j];
}

void optimal_set(int c,int n)
{
int x[10],i,j,sum;
for(i=0;i<n;i++)
x[i]=0;

i=n;
j=c;
while(i>0&&j>0)
{
 if(k[i][j]!=k[i-1][j])
 {
printf("in %d %d %d\t\n",j,i,weight[i-1]);
  x[i]=1;
  j=j-weight[i];
  //printf("%d %d\t",j,i);
 }
printf("out %d %d\t\n",j,i,weight[i-1]);
i=i-1;
}

printf("\nThe optimal set of items is:\n");
for(i=1;i<=n;i++)
{
 if(x[i]==1)
 {
  printf("%d\t",values[i]);
  sum=sum+values[i];
 }

}
}
int main()
{
    int c;
    printf("enter the capacity\n");
    scanf("%d",&c);
    int n,i,j;
    printf("enter the number of items\n");
    scanf("%d",&n);
    printf("enter the weights of all the items\n");
    for(i=1;i<=n;i++)
    scanf("%d",&weight[i]);
    printf("enter the values of all the items\n");
    for(i=1;i<=n;i++)
    scanf("%d",&values[i]);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=c;j++)
        {
            if(i==0||j==0)
                k[i][j]=0;
            else
                k[i][j]=-1;
        }
    }
    int s=knapsack(n,c);
    printf("soln= %d \n ",s);
    optimal_set(c,n);
    return 0;
}
