#include <iostream>
#include <typeinfo>
using namespace std;
 
class student
{
private:
    int roll;
public:
    // constructor
    student(int r):roll(r) {}
 
    // A const function that changes roll with the help of const_cast
    void fun() const
    {
        ( const_cast <student*> (this) )->roll = 5;
        //assignment of member ‘student::roll’ in read-only object
        //this->roll = 5;
    }
 
    int getRoll()  { return roll; }
};
 
int fun(int *ptr)
{
    return (*ptr + 10);
}

int main(void)
{
    student s(3);
    cout << "Old roll number: " << s.getRoll() << endl;
 
    s.fun();
 
    cout << "New roll number: " << s.getRoll() << endl;

    const int val=10;
    const int *ptr = &val;
    int *ptr1 = const_cast<int*>(ptr);
    cout << fun(ptr1) << endl;
 
    int a1 = 40;
    const int * b2 = &a1;
    //invalid const_cast from type ‘const int*’ to type ‘char*’
    //char * c2 = const_cast<char*>(b2);
    char * c2 = (char*)(b2);
    cout << *b2 << endl;
    *c2 = 'A';
    cout << *b2 << endl;

    a1 = 40;
    const volatile int * b1 = &a1;
    cout << "typeid of b1 " << typeid(b1).name() << endl;
    int * c1 = const_cast<int *>(b1);
    cout << "typeid of c1 " << typeid(c1).name() << endl;
    return 0;
}
