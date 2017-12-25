#include<iostream>  
#include<string.h>  
#include<stdlib.h>  
using namespace std;
class complex  
{  
    public:
    int i,r;  
    complex()
    {
        cin>>r>>i;
    }
    void display()  
    {
        cout<<"\n= "<<r<<"+"<<i<<"i";  
    }  
    friend complex add(const complex a2,const complex a1);  
    friend complex mul(const complex a2,const complex a1);  
};

complex add(complex a2,complex a1)  
{
    cout<<"enter some waste value\n";
    complex a;
    a.r=a1.r+a2.r;
    a.i=a1.i+a2.i;
    a.display();
    //return a;
}  

complex mul(complex a2,complex a1)  
{  
    cout<<"enter some waste value\n";
    complex a;  
    a.r=(a1.r*a2.r)-(a1.i*a2.i);  
    a.i=(a1.r*a2.i)+(a1.i*a2.r);  
    return a;  
} 
 
int  main()  
{  
    int ch,a,b;  
    do  
    {  
        cout<<"\n1.Addition";  
        cout<<"\n2.Mulitplication\n3.Exit\n"; 
        cout<<"\nEnter the choice :";  
        cin>>ch;  
        switch(ch)  
        {  
            case 1:  
            {    
                cout<<"\nEnter The First Complex Number i.e real and complex part:";//cin>>a>>b;  
                complex a1;
                //a1.display();  
                cout<<"\nEnter The second Complex Number i.e real and complex part:";//cin>>a>>b;  
                complex b1; 
                //b1.display();
                //complex c1;
                add(a1,b1);
                //c1.display();  
                break;  
            }
            case 2:  
            {
                cout<<"\nEnter The First Complex Number i.e real and complex part:";//cin>>a>>b;  
                complex a1;
                //a1.display();  
                cout<<"\nEnter The second Complex Number i.e real and complex part:";//cin>>a>>b;  
                complex b1;
                //b1.display();  
                complex c1;
                c1=mul(a1,b1);  
                c1.display();  
                break;
            }
            case 3:exit(0);
            break;
            default:cout<<"invalid choice";
        }  
    }while(ch!=5);  
    return 0;
}  
