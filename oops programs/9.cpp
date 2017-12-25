#include <iostream>
using namespace std;

class shape
{
    public :
    virtual float get_area()=0;
};
class rectangle
{
    public:float l,b;
    void get()
    {
        cout<<"enter length and breadth of rectangle\n";
        cin>>l>>b;
    }
    float get_area()
    {
        return (l*b);
    }
    
};
class ellipse
{
    public:float maj,min;
    void get()
    {
        cout<<"enter major and minor axis\n";
        cin>>maj>>min;
    }
    float get_area()
    {
        return (maj*min*3.142);
    }
    
};
int main()
{
   //cout << "Hello World" << endl; 
   rectangle r;
   ellipse e;
   r.get();
   cout<<"area of rectangle = "<<r.get_area()<<endl;
   e.get();
   cout<<"area of ellipse = "<<e.get_area()<<endl;
   return 0;
}

