#include <iostream>
#include<stdlib.h>
using namespace std;

class Box {
   public:
      double length;      // Length of a box
      double breadth;     // Breadth of a box

      double getarea(void) {
         return length * breadth;
      }

      double getperi(void)
      {
          return length + breadth;
      }

      void setLength( double len ) {
         length = len;
      }

      void setBreadth( double bre ) {
         breadth = bre;
      }

      Box operator+(const Box& b) {
         Box box;
         box.length = length + b.length;
         box.breadth = breadth + b.breadth;
         return box;
      }

      void operator==(const Box& b) {
       if(length == b.length && breadth == b.breadth)
            cout<<"objects equal"<<endl;
        else
            cout<<"objects not equal"<<endl;
       }
friend ostream &operator << (ostream & t,const Box &b);
};

ostream &operator << (ostream & t,const Box &b)
{
    t<<b.length<<endl;
    t<<b.breadth<<endl;
    
}

// Main function for the program
int main( ) {
   Box Box1;
   Box Box2;
   Box Box3;
   double area = 0.0;
   double peri = 0.0;

   // box 1 specification
   Box1.setLength(6.0);
   Box1.setBreadth(7.0);

   // box 2 specification
   Box2.setLength(12.0);
   Box2.setBreadth(13.0);

   area = Box1.getarea();
    cout << "area of Box1 : " << area <<endl;

   area = Box2.getarea();
   cout << "area of Box2 : " << area <<endl;

   peri = Box1.getperi();
    cout << "peri of Box1 : " << peri <<endl;

    peri = Box2.getperi();
    cout << "peri of Box2 : " << peri <<endl;

   // Add two object as follows:
   Box3 = Box1 + Box2;
    cout<<"box1+box2="<<Box3;

   // area of box 3
   area = Box3.getarea();
   cout << "area of Box3 : " << area <<endl;

   Box1==Box2;

   return 0;
}
