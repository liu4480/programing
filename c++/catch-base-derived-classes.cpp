#include<iostream>
using namespace std;
 
class Base {};
class Derived: public Base {};
int main()
{
   Derived d;
   // some other stuff
   try {
       // Some monitored code
       throw d;
   }
   //if put Base in front, the compiler will report warning, and program
   //only catch Base
   /*
   catch(Base b) { 
        cout<<"Caught Base Exception";
   }
   catch(Derived d) {  //This catch block is NEVER executed
        cout<<"Caught Derived Exception";
   }*/
   catch(Derived d) { 
        cout<<"Caught Derived Exception";
   }
   catch(Base b) { 
        cout<<"Caught Base Exception";
   }
   return 0;
}
