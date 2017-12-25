#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
double si(double p, double r=12, double t=1)
{
	return (p*r*t)/100;
}
int main()
{
	double p,r,t;
	cout<<"enter principal amount, rate of interest and time period\n";
	cin>>p>>r>>t;
	printf("%lf\n",si(p));
	printf("%lf\n",si(p,r,t));
	return 1;
}