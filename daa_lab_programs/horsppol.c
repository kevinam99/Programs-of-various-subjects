#include<stdio.h>
#include<time.h>
#include<string.h>

int table[200];
shifttable(char p[],int m)
{
	int j;
	for(j=0;j<200;j++)
		table[j]=m;
	for(j=0;j<m-1;j++)
		table[p[j]]=m-1-j;
}
	

int horspool(char p[],int m,char t[],int n)
{
	shifttable(p,m);
	int i=m-1;
	while(i<n)
	{
		int k=0;
		while((k<m)&&(t[i-k]==p[m-1-k]))
		{
			k=k+1;
		}
		if(k==m)
			return (i-m+1);
		else
			i=i+table[t[i]];
	}
	return -1;
}

void main()
{
	char text[80],pattern[80];
	printf("\nEnter Text: ");
	gets(text);
	printf("\nEnter Pattern: ");
	gets(pattern);
	int lp=strlen(pattern);
	int lt=strlen(text);
	int p=horspool(pattern,lp,text,lt);
	
	if(p==-1)
		printf("\nPattern Not Found\n");
	else
		printf("\nPattern Found at Position %d \n",p+1);
}
