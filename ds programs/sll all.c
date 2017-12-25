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

void insert_after(int item,int given)
{
	
	node *newnode=(node *)malloc(sizeof(node));
	newnode->info=item;
/*
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
*/
	node *temp=start;
	int flag=0;
	while(temp!=NULL)
	{
		if(temp->info==given)
		{
			newnode->link=temp->link;
			temp->link=newnode;
			printf("\nItem Inserted");
			return;
		}
		
		temp=temp->link;
	}
	if(flag==0)
		printf("\nNode NOT Found!");

}

void del_given(int given)
{
	int flag=0;
	if(start==NULL)
	{
		printf("\nSLL Underflow");
		return;
	}	
	if(start->info==given)
	{
		node* temp=start;
		start=start->link;
		printf("\nItem deleted is %d ",temp->info);
		free(temp);
		return;
	}
	node* temp=start;
	while(temp->link!=NULL)
	{
		if(temp->link->info==given)
		{
			node* temp1=temp->link;
			temp->link=temp1->link;
			printf("\nItem deleted is %d ",temp1->info);
			free(temp1);
			return;
		}
		temp=temp->link;
	}
	if(!flag)
		printf("\nGiven Node NOT Found");
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

void deleteinfo(int given)
{
	int flag=0;
	node* temp=start;
	
		while(temp->info==given)
		{
			if(temp->link==NULL)
			{
				free(start);
				start=NULL;
				return;
			}
			start=start->link;
			free(temp);
			temp=start;
			flag++;
		}
		

	
	if(temp->link==NULL)
		return;
	while(temp->link->link!=NULL)
	{
		while(temp->link->info==given)
		{
			node* temp1=temp->link;
			temp->link=temp1->link;
			free(temp1);
			flag++;
			if(temp->link==NULL)
				break;		
		}
		if((temp->link==NULL)||(temp->link->link==NULL))
			break;
		temp=temp->link;
	}
	if((temp->link==NULL)&&(temp->info==given))
	{
		free(temp);
				
		temp=start=NULL;
		flag++;
		return;
	}
	if(temp->link==NULL)
	{
		return;
	}		
	
	if(temp->link->info==given)
	{
		node* temp1=temp->link;
		temp->link=temp1->link;
		free(temp1);
		flag++;
	}
	if(flag==0)
		printf("\nNode not present\n");
}

void del_after(int given)
{
	if(start==NULL)
	{
		printf("\nSLL Underflow");
		return;
	}
	/*
	if((start->info==given)&&(start->link==NULL);
	{
		printf("\nNo Node exists after Given Info");
		return;
	}
	*/
	int flag=0;
	node* temp=start;
	while(temp!=NULL)
	{
		if(temp->info==given)
		{
			if(temp->link==NULL)
			{
				printf("\nNo Node exists after Given Info");
				return;
			}
			node* temp1=temp->link;
			temp->link=temp1->link;
			printf("\nItem Deleted is %d\n",temp1->info);
			free(temp1);
			return;
		}
		temp=temp->link;
	}
	if(!flag)
		printf("\nNode Not Found");
}

void insert_before(int item,int given)
{
	node* newnode=(node*)malloc(sizeof(node));
	newnode->info=item;
	node* temp=start;
	if(start==NULL)
	{
		printf("\nNode Not Found\n");
		return;
	}
	if(start->info==given)
	{
		newnode->link=start;
		start=newnode;
		printf("\nNew Node Inserted");
		return;
	}
	int flag=0;
	while(temp->link!=NULL)
	{
		if(temp->link->info==given)
		{
			newnode->link=temp->link;
			temp->link=newnode;
			printf("\nNew Node Inserted");
			return;
		}
		temp=temp->link;
	}
	if(!flag)
		printf("\nNode not Found\n");
}

void del_before(int given)
{
	if(start==NULL)
	{
		printf("\nSLL Underflow");
		return;
	}
	if(start->info==given)
	{
		printf("\nNo Node exists Before Given Node");
		return;
	}
	if(start->link->info==given)
	{
		node* temp=start;
		start=start->link;
		printf("\nItem Deleted is %d\n",temp->info);
		free(temp);
		return;
	}
	int flag=1;
	node* temp=start;
	node* prev;
	while(temp->link!=NULL)
	{
		if(temp->link->info==given)
		{
			prev->link=temp->link;
			printf("\nItem Deleted is %d\n",temp->info);
			free(temp);
			return;
		}
		prev=temp;
		temp=temp->link;
	}
	if(flag)
		printf("\nNode Not Found\n");
}
			
void main()
{
	int c,i,p;
	do
	{	
		printf("\n**MENU**\n");
		printf("1.Insert at Beginning\n2.Deletion at Beginning\n3.Insert at End\n4.Deletion at End");
		printf("\n5.Insertion at given Position\n6.Delete from given Position\n");
		printf("7.Insert After Given Node(Info)\n8.Delete After Given Node(Info)\n");
		printf("9.Insert Before Given Node(Info)\n10.Delete Before Given Node(Info)\n");
		printf("11.Delete Given Info\n12.Delete All Given Info\n13.Display\n14.Exit\n");
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
				printf("\nEnter Element to be Inserted:");
				scanf("%d",&i);
				printf("\nEnter Info after which Element is to be Inserted:");
				scanf("%d",&p);
				insert_after(i,p);
				break;	
			case 8:
				printf("\nEnter Node After which Element is to be Deleted:");
				scanf("%d",&p);
				del_after(p);
				break;	
			case 9:
				printf("\nEnter Element to be Inserted:");
				scanf("%d",&i);
				printf("\nEnter Info Before which Element is to be Inserted:");
				scanf("%d",&p);
				insert_before(i,p);
				break;	
			case 10:
				printf("\nEnter Node Before which Element is to be Deleted:");
				scanf("%d",&p);
				del_before(p);
				break;	
			case 11:
				printf("\nEnter Info which is to be Deleted:");
				scanf("%d",&p);
				del_given(p);
				break;	
			case 12:
				printf("\nEnter Info which is to be Deleted:");
				scanf("%d",&p);
				deleteinfo(p);
				break;	


			case 13:
				disp();
				break;
			case 14:
				exit(0);
				break;
			default:
				printf("Wrong Choice!Try Again!\n");
		}
	}while(c!=14);
}
