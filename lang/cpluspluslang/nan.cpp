#include<iostream>
#include<cmath> // for sqrt()
using namespace std;
int main()
{
    float a = sqrt(2), b = sqrt(-2);
 
    // Prints the number (1.41421)
    cout << a << endl;
    a == a ? cout << "It is a real number" << endl:
             cout << "It is NaN" << endl;
    !isnan(a) ? cout << "It is a real number" << endl:
             cout << "It is NaN" << endl;
    // Prints "nan" exception
    // sqrt(-2) is complex number
    cout << sqrt(b) << endl;
    b == b ? cout << "It is a real number" << endl:
             cout << "It is NaN" << endl;
    !isnan(b) ? cout << "It is a real number" << endl:
             cout << "It is NaN" << endl;
 
    return 0;
}
