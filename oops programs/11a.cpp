#include <iostream>
using namespace std;

double division(float a, float b) 
{
   if( b == 0 ) 
   {
      throw "Division by zero condition!";
   }
   if(a<b)
    { 
        throw 1;
    }        
   return (a/b);
}

int main () 
{
   float x = 50;
   float y = 0;
   double z = 0;
    cin>>x>>y; 
   try 
   {
      z = division(x, y);
      cout << z << endl;
   }
   catch (const char* msg) 
   {
      cout << msg << endl;
   }
   catch (int) 
   {
      cout <<"a is less than b\n"<< endl;
   }

   return 0;
}