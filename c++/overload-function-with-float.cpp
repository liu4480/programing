#include<iostream>
using namespace std;
void test(float s,float t)
{
    cout << "Function with float called ";
}
void test(int s, int t)
{
    cout << "Function with int called ";
}
int main()
{
    //call of overloaded ‘test(double, double)’ is ambiguous
    //     test(3.5, 5.6);
    //floating point literals (compile time constants) are 
    //treated as double unless explicitly specified by a suffix
    //test(3.5, 5.6);
    test(3.5f, 5.6f);
    return 0;
}
