#include<stdio.h>
#include<ctype.h>

char a[20];
#define SIZE 20
int top=-1;

void push(char c)
{
	if(top==(SIZE-1))
		printf("\nStack Overlow.\n");
	else
	{
		top++;
		a[top]=c;
	}
}

char pop()
{
	char c;
	if(top==-1)
		printf("\nStack Underflow.\n");
	else
	{
		c=a[top];
		top--;
	}
	return c;
}

int check(char c)
{
	if(c=='(')
		return 0;
	else if((c=='+')||(c=='-'))
		return 1;
	else if((c=='*')||(c=='/'))
		return 2;
	else if((c=='^')||(c=='%'))
		return 3;
}

void main()
{
	char infix[20];
	char postfix[20];
	printf("\nEnter Infix Expression:");
	scanf("%s",infix);
	int i=0,j=0;
	char ch=infix[i];
	while(infix[i]!='\0')
	{
		ch=infix[i++];		
		if(ch=='(')
			push(ch);
		else if(isalnum(ch))
			postfix[j++]=ch;
		else if(ch==')')
		{	
			
			while(a[top]!='(')
			{
				postfix[j++]=pop();
			}
			top--;
		}
		else
		{
			if(top!=-1)
			{	while(check(a[top])>=check(ch))
				{
					postfix[j++]=pop();
				}
			}	
			push(ch);
			
		}
	}
	while(top!=-1)
	{
		postfix[j++]=pop();
	}
	postfix[j]='\0';
	printf("\nPostfix Expression: %s\n",postfix);
}	
