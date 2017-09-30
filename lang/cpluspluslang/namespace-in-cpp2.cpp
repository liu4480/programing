#include <iostream>
using namespace std;

// first name space
namespace first
{
   int func() {  return 5; }
   int val1 = 500;
}

// second name space
namespace second
{
   int func() { return 10; }
   int val2 = 501;
}
//unnamed namespace
namespace
{
    int rel = 300;
}

int main()
{
   // member function of namespace
   // accessed using scope resolution operator
   cout << first::func() <<"\n";        
   cout << second::func() <<"\n"; 
   cout << first::val1 << endl;
   cout << second::val2 << endl;
   cout << rel << endl;
   return 0;
}
