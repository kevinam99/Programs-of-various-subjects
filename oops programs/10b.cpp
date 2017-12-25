#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{

char data[30];
char data1[20];

char out[100];

ofstream of;
of.open("sample1.dat");

/// each character is 1 byte ---> 30bytes + 30 characters
cout<<"enter upto 30 characters\n";
cin.getline(data,30);
of.write((char*)&data,sizeof(data));
cout<< "Enter upto 20 characters\n";
cin.getline(data1,20);
of.seekp(15);
of.write((char*)&data1,sizeof(data1));
//of <<data1 <<endl;

of.close();

//read from file

ifstream iff;
iff.open("sample1.dat");
iff.read((char*)&out,sizeof(data));
cout<<"the data in the file is \n";
cout<< out<<endl;

iff.close();

return 0;
}