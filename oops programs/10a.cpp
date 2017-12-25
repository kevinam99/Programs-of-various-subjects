#include <iostream>
#include<fstream>
using namespace std;
class employee
{
    public:
    char name[30];
    long int empno;
    long int salary;
    char deptname[10];
};
int main()
{
    employee e;
    ofstream ofile;
    ofile.open("sample.txt");
    cout<<"Enter employee details:\n:";
    cout<<"Name:";
    cin.getline(e.name,30);
    //cin>>e.name;
    ofile<<e.name<<endl;
    cout<<"EmpNo:";
    cin>>e.empno;
    ofile<<e.empno<<endl;
    cout<<"Salary:";
    cin>>e.salary;
    ofile<<e.salary<<endl;
    cout<<"DeptName:";
    cin.getline(e.deptname,10,'#');
    ofile<<e.deptname;
    ofile.close();
    ifstream ifile("sample.txt");
    int line=0,word=0,c=0;
    char ch;
 ifile.seekg(0,ios::beg);
ch=ifile.get();
 while(ch!=EOF)
 {

  if(ch==' ' || ch=='\n')
   {
	word++;
   }

  if(ch=='\n')
   {
	line++;
   }
   if(ch!=' ' && ch!='\n')
	   c++;
   ch=ifile.get();
 }

 cout<<"Lines="<<line<<"\nWords="<<word<<"\nCharacters="<<c<<"\n";
 ifile.close();

}