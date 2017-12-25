#include<iostream>
#include<stdlib.h>
using namespace std;
inline int max(int a, int b)
{
	return (a>=b?a:b);
}
int main()
{
	int a,b,c,d;
	cout<<"enter 3 nos"<<endl;
	cin>>a>>b>>c;
	d=max(a,b);
	cout<<"greatest of 3 nos is "<<max(d,c)<<endl;
	return 1;
}