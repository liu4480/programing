#include<iostream>
 
using namespace std;
//Making base class destructor virtual guarantees that the object of derived class is destructed properly, 
//i.e., both base class and derived class destructors are called.
//otherwise, only the derived destructor can be called.
class base {
  public:
    base()     
    { cout<<"Constructing base \n"; }
    //~base()
    virtual ~base()
    { cout<<"Destructing base \n"; }     
};
 
class derived: public base {
  public:
    derived()     
    { cout<<"Constructing derived \n"; }
    ~derived()
    { cout<<"Destructing derived \n"; }
};
 
int main(void)
{
  derived *d = new derived();  
  base *b = d;
  delete b;
  return 0;
}
