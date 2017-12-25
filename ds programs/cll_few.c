#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node *link;
};

struct node *last=NULL;
struct node *nn;
struct node*temp;

int ch,item;

void del_end();
void del_beg();
void in_end(int);
void in_beg(int);

void in_end(int item)
{
nn=(struct node*)malloc(sizeof(struct node));
nn->info=item;
if(last==NULL)
{
nn->link=nn;
last=nn;
}
else
{
nn->link=last->link;
last->link=nn;
last=nn;
}
}

void in_beg(int item)
{
nn=(struct node*)malloc(sizeof(struct node));
nn->info=item;
if(last==NULL)
{
last=nn;
last->link=nn;
}
else
{
nn->link=last->link;
last->link=nn;
}
}
void displayList()
{
    struct node *temp;
   // int n = 1;
 
    if(last== NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
       temp = last->link;
        printf("DATA IN THE LIST:\n");
 
        do {
            printf("%d\n",  temp->info);
 
            temp = temp->link;
           // n++;
        }while(temp != last);
printf("%d\n", temp->info);
    }
}
void del_beg()
{
if(last==NULL)
{
printf("UNDERFLOW");
return;
}
if(last->link==last)
{
printf("\ndeleted element:%d",last->info);
free(last);
last=NULL;
return;
}
temp=last->link;
last->link=temp->link;
printf("\ndeleted element:%d",temp->info);
free(temp);
}


void del_end()
{
if(last==NULL)
{
printf("underflow");
return;
}
if(last->link==last)
{
printf("deleted element:%d",last->info);
free(last);
last=NULL;
return;
}
temp=last->link;
while(temp->link!=last)
{
temp=temp->link;
}
temp->link=last->link;
printf("deleted element:%d",last->info);
free(last);
last=temp;
}




void insert_given(int item,int pos)
{
    int c=1;
    temp=last->link;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->info=item;
    while(temp!=last && c!=pos)
    {    
        temp=temp->link;
        c++;
    }
    if(c==pos && temp==last)
    {
        nn->link=temp->link;
        temp->link=nn;
        last=nn;
        return;
    }    
    else if( temp==last && c!=pos)
    {
        printf("INVALID");
        return;
    }
    nn->link=temp->link;
    temp->link=nn;
    //last=nn;
    return;
}


void del_pos(int pos)
{
    int c=1;struct node*k;
    temp=last->link;
    while(temp!=last && c!=pos-1)
    {    
        temp=temp->link;
        c++;
    }
    k=temp->link;
    temp->link=k->link;
    free(k);
    printf("element deleted\n");
}













void main()
{
int pos;
while(1)
{
printf("1.insert beg\n2.delete beg\n3.delete end\n4.insert end\n5.display\n6.exit\n7.insert at position\n");
printf("enter choice");
scanf("%d",&ch);
switch(ch)
{
case 1:  
printf("enter info for newnode\n");
scanf("%d",&item);
in_beg(item);
break;
case 2:del_beg();
break;
case 3:del_end();
break;
case 4:
printf("enter info for newnode\n");
scanf("%d",&item);
in_end(item);
break;
case 5:displayList();
break;
case 6:exit(0);
break;
case 7://int pos;
printf("enter info for newnode and the position\n");
    scanf("%d",&item);
    scanf("%d",&pos);
    insert_given(item,pos);
    break;
case 8: printf("enter  the position\n");
    //scanf("%d",&item);
    scanf("%d",&pos);
    del_pos(pos);
break;
default:printf("invalid choice");
}
}
}