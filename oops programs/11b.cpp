#include <iostream>

#include<stdlib.h>

using namespace std;

class account

{

    public: int amount;

            account()

            {

                amount =500;

            }

            void deposit(int x)

            {

                amount+=x;

            }

            void withdraw(int x)

            {

                amount-=x;

            }

            void display()

            {

                cout<<"amount in the account="<<amount<<endl;

            }

};

int main()

{

   //cout << "Hello World" << endl;

   int x,ch;account a;

   while(1)

   {

       cout<<"\n1.deposit\n2.withdraw\n3.display\n4.exit\n";

       cin>>ch;

       switch(ch)

       {

           case 1:

                cout<<"enter the amount to deposit";

                cin>>x;

                a.deposit(x);

                break;

            case 2:cout<<"enter the amount to withdraw";

                cin>>x;

                try

                {

                    if(x>a.amount)

                        throw "withdraw amount is more than the balance amount";

                    a.withdraw(x);

                }

                catch(const char*msg)

                {

                    cout<<msg;

                }

                break;

            case 3:a.display();

                    break;

            case 4:exit(0);

                break;

            default:cout<<"invalid choice";

       }

   }

   return 0;

}