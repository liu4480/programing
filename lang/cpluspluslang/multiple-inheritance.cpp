#include<iostream>
using namespace std;

class A
{
public:
  A()  { cout << "A's constructor called" << endl; }
};

class B
{
public:
  B()  { cout << "B's constructor called" << endl; }
};

class C: public A, public B  // Note the order
//class C: public B, public A  // Note the order
{
public:
  C()  { cout << "C's constructor called" << endl; }
};

#include<iostream>
using namespace std;
class Person {
   // Data members of person 
public:
    //constructor of ‘Person’ is called two timesi without inheritance of 
    //virtual. Destructor of ‘Person’ will also be called two times
    Person(int x)  { cout << "Person::Person(int ) called" << endl;   }
    Person() { cout << "Person::Person() called" << endl;}
};

//constructor of ‘Person’ is called two timesi without inheritance of 
//virtual. Destructor of ‘Person’ will also be called two times
//class Faculty : public Person {
class Faculty : virtual public Person {
   // data members of Faculty
public:
    Faculty(int x):Person(x)   {
       cout<<"Faculty::Faculty(int ) called"<< endl;
    }
};

//constructor of ‘Person’ is called two timesi without inheritance of 
//virtual. Destructor of ‘Person’ will also be called two times
//class Student : public Person {
class Student : virtual public Person {
   // data members of Student
public:
    Student(int x):Person(x) {
        cout<<"Student::Student(int ) called"<< endl;
    }
};

class TA : public Faculty, public Student  {
public:
//How to call the parameterized constructor of the ‘Person’ class? 
//The constructor has to be called in ‘TA’ class
//    TA(int x):Student(x), Faculty(x)   {
    TA(int x):Student(x), Faculty(x), Person(x)   {
        cout<<"TA::TA(int ) called"<< endl;
    }
};

int main()
{
    C c;
    TA tal(30);
    return 0;
}
