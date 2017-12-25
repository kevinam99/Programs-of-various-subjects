#include <iostream>

using namespace std;
class vector
{
    public:int a[10],n,scal,i;
    void assign()
    {
        cout<<"enter size and scaler value"<<endl;
        cin>>n>>scal;
        cout<<"enter the values for the array=";
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
    }
    void print()
    {
        for(i=0;i<n;i++)
        {
            cout<<a[i]<<"\t";
        }
        cout<<endl;
    }
    void mul()
    {
        for(i=0;i<n;i++)
        {
            a[i]=a[i]*scal;
        }
    }
};
int main()
{
    vector o1;
    o1.assign();
    o1.print();
    o1.mul();
    o1.print();
   return 0;
}

