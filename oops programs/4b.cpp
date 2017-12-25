#include<iostream>
#include<stdio.h>
using namespace std;
int i=0,j=0,k=0,sum=0;
class matrix
{
	public:
		int m,n,**p;
		matrix(int x, int y)
		{
			cout<<"Object created, constructor called, memory allocated\n";
			m=x;
			n=y;
			p= new int *[m];
			for(i=0;i<m;i++)
				p[i]= new int [n];
		}
		~matrix()
		{
			cout<<"destuctor invoked, memory space destroyed\n";
			delete(p);
		}
		void getdata()
		{
			cout<<"enter elements of matrix\n";
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
					cin>>p[i][j];
			return;
		}
		void putdata()
		{
			cout<<"matrix is:\n\n";
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					cout<<p[i][j];
					cout<<" ";
				}
				cout<<"\n";
			}
			return;
		}
		void add(matrix& a)
		{
			matrix b(m,n);
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
					b.p[i][j]=p[i][j]+a.p[i][j];
			cout<<"matrix obtained by adding two matrix is\n\n";
			b.putdata();
			return;
		}
		void multiply(matrix& a)
		{
			matrix c(m,n);
			for (i = 0; i < m; i++)
			{
      				for (j = 0; j < n; j++) 
				{
        				for (k = 0; k < m; k++) 
					{
          					sum = sum + p[i][k]*a.p[k][j];
        				}
 					c.p[i][j] = sum;
 		       			sum = 0;
      				}
			}
			cout<<"matrix obtained by multiplying two matrix is\n\n";
			c.putdata();
			return;
		}
};
int main()
{
	int x;
	cout<<"enter order of square matrix\n";
	cin>>x;
	matrix m1(x,x);
	m1.getdata();
	matrix m2(x,x);
	m2.getdata();
	m1.putdata();
	m2.putdata();
	m1.add(m2);
	m1.multiply(m2);
	return 0;
}			
				
		
