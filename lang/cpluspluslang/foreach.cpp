#include <iostream>
using namespace std;
 
int main()
{
  int arr[] = {10, 20, 30, 40};
 
  // Printing elements of an array using
  // foreach loop
  // error: range-based ‘for’ loops are not allowed in C++98 mode
  for (int x : arr)
     cout << x << endl;
}
