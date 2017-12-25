#include <stdio.h>
#include <string.h>
#include <malloc.h>
struct node 
{ 
    char info; 
    struct node *left,*right; 
};

int top=-1; 
struct node *stack[20]; 
struct node *nn;

void push(struct node* no) 
{ 
    stack[++top]=no; 
}

struct node * pop() 
{ 
    return(stack[top--]); 
}
int  isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return 1;
    return 2;
}

void inorder(struct node*t)
{
    //struct node*t=stack[top];
    if(t==NULL)
        return;
    if(t)
    {
        inorder(t->left);
        printf("%c ", t->info);
        inorder(t->right);
    }
}

void newnode(char a)
{
    nn=((struct node*)(malloc(sizeof(struct node)))); 
    nn->info=a; 
    nn->left=NULL; 
    nn->right=NULL;
}

void constructTree()
{
    //stack<et *> st;
    struct node *t, *t1, *t2;
    char postfix[20];int i;
    scanf("%s",postfix);
    for(i=0; i<strlen(postfix); i++)
    {
        // If operand, simply push into stack
        if (isOperator(postfix[i])==2)
        {
            newnode(postfix[i]);
            push(nn);
        }
        else // operator
        {
            newnode(postfix[i]);
            // Pop two top nodes
            //t1 = st.top(); // Store top
            nn->right = stack[top];
            pop();      // Remove top
            nn->left = stack[top];
            //t2 = st.top();
            pop();
            //  make them children
            // Add this subexpression to stack
            push(nn);
        }
    }
}

int cal(struct node *temp) 
{ 
    int ch; 
    ch=isOperator(temp->info); 
    if(ch==2) 
    return temp->info-48; 
    else if(ch==1) 
    { 
        if(temp->info=='+') 
            return cal(temp->left)+cal(temp->right); 
        if(temp->info=='-') 
            return cal(temp->left)-cal(temp->right); 
        if(temp->info=='*') 
            return cal(temp->left)*cal(temp->right); 
        if(temp->info=='/') 
            return cal(temp->left)/cal(temp->right); 
    } 
}

int main()
{
    printf("enter the valid postfix expression = ");
    constructTree();
    printf("infix expression is \n");
    inorder(stack[top]);
    printf("\nvalue of the expression = %d\n",cal(stack[top]));
    return 0;
}

