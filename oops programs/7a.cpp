#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
class strng
{
public:
char str[20];
public:
strng(const char msg[])
{
    strcpy(str,msg);
}
strng( strng &s1)
{
    strcpy(str,s1.str);
}
friend ostream & operator<<(ostream&,strng&);
};
strng operator+(strng s1,strng s2)
{
strcat(s1.str,s2.str);
return s1;
}
ostream & operator<<(ostream& os,strng& s)
{
os<<s.str<<endl;
return os;
}
int main()
{
strng s1("ise");
strng s2("MSRIT");
strng s3("");
s3=s1+s2;
cout<<"\nBEFORE CONCATINATION";
cout<<"\n s1="<<s1;
cout<<"\n s2="<<s2;
s3=s1+s2;
cout<<"\nAFTER CONCATENATION"<<"\n:";
cout<<"\n s1+s2="<<s3;
return 0;
}