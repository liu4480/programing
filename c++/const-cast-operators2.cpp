#include <iostream>
#include <typeinfo>
using namespace std;

class student
{
private:
    const int roll;
public:
    student(int r):roll(r){}
    void fun() const
    {
        //error: assignment of read-only member ‘student::roll’
        ( const_cast <student*> (this) )->roll = 5;
    }
    int getRoll() { return roll; }
};

int main()
{
    int a1 = 40;
    const int * b1 = &a1;
    char * c1 = (char*)b1;
    cout << a1 << " " << *b1 << endl;
    *c1 = 'A';
    cout << *c1 << *b1 << endl;

    student s(3);
    cout << "Old roll number: " << s.getRoll() << endl;

    s.fun();

    cout << "New roll number: " << s.getRoll() << endl;
    return 0;
}
