#include<iostream>
using namespace std;
class Test
{
    int a;
    static int b;
public:
    Test() { a = 1; }
 
    // Local parameter 'a' hides class member 'a'
    void func1(int a)  { cout << a << endl; }
    void func2(int a)  { cout << this->a << endl; }
    void func3(int b)  { cout << Test::b << endl; }
};

int Test::b=10;
 
int main()
{
    Test obj;
    int k = 3 ;
    obj.func1(k);
    obj.func2(k);
    obj.func3(k);
    return 0;
}
