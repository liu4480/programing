/*
 * Array algorithms in C++ STL (all_of, any_of, none_of, copy_n and iota)
 */

/*
 * copy_n() copies one array elements to new array. This type of copy
 * creates a deep copy of array. This function takes 3 arguments, source
 * array name, size of array and the target array name.
 */

/*
 * iota() function is used to assign continuous values to array. This 
 * function accepts 3 arguments, the array name, size, and the starting
 * number.
 */

// C++ code to demonstrate working of all_of()
#include <iostream>
#include <algorithm> // for all_of(), any_of, none_of, copy_n
#include <numeric>   // for iota()
using namespace std;
int main()
{
    // Initializing array
    int ar[6] =  {1, 2, 3, 4, 5, -6};
    int ar1[6];
    // Checking if all elements are positive
    all_of(ar, ar+6, [](int x) { return x>0; })?
          cout << "All are positive elements" <<endl :
          cout << "Not all are positive elements" << endl;
    all_of(ar, ar+5, [](int x) { return x>0; })?
          cout << "All are positive elements" << endl :
          cout << "Not all are positive elements" << endl;

    any_of(ar, ar+6, [](int x){ return x<0; })?
          cout << "There exists a negative element" << endl :
          cout << "All are positive elements" << endl;

    // Checking if no element is negative
    none_of(ar, ar+6, [](int x){ return x<0; })?
          cout << "No negative elements" << endl :
          cout << "There are negative elements" << endl;

    copy_n(ar, 6, ar1);
    cout << "The new array after copying is : ";
    for (int i=0; i<6 ; i++)
          cout << ar1[i] << " ";
    cout << endl;

    iota(ar, ar+6, 20);
    for (int i=0; i<6 ; i++)
          cout << ar[i] << " ";
    cout << endl;

    return 0;

}
