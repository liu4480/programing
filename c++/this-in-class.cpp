#include<iostream>
using namespace std;
 
class Test
{
private:
  int x;
  int y;
public:
  Test(int x = 0, int y = 0) { this->x = x; this->y = y;}
  //lvalue required as left operand of assignment
  //void change(Test *t) { this = t; }
  void change(Test *t) { this->x = t->x; }
  void print() { cout << "x = " << x << " y=" << y << endl; }
  static void fun1() { cout << "Inside fun1()" << endl;}
  //‘this’ is unavailable for static member function
  //static void fun2() { cout << "Inside fun2()";this->fun1();}
  static void fun2() { cout << "Inside fun2()" << endl;fun1();}
  //every call will construct a new Test instance
  //Test setX(int a) { x= a; return *this;}
  //Test setY(int b) { y= b; return *this;}
  Test &setX(int a) { x= a; return *this;}
  Test &setY(int b) { y= b; return *this;}
};
 
int main()
{
  Test obj(5);
  Test *ptr = new Test (10);
  obj.change(ptr);
  obj.print();

  obj.fun2();
  obj.setX(10).setY(20);
  obj.print();
  return 0;
}
