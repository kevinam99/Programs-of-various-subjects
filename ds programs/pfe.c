#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define SIZE 20 
int a[20];
char s[20];
int l,top=-1;

void push(int x)
{
	
	if(top==SIZE-1)
		printf("\nStack Overflow.\n");
	else
	{
		
		top++;
		a[top]=x;
	}
}

int pop()
{
	if(top==-1)
	{
		printf("\nStack Underflow\n");
		return -1;
	}
	else
	{
		int y=a[top];
		top--;
		return y;
	}
}

void display()
{
	if(top==-1)
		printf("\nStack Empty\n");
	else
	{
		int i;
		for(i=top;i>=0;i--)
			printf("\n%d",a[i]);
	}
}

void main()
{
	char c;
	printf("\nEnter Postfix Expression:");
	scanf("%s",s);
	int i=0,op1,op2;
	while(s[i]!='\0')
	{
		c=s[i];
		if(isdigit(c))
			push(c - '0');
		else if(!isspace(c))
		{
			op2=pop();
			op1=pop();
			switch(c)
			{
				case '+': push(op1+op2); break;
				case '-': push(op1-op2); break;
				case '*': push(op1*op2); break;
				case '/': push(op1/op2); break;
				case '^': push(pow(op1,op2)); break;			
			}
			
		}
		else
			top++;
	i++;
	}
	printf("\nResult=%d\n",a[top]);
	


}

























