#include <iostream>
using namespace std;
//g++ -o libpycallclass.so -shared -fPIC pycallclass.cpp
class TestLib
{
public:
    int add(int a, int b)
    {
        cout << "you entered " << a << "and " << b << endl;
        return a + b;
    }

    void display()
    { cout << "First display" << endl; }

    void display(int a)
    {
        cout << "Second display:" << a << endl;
    }
};

extern "C" {
    TestLib obj;
    int add(int a, int b)
    {
        return obj.add(a, b);
    }
    void display()
    {
        obj.display();
    }
    void display_int(int a)
    {
        obj.display(a);
    }
}
