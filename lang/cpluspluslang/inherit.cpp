/*
 * 1. What all is inherited from parent class in C++
 * 1) Every data member defined in the parent class(although such members 
 * may not always be accessible in the derived class
 * 2) Every ordinary member function of the parent class(although such 
 * members may not always be accessible in the derived class
 * 3) The same initial data layout as the base class
 *
 * Following are the things which a derived class doesn't inherits from its
 * parent:
 * 1) The base class's constructos and destructor.
 * 2) The base class's friends
 */

/*
 * Virtual functions allow us to create a list of base class pointers and 
 * call methods of any of the derived classes without even knowing kind of 
 * derived class object. 
 *
 * Compiler maintains two things to this magic:
 * 1) vtable: A table of function pointers. It is maintained per class.
 * 2) vptr: A pointer to vtable. It is maintained per object (See this for 
 * an example).
 *
 * Compiler adds additional code at two places to maintain and use vptr.
 * 1) Code in every constructor. This code sets vptr of the object being 
 * created. This code sets vptr to point to vtable of the class.
 * 2) Code with polymorphic function call (e.g. bp->show() in above code). 
 * Wherever a polymorphic call is made, compiler inserts code to first look
 * for vptr using base class pointer or reference (In the above example, 
 * since pointed or referred object is of derived type, vptr of derived 
 * class is accessed). Once vptr is fetched, vtable of derived class can be
 * accessed. Using vtable, address of derived derived class function show()
 * is accessed and called. 
 */

#include<iostream>
using namespace std;
  
class Base
{
public:
    virtual void show() { cout<<" In Base \n"; }
};
  
class Derived: public Base
{
public:
    void show() { cout<<"In Derived \n"; }
};
  
int main(void)
{
    Base *bp = new Derived;
    bp->show();  // RUN-TIME POLYMORPHISM
    return 0;
}
