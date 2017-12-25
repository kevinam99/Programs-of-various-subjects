#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct student
{
	char name[20];
	char usn[20];
	double height;
	public:void getdata();
	       void display();
	       friend void sort(student s[]);
	        
};
struct student s[3];
char n[20];
char u[20];
double h=0;
int i=0,j=0;
void getdata()
{
	for(i=0;i<3;i++)
	{
		cout<<"enter name of student no. "<<i+1<<endl;
		cin>>s[i].name;
		cout<<"enter usn of student no. "<<i+1<<endl;
		cin>>s[i].usn;
		cout<<"enter height of student no. "<<i+1<<endl;
		cin>>s[i].height;
	}
	return;
}
void sort(student s[])
{
    student temp;
	for(i=0;i<3-1;i++)
	{
		for(j=i+1;j<3-1;j++)
		{
			if(s[i].height>s[j].height)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
	return;
}
void display()
{
    cout<<"details of student no "<<endl;
    cout<<"slno\tname\tusn\theight\t"<<endl;
	for(i=0;i<3;i++)
	{
				cout<<i+1<<"\t";
				cout<<s[i].name<<"\t";
				cout<<s[i].usn<<"\t";
				cout<<s[i].height<<endl;
	}
	return;
}
int main()
{
	cout<<"enter details of students\n\n";
	getdata();
	cout<<"data will be sorted in ascending order according to height of student\n\n";
	sort(s);
	cout<<"the sorted data is:\n\n";
	display();
	return 1;
}
