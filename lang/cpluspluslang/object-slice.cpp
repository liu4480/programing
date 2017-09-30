/*
 * In C++, a derived class object can be assigned to a base class object, 
 * but the other way is not possible.
 * Object slicing happens when a derived class object is assigned to a base
 * class object, additional attributes of a derived class object are sliced
 * off to form the base class object.
 */

#include <iostream>
using namespace std;

class Base
{
protected:
    int i;
public:
    Base(int a)     { i = a; }
    virtual void display()
    { cout << "I am Base class object, i = " << i << endl; }
};

class Derived : public Base
{
    int j;
public:
    Derived(int a, int b) : Base(a) { j = b; }
    virtual void display()
    { cout << "I am Derived class object, i = "
           << i << ", j = " << j << endl;  }
};

// Global method, Base class object is passed by value
void somefunc (Base obj)
{
    obj.display();
}

void somefunc1 (Base* obj)
{
    obj->display();
}
int main()
{
    Base b(33);
    Derived d(45, 54);
    Base * bp = new Derived(22, 11);
    somefunc(b);
    somefunc(d);  // Object Slicing, the member j of d is sliced off
    somefunc(*bp);

    somefunc1(&b);
    somefunc1(&d);  // Object Slicing, the member j of d is sliced off
    somefunc1(bp);
    return 0;
}
