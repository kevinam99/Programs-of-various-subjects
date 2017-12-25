#include <iostream>

using namespace std;
class dist
{
    int feet;
    float inches;
public:
    dist(int f=0,float i=0);
    void get(int f,float i)
    {
        feet=f;
        inches=i;
    }
    friend ostream &operator <<(ostream &out,dist &d)
    {
        out<<"Feet:"<<d.feet<<endl<<"Inches:"<<d.inches<<endl;
        return out;
    }
    void operator =(dist &d)
    {
        feet=d.feet;
        inches=d.inches;
    }
    dist operator ++()
    {
        return dist(++feet,inches);
    }
    dist operator--(int)
    {
        dist(feet--,inches);

    }

};
dist::dist(int f,float i)
{
    feet=f;
    inches=i;
}
int main()
{
    dist d1;
    int f;
    float i;
    cout<<"Enter the feet and inches:";
    cin>>f>>i;
    d1.get(f,i);
    cout<<"Elements of d1:\n";
    cout<<d1;
    ++d1;
    cout<<"Elements of d1 after pre incrementing:\n";
    cout<<d1;
    d1--;
    cout<<"Elements of d1 after post decrementing:\n";
    cout<<d1;
    dist d2;
    d2=d1;
    cout<<"Elements of d2(copied):\n";
    cout<<d2;
    return 0;
}