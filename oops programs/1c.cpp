#include <iostream>
using namespace std;

double area(int a)
{
    return(a*a);
}
double area(float a,float b)
{
    return(a*b);
}
double area(float r)
{
    return(r*r*3.142);
}
int main()
{
   int a,ch;
   float r,l,b;
   cout<<"\nmenu\n";
   cout<<"1.square\n2.rectangle\n3.circle\n";
   cin>>ch;
   switch(ch)
   {
       case 1:cout<<"enter the edge length of square=";cin>>a;
              cout<<"area = "<<area(a)<<endl;
              break;
       case 2:cout<<"enter the length and breadth of rectangle= ";cin>>l>>b;
              cout<<"area = "<<area(l,b)<<endl;
              break;    
       case 3:cout<<"enter the radius of circle= ";cin>>r;
              cout<<"area = "<<area(r)<<endl;
              break;              
       default:cout<<"invalid choice\n";
   }
   return 0;
}

