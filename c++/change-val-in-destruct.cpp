#include <iostream>
using namespace std;
 
int i;
 
class A
{
public:
    ~A()
    {
        i = 10;
    }
};
 
int foo1()
{
    i = 3;
    A ob;
    return i;
}
 
int& foo2()
{
    i = 3;
    A ob;
    return i;
}

int foo3()
{
    i = 3;
    {
        A ob;
    }
    return i;
}

int main()
{
    cout << "i = " << foo1() << endl;
    cout << "i = " << foo2() << endl;
    cout << "i = " << foo3() << endl;
    return 0;
}
