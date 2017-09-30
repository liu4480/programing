#include <iostream>
using namespace std;
 
//// LIBRARY START
class Base
{
public:
 
    Base() { }
 
    virtual // Ensures to invoke actual object destructor
    ~Base() { }
 
    // An interface
    virtual void DisplayAction() = 0;
};
 
class Derived1 : public Base
{
public:
    Derived1()
    {
        cout << "Derived1 created" << endl;
    }
 
    ~Derived1()
    {
        cout << "Derived1 destroyed" << endl;
    }
 
    void DisplayAction()
    {
        cout << "Action from Derived1" << endl;
    }
};
 
class Derived2 : public Base
{
public:
    Derived2()
    {
        cout << "Derived2 created" << endl;
    }
 
    ~Derived2()
    {
        cout << "Derived2 destroyed" << endl;
    }
 
    void DisplayAction()
    {
        cout << "Action from Derived2" << endl;
    }
};

class Derived3 : public Base
{
public:
    Derived3()
    {
        cout << "Derived3 created" << endl;
    }
 
    ~Derived3()
    {
        cout << "Derived3 destroyed" << endl;
    }
 
    void DisplayAction()
    {
        cout << "Action from Derived3" << endl;
    }
};
 
//// LIBRARY END
 
class User
{
public:
    User() : pBase(0)
    {
        // Creates Drived1 or Derived2 based on need
 
        int input; // ID to distinguish between
                   // Derived1 and Derived2
 
        cout << "Enter ID (1 or 2 or 3): ";
        cin  >> input;
 
        while( (input !=  1) && (input !=  2) && (input != 3))
        {
            cout << "Enter ID (1 or 2 or 3 only): ";
            cin  >> input;
        }
 
        if( input == 1 )
        {
            pBase = new Derived1;
        }
        else if( input == 2 )
        {
            pBase = new Derived2;
        }
        else
        {
            pBase = new Derived3;
        }
    } 
    ~User()
    {
        if( pBase )
        {
            delete pBase;
            pBase = 0;
        }
    }
 
    // Delegates to actual object
    void Action()
    {
        pBase->DisplayAction();
    }
 
private:
    Base *pBase;
};
 
int main()
{
    User *user = new User();
 
    // Need Derived1 functionality only
    user->Action();
 
    delete user;
}
