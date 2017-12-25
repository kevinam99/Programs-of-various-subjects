#include<iostream>
#include<stdlib.h>

using namespace std;

int f=0;

int r=-1;

template<class t>

class q

{



t q1[4];

public:

void insert()

{

t item;

cout<<"\nEnter item";

cin>>item;

if(r>=3)

cout<<"\noverflows";

else

q1[++r]=item;

}

void delet()

{

if(r==-1)

cout<<"\nunderflow\n";

else

cout<<"\n"<<q1[f++]<<"is deleted";

if(f>r)

      {

     f=0;

   r=-1;

           }

      }



       void display()

       {

        int i;

        if(r==-1)

        {

        cout<<"\nqueue empty\n";

        return;

   }

  cout<<"\nqueue is:";

  for(i=f;i<=r;i++)

  {

  cout<<"\n"<<q1[i];

  }       }

   };

  int main()

  {

  q<int>w1;

  q<double>w2;

  int ch1=1,ch2=1,n;

  cout<<"\nenter 1 for integer queue\n\t2 for double queue";

  cin>>n;

  if(n==1)

  {

  for(;;)

  {

  cout<<"\n1 to insert,2 to delete,3 to display,4 to exit\n";

  cin>>ch1;

  switch(ch1)

  {

  case 1:w1.insert();

  break;

  case 2:w1.delet();

  break;

  case 3:w1.display();

  break;

  default:

  exit(0);

  }

  }

  }

 else

  {

  while(ch2)

  {

  cout<<"\n1 to insert,2 to delete,3 to display,4 to exit\n";

  cin>>ch2;

  switch(ch2)

  {

 case 1:w2.insert();

  break;

  case 2:w2.delet();

  break;

  case 3:w2.display();

  break;

  default:

  exit(0);

  }  }  }

  return 0;

}