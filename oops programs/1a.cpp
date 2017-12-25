#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class sample
{
	private:
		double a, b;
	public:
		sample()
		{
			cout<<"enter two nos\n";
			cin>>a>>b;
		}	
		friend double mean(sample&);
};
double mean(sample& m)
{
	return(m.a+m.b)/2;
}
int main()
{
	sample s;
	printf("mean of nos is %lf\n",mean(s));
	return 1;
}