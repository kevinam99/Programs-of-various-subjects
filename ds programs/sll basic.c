#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int info;
	struct node* link;
}node;

node *start=NULL;

void insert_beg(int item)
{
	node *newnode=(node *)malloc(sizeof(node));
	newnode->info=item;
	if(start==NULL)
		newnode->link=NULL;
	else
		newnode->link=start;
	start=newnode;
	printf("\nItem Inserted");
}

void del_beg()
{
	if(start==NULL)
	{
		printf("\nSLL Underflow");
		return;
	}	
	if(start->link==NULL)
	{
		printf("\nItem deleted is %d ",start->info);
		free(start);
		start=NULL;
		return;
	}
	node *temp=start;
	start=start->link;
	printf("\nItem deleted is %d ",temp->info);			
	free(temp);
}

void insert_end(int item)
{
	node *newnode=(node *)malloc(sizeof(node));
	newnode->info=item;
	if(start==NULL)
	{
		newnode->link=NULL;
		start=newnode;
		printf("\nItem Inserted");
		return;
	}
	node *temp=start;
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=newnode;
	newnode->link=NULL;
	printf("\nItem Inserted");
}

void del_end()
{
	if(start==NULL)
	{
		printf("\nSLL Underflow");
		return;
	}	
	if(start->link==NULL)
	{
		printf("\nItem deleted is %d ",start->info);
		free(start);
		start=NULL;
		return;
	}
	node *temp=start;
	while(temp->link->link!=NULL)
	{
		temp=temp->link;
	}
	printf("\nItem deleted is %d ",temp->link->info);
	free(temp->link);
	temp->link=NULL;
	return;
}

void insert_position(int item,int pos)
{

	node *newnode=(node *)malloc(sizeof(node));
	newnode->info=item;
	if((pos==1)&&(start==NULL))
	{
		newnode->link=NULL;
		start=newnode;
		printf("\nItem Inserted");
		return;
	}
	if((pos==1)&&(start->link==NULL))
	{
		newnode->link=start;
		start=newnode;
		printf("\nItem Inserted");
		return;
	}
	if((pos==1)&&(start->link!=NULL))
	{
		newnode->link=start;
		start=newnode;
		printf("\nItem Inserted");
		return;
	}
	node *temp=start;
	int c=1,flag=0;
	while(temp!=NULL)
	{
		if(c+1==pos)
		{
			newnode->link=temp->link;
			temp->link=newnode;
			printf("\nItem Inserted");
			return;
		}
		c++;
		temp=temp->link;
	}
	if(flag==0)
		printf("\nInvalid Position!");

}

void del_position(int pos)
{
	if(start==NULL)
	{
		printf("\nSLL Underflow");
		return;
	}
	if((pos==1)&&(start->link==NULL))
	{
		printf("\nItem deleted is %d ",start->info);
		free(start);
		start=NULL;
		return;
	}
	if((pos==1)&&(start->link!=NULL))
	{
		node *temp=start;
		start=start->link;
		printf("\nItem deleted is %d ",temp->info);
		free(temp);
		return;
	}
	node *temp=start;
	int c=1,flag=0;
	while(temp->link!=NULL)
	{
		if(c+1==pos)
		{
			node *del=temp->link;
			temp->link=temp->link->link;
			printf("\nItem deleted is %d ",del->info);
			free(del);
			return;
		}
		c++;
		temp=temp->link;
	}
	if(flag==0)
		printf("\nInvalid Position!");

}

void disp()
{
	node *temp=start;
	if(temp==NULL)
	{
		printf("\nSLL Empty");
		return;
	}
	printf("\nSLL contents are:-\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->link;
	}
}

void main()
{
	int c,i,p;
	do
	{	
		printf("\n**MENU**\n");
		printf("1.Insert at Beginning\n2.Deletion at Beginning\n3.Insert at End\n4.Deletion at End");
		printf("\n5.Insertion at given Position\n6.Delete from given Position\n7.Display\n8.Exit\n");
		printf("Enter your Choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("\nEnter Element to be Inserted:");
				scanf("%d",&i);
				insert_beg(i);
				break;
			case 2:
				del_beg();
				break;
			case 3:
				printf("\nEnter Element to be Inserted:");
				scanf("%d",&i);
				insert_end(i);
				break;
			case 4:
				del_end();
				break;
			case 5:
				printf("\nEnter Element to be Inserted:");
				scanf("%d",&i);
				printf("\nEnter Position where Element is to be Inserted:");
				scanf("%d",&p);
				insert_position(i,p);
				break;	
			case 6:
				printf("\nEnter Position from where Element is to be Deleted:");
				scanf("%d",&p);
				del_position(p);
				break;	
			case 7:
				disp();
				break;
			case 8:
				exit(0);
				break;
			default:
				printf("Wrong Choice!Try Again!\n");
		}
	}while(c!=8);
}
