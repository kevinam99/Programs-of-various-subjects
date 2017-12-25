#include <iostream>
using namespace std;
class SecondClass;

class MyClass
{
	public:
	friend class SecondClass;
    int a;
	MyClass()
	{
        a=5;
	}
	void printMember()
	{
		cout << " memeber of my class = " <<a<< endl;
	}
};

class SecondClass
{
	public:
	    int b;
	    SecondClass()
	    {
	        b=10;
	    }
		void change( MyClass& yourclass)
		{
			int temp=yourclass.a;
			    yourclass.a=b;
			    b=temp;
		}
		void printMember1()
	    {
		    cout << " memeber of second class = " <<b<< endl;
	    }
};

int  main()
{
	MyClass my_class;
	SecondClass sec_class;
	my_class.printMember();
	sec_class.printMember1();
	sec_class.change(my_class);
	sec_class.printMember1();
	my_class.printMember();
	return 0;
}	