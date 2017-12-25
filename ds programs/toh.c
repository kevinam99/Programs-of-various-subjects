#include<stdio.h>

void TOH(int n, char S, char T, char D);
 
int main() {
   int num;
   printf("\nEnter number of discs:");
   scanf("%d", &num);
 
   TOH(num, 'S', 'T', 'D');
   return (0);
}
 
void TOH(int n, char S, char T, char D)
{
    if(n==1)
        printf("move disc from %c to %c\n",S,D);
    else
    {
        TOH(n-1, S, D, T);
        printf("move disc from %c to %c\n",S,D);
        TOH(n-1, T, S, D);
    }
    return;
}