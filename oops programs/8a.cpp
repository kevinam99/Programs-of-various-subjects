#include<iostream>
using namespace std;
class octal
{
    int oct,dec,ten;
    public:
    octal()
    {
        oct=0;
        ten=1;
    }

void operator=(int x)
{
    int r;
    dec=x;
    while(x!=0)
    {
        r=x%8;
        x=x/8;
        oct=oct+ten*r;
        ten=ten*10;
    }
}

int operator+(int k)
{
return(dec+k);
}

friend ostream & operator<<(ostream&,octal& c);

};

ostream & operator<<(ostream& sout,octal&c)
{
    sout<<c.oct;
}

int main()
{
    octal h;
    int n,k;
    cout<<"Enter a integer to change to octal: ";
    cin>>n;
    cout<<endl;
    h=n;
    cout<<"The octal value of "<<n<<" is: "<<h<<endl;
    cout<<"\nEnter integer to be added to previous octal: ";
    cin>>k;
    cout<<endl;
    int y=h+k;
    cout<<"Integer sum of octal and integer is: "<<y<<"\n";
    return 0;
}