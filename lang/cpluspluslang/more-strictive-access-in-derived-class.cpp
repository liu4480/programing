#include<iostream>
using namespace std;
/*
 * In the above program, private function “Derived::fun(int )” is being 
 * called through a base class pointer, the program works fine because 
 * fun() is public in base class. Access specifiers are checked at compile 
 * time and fun() is public in base class.
 *
 * At run time, only the function corresponding to the pointed object is 
 * called and access specifier is not checked. So a private function of 
 * derived class is being called through a pointer of base class.
 */
class Base {
public:
    virtual int fun(int i) { cout << "Base::fun(int i) called"; }
};

class Derived: public Base {
private:
    int fun(int x)   { cout << "Derived::fun(int x) called"; }
};

int main()
{
    //Derived d;
    //error: ‘virtual int Derived::fun(int)’ is private
    //d.fun(10);
    Base *ptr = new Derived;
    ptr->fun(10);
    return 0;
}
