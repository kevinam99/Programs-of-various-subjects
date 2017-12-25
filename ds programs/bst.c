#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node*left;
    struct node*right;
};
struct node*root=NULL;
struct node*temp;
void create();
void search(struct node*root);
void insert()
{
    create();
    if (root == NULL)
        root = temp;
    else
        search(root);
}
void create()
{
    int data;
    printf("Enter data of node to be inserted : ");
    scanf("%d", &data);
    temp = ((struct node *)(malloc(sizeof(struct node))));
    temp->info = data;
    temp->left = temp->right = NULL;
}
void search(struct node*t)
{
    if ((temp->info > t->info)&&(t->right != NULL))
        search(t->right);
    else if ((temp->info > t->info) && (t->right == NULL))
        t->right = temp;
    else if ((temp->info < t->info) && (t->left != NULL))
        search(t->left);
    else if ((temp->info < t->info) && (t->left == NULL))
        t->left = temp;
}
int search1(struct node*t,int key)
{
    if(t==NULL)
        return 0;
    else if(t->info==key)
        return 1;
    else if (t->info<key)
        return search1(t->right,key);
    else if (t->info>key)
        return search1(t->left,key);
}

void display(struct node* root,int l)
{
    int i;
    if(root==NULL)
    {
        return;
    }
    display(root->right,l+3);
    for(i=0;i<l;i++)
        printf(" ");
    printf("%d\n",root->info);
    display(root->left,l+3);
}
void main()
{
    int item,ch,pos;
    while(1)
    {
        printf("1.insert\n2.search\n3.display\n4.exit\n");
        printf("enter choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1://printf("enter info for newnode\n");
                    //scanf("%d",&item);
                    //create(item);
                    insert();
                    break;
            case 2:printf("enter the key to search\n");
                    scanf("%d",&pos);
                    item=search1(root,pos);
                    if(item==1)
                        printf("element found\n");
                    else
                        printf("element not found\n");
                    break;
            case 3:display(root,0);
                    break;
            case 4:exit(0);
                    break;
            default:printf("invalid choice");
        }
    }
}