// C++ program to demonstrate accessing of variables
// in normal way, i.e., using "::"
// C++ can also access variables by header file
#include <iostream>
using namespace std;

namespace geek
{
    int rel = 300; 
}

// Nested namespace
namespace out
{
  int val = 5; 
  namespace in
  {
      int val2 = val;    
  }
}

namespace alias=out::in;

int main()
{
    // variable ‘rel’ accessed 
    // using scope resolution operator
    cout << geek::rel << "\n";  // prints 300
    // directive access, it works only if there is one namespace geek
    //cout << rel << "\n";  // prints 300

    cout << out::in::val2 << endl;
    cout << alias::val2 << endl;
    return 0;
}
