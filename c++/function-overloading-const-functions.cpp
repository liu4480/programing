#include<iostream>
using namespace std;

class Test
{
protected:
    int x;
public:
    Test (int i):x(i) { }
    void fun() const
    {
        cout << "fun() const called " << endl;
    }
    void fun()
    {
        cout << "fun() called " << endl;
    }
};

//void fun(const int) and void fun(int) are the same define, cannot be overloaded
//while fun(const int*) and void fun(int*) not the same, can be overloaded
// fun(const int&) and void fun(int&) not the same, can be overloaded
void fun(const int& i)
{
    cout << "fun(const int) called ";
}

void fun(int& i)
{
    cout << "fun(int ) called " ;
}

int main()
{
    Test t1 (10);
    const Test t2 (20);
    t1.fun();
    t2.fun();
    const int i = 10;
    fun(i);
    return 0;
}
