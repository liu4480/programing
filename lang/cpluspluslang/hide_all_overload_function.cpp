/*
 * In C++, if a derived class redefines base class member method then all 
 * the base class methods with same name become hidden in derived class.
 * Even if the signature of the derived class method is different, all the 
 * overloaded methods in base class become hidden. 
 */
#include<iostream>
 
using namespace std;
 
class Base
{
public:
    int fun()
    {
        cout<<"Base::fun() called";
    }
    int fun(int i)
    {
        cout<<"Base::fun(int i) called";
    }
};
 
class Derived: public Base
{
public:
    int fun() 
    {
        cout<<"Derived::fun() called";
    }
};
 
int main()
{
    Derived d;
    d.fun(5);  // Compiler Error
    return 0;
}
