/*
 * Namespaces allow us to group named entities that otherwise would have 
 * global scope into narrower scopes, giving them namespace scope. This 
 * allows organizing the elements of programs into different logical scopes
 * referred to by names.

 * Namespace is a feature added in C++ and not present in C.
 * A namespace is a declarative region that provides a scope to the 
 * identifiers (names of the types, function, variables etc) inside it.
 * Multiple namespace blocks with the same name are allowed. All 
 * declarations within those blocks are declared in the named scope.
 */

#include <iostream>
using namespace std;
namespace ns1
{
    int value()    { return 5; }
}
namespace ns2 
{
    const double x = 100;
    double value() {  return 2*x; }
}

namespace ns
{
    // A Class in a namespace
    class geek
    {
    public:
        void display()
        {
            cout << "ns::geek::display()\n";
        }
    };
}

int main()
{
    // Access value function within ns1
    cout << ns1::value() << '\n'; 

    // Access value function within ns2
    cout << ns2::value() << '\n'; 

    // Access variable x directly
    cout << ns2::x << '\n';       

    ns::geek obj;
    obj.display();

    return 0;
}
