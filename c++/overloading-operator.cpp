#include<iostream>
using namespace std;
 
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)  {real = r;   imag = i;}
     
    // This is automatically called when '+' is used with
    // between two Complex objects
    Complex operator + (Complex const &obj) {
         Complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
    void print() { 
        cout << real;
        if(imag < -1) 
            cout << imag;
        else if(imag == -1)
            cout << "-";
        else if(imag == 0)
            return;
        else if(imag == 1)
            cout << "+";
        else
            cout << "+" << imag;
        cout <<"i"<< endl;
    }
    friend Complex operator - (Complex const &, Complex const &);
};

Complex operator - (Complex const &c1, Complex const &c2)
{
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+"
    c3.print();
    c3 = c1 - c2;
    c3.print();
}
