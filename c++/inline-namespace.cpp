//An inline namespace is a namespace that uses the optional keyword inline 
//in its original-namespace-definition.
//In C++, namespaces can be nested, and resolution of namespace variables is hierarchical. 
#include <iostream>
using namespace std;
 
namespace ns1
{
   inline namespace ns2
   {
       int var = 10;
       inline namespace ns3
       {
           int var2 = 20;
       }
   }
}

int x = 20;
namespace outer {
  int x = 10;         
  namespace inner {
    int z = x; // this x refers to outer::x
  }
}
 
int main()
{
   cout << ns1::var  << endl;
   cout << ns1::var2 << endl;
   cout<<outer::inner::z; //prints 10
   return 0;
}
