#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node* link;
}node;

node *start=NULL;

void insert(int item)
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->info=item;
	if(start==NULL)
	{
		newnode->link=NULL;
		start=newnode;
		printf("\nNew node Inserted");
		return;
	}
	if(item<start->info)
	{
		newnode->link=start;
		start=newnode;
		printf("\nNew node Inserted");
		return;
	}
	node *temp=start;
	while(temp->link!=NULL)
	{
		if(item<temp->link->info)
		{
			newnode->link=temp->link;
			temp->link=newnode;
			printf("\nNew node Inserted");
			return;
		}
		temp=temp->link;
	}
	temp->link=newnode;
	newnode->link=NULL;
	printf("\nNew node Inserted");
	return;
}


void disp()
{
	if(start==NULL)
	{
		printf("\nOLL Empty");
		return;
	}
	node *temp=start;
	printf("\nOLL Contents are:-\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->link;
	}
}

void main()
{
	int c,i;
	do
	{
		printf("\n**MENU**\n");
		printf("\n1.Insert\n2.Display\n3.Exit\n");
		printf("Enter Your Choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter Element to be Inserted:");
				scanf("%d",&i);
				insert(i);
				break;
			case 2:
				disp();
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("\nWrong Choice!Try Again!\n");
		}
	}while(c!=3);
}
