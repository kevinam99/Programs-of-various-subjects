#include<iostream>
#include<stdio.h>
#define pi 3.14
using namespace std;
class circle
{
	public:
		double r;
		circle(double a)
		{
			r=a;
		}
		double area()
		{
			return (pi*r*r);
		}
};
class sector : public circle
{
	public:
		double ca;
		sector(double a, double b) : circle(a)
		{
			ca=b;
		}
		double area_sector()
		{
			return (r*r*(ca/2));
		}
};
class segment : public circle
{
	public:
		double h;
		segment(double a, double b) : circle(a)
		{
			h=b;
		}
		double area_segment()
		{
			return ((r*r)*((r-h)/r)-(r-h)*((2*r*h)-(h*h)))/2;
		}
};	
int main()
{
	double r,ca,h;
	cout<<"enter radius of circle\n";
	cin>>r;
	cout<<"enter control angle of sector in radian\n";
	cin>>ca;
	cout<<"enter length of segment\n";
	cin>>h;
	circle obj1(r);
	printf("area of circle is %lf\n",obj1.area());
	sector obj2(r,ca);
	printf("area of sector is %lf\n",obj2.area_sector());
	segment obj3(r,h);
	printf("area of segment is %lf\n",obj3.area_segment());
	return 1;
}	
