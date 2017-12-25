#include<stdio.h>

int i=1,g=1;

void gcd(int m,int n)
{
	if((i<=m)&&(i<=n))
	{
		if((m%i==0)&&(n%i==0))
			g=i;
		i++;
		gcd(m,n);
	}
}

void main()
{
	int x,y;
	printf("Enter two Numbers:-\n");
	printf("Enter First Number:");	
	scanf("%d",&x);
	printf("Enter Second Number:");	
	scanf("%d",&y);
	gcd(x,y);
	printf("\nGCD of %d and %d = %d\n",x,y,g);
}
