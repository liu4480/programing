/*
 * Placement new is a variation new operator in C++. Normal new operator 
 * does two things : 
 * (1) Allocates memory 
 * (2) Constructs an object in allocated memory.
 *
 * Placement new allows us to separate above two things. 
 * In placement new, we can pass a preallocated memory and construct an 
 * object in the passed memory.
 */

/*
 * new vs placement new
 *
 * 1. Normal new allocates memory in heap and constructs objects tehre 
 * whereas using placement new, object construction can be done at 
 * known address.
 * 2. With normal new, it is not known that, at what address or memory 
 * location it’s pointing to, whereas the address or memory location that 
 * it’s pointing is known while using placement new.
 * 3. The deallocation is done using delete operation when allocation is 
 * done by new but there is no placement delete, but if it is needed one 
 * can write it with the help of destructor
 */
// C++ program to illustrate the placement new operator
/* 
 * The operator delete can only delete the storage created in heap, so when
 * placement new is used delete operator cannot be used to delete the 
 * storage. In the case of memory allocation using placement new operator ,
 * since it is created in stack the compiler knows when to delete it and it
 * will handle deallocation of the memory automatically. If required, one 
 * can write it with the help of destructor as shown below.
 */

/*
 * The placement new operator should be used with care. The address which is
 * passed can be a reference or a pointer  pointing to a valid memory 
 * location. It may show error when the address passed is :
 *
 * A pointer such as NULL pointer.
 * A pointer that is not pointing to any location.
 * It cannot be a void pointer unless it points to some location.
 */

#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class Complex
{
private:
    double re_, im_;
public:
    // Constructor
    Complex(double re = 0, double im = 0): re_(re), im_(im)
    {
        cout << "Constructor : (" << re_
             << ", " << im_ << ")" << endl;
    }

    // Destructor
    ~Complex()
    {
        cout << "Destructor : (" << re_ << ", "
             << im_ << ")" << endl;
    }

    double normal()
    {
        return sqrt(re_*re_ + im_*im_);
    }

    void print()
    {
        cout << "|" << re_ <<" +j" << im_
             << " | = " << normal() << endl;
    }
};

int main()
{
    // buffer on stack
    unsigned char buf[sizeof(int)*2] ;

    // placement new in buf
    int *pInt = new (buf) int(3);

    int *qInt = new (buf + sizeof (int)) int(5);
    int *pBuf = (int*)(buf+0) ;
    int *qBuf = (int*) (buf + sizeof(int));
    cout << "Buff Addr           Int Addr" << endl;
    cout << pBuf <<"             " << pInt << endl;
    cout << qBuf <<"             " << qInt << endl;
    cout << "------------------------------" << endl;
    cout << "1st Int             2nd Int" << endl;
    cout << *pBuf << "                         "
         << *qBuf << endl;

    // initial value of X
    int X = 10;

    cout << "Before placement new :" << endl;
    cout << "X : " << X << endl;
    cout << "&X : " << &X << endl;

    // Placement new changes the value of X to 100
    int *mem = new (&X) int(100);

    cout << "\nAfter placement new :" << endl;
    cout << "X : " << X << endl;
    cout << "mem : " << mem << endl;
    cout << "&X : " << &X << endl;

    // buffer on stack
    unsigned char buf1[100];

    Complex* pc = new Complex(4.2, 5.3);
    Complex* pd = new Complex[2];

    // using placement new
    Complex *pe = new (buf1) Complex(2.6, 3.9);

    // use objects
    pc -> print();
    pd[0].print();
    pd[1].print();
    pe->print();

    // Release objects
    // calls destructor and then release memory
    delete pc;

    // Calls the destructor for object pd[0]
    // and then release memory
    // and it does same for pd[1]
    delete [] pd;

    // No delete : Explicit call to Destructor.
    pe->~Complex();

    return 0;
}
