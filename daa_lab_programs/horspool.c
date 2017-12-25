#include<stdio.h>
#include<string.h>

int table[200];
void shifttable(char p[],int lp)
{
	int i,j;
	for(i=0;i<200;i++)
		table[i]=lp;
	for(j=0;j<lp-1;j++)
		table[p[j]]=lp-j-1;

}

int horspool(char p[],int lp,char t[],int lt)
{
	int i,k,m;
	shifttable(p,lp);
	i=lp-1;
	m=lp;
	while(i<lt)
	{
		k=0;
		while(k<m && t[i-k]==p[lp-1-k])
			k++;
		if(k==m)
			return i-m+1;
		else
			i=i+table[t[i]];
	}
	return -1;
}

void main()
{
	char t[100],p[100];
	int lp,lt,k;
	gets(t);
	gets(p);
	lp=strlen(p);
	lt=strlen(t);
	k=horspool(p,lp,t,lt);
	if(k==-1)
		printf("pattern did not match");
	else
		printf("pattern matched at %d ",k+1);	
}