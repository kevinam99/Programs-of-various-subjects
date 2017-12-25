#include <iostream>
#include<stdlib.h>

using namespace std;
class vector
{
    int a[10];
public:
    void assign()
    {int i;
        for(i=0;i<10;i++)
            cin>>a[i];
    }
    int operator[](int p)
    {
        if(p<1 || p>10)
            {cout<<"Invalid subscript\n";exit(0);}
        else
            return a[p];
    }
};

int main()
{
    vector v;
    int p;
    cout<<"Enter 10 array elements:";
    v.assign();
    cout<<"Enter the position of the element to be displayed:";
    cin>>p;
    cout<<v[p-1]<<endl;
    return 0;
}