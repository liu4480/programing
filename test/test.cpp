// Last Update:2017-09-25 16:57:36
/**
 * @file test.cpp
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2017-09-25
 */
#include<iostream>
using namespace std;

class A
{
  int x;
public:
  void setX(int i) {x = i;}
  int getX(){return x;}
  void print() { cout << x; }
};

class B: virtual public A
{
public:
  B()  { setX(10); }
};

class C: virtual public A  
{
public:
  C()  { setX(20); }
};

class D: public B, public C {
};

int main()
{
    D d;
    cout << d.getX() << endl;
    return 0;
}
