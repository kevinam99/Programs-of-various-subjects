#include <iostream>

using namespace std;
class operation
{
    public:int a,b,res;char oper;
    void get()
    {
        cout<<"enter 2 values and operator";
        cin>>a>>b>>oper;
    }
    void print()
    {
        cout<<"result of " <<a<<" and "<<b<<" = "<<res<<endl;
    }
    void result()
    {
        switch(oper)
        {
            case '+':res=a+b;break;
            case '-':res=a-b;break;
            case '*':res=a*b;break;
            case '/':res=a/b;break;
            default:cout<<"invalid choice";
        }
    }
};
int main()
{
    operation o1;
    o1.get();
    o1.result();
    o1.print();
   return 0;
}

