#include<iostream>
using namespace std;
 
int &fun()
{
    static int x = 10;
    return x;
}

int &fun2()
{
    //reference to local var returned.
    int x = 10;
    return x;
}

int func1(int &x)
{
    return x;
}

int main()
{
    int a=10;
    fun() = 30;
    cout << fun();
    cout << endl << func1(a) << endl;
    fun2() = 30;
    cout << fun2() << endl;
    // the following line will get a compile error that an reference not initialized
    //cout << endl << func1(10) << endl;
    int x=10;
    int *ptr = &x;
    //this line is error
    //int &*ptr1 = ptr;
    int * ptr1 = NULL;
    // this line is segment fault
    //int & ref = * ptr1;
    //cout << ref << endl;
    return 0;
}
