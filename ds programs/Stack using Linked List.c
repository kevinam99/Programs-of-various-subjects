#include<stdio.h>
#include<stdlib.h>

struct Node
{
   int data;
   struct Node *next;
}*top = NULL;

void push(int);
void pop();
void display();

void main()
{
   int choice, value;
   
   printf("\n:: Stack using Linked List ::\n");
   while(1){
      printf("\n****** MENU ******\n");
      printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%d", &value);
		 push(value);
		 break;
	 case 2: pop(); break;
	 case 3: display(); break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}
void push(int value)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   if(top == NULL)
    {  
        newNode->next = newNode;
        top=newNode;
        return;
    }
   else
    {  
        struct Node *temp = top;
        while(temp->next!=top)
        {
          temp=temp->next;
        }
       newNode->next = top;
       temp->next=newNode;
       top = newNode; 
    }
   printf("\nInsertion is Success!!!\n");
}
void pop()
{
   if(top == NULL)
      printf("\nStack is Empty!!!\n");
   else{
      struct Node *temp = top;
      if(top->next==top)
      {
          printf("\nDeleted element: %d", temp->data);
          top=NULL;
          return;
      }
      printf("\nDeleted element: %d", temp->data);
      while(temp->next!=top)
      {
          temp=temp->next;
      }
      temp->next=top->next;
      temp=top;
      top = top->next;
      free(temp);
   }
}
void display()
{
   if(top == NULL)
      printf("\nStack is Empty!!!\n");
   else{
      struct Node *temp = top;
      while(temp->next != top){
	 printf("%d--->",temp->data);
	 temp = temp -> next;
      }
      printf("%d--->NULL",temp->data);
   }
}