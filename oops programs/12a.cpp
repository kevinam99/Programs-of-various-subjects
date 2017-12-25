#include <iostream>
using namespace std;
template <class T>
void sort(T a[],T n)
{
    T temp;int  i;int  j;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    cout<<"sorted array is ="<<endl;
    for(i=0;i<n;i++)
        cout<<a[i]<<endl;
}
int main()
{
   //cout << "Hello World" << endl; 
   int b[10],c;
   double a1[10],n1;
   cout<<"enter the size of the integer array";
   cin>>c;
   for(int i=0;i<c;i++)
   {
       cin>>b[i];
   }
   sort(b,c);
   cout<<"enter the size of the double type array";
   cin>>n1;
   for(int i=0;i<n1;i++)
   {
       cin>>a1[i];
   }
   sort(a1,n1);
   return 0;
}