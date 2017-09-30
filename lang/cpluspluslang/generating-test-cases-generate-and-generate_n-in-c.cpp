/*
 * The generate functions assigns random values provided by calling the
 * generator function ‘gen’ to the elements in the range [begin, end).
 * Notice that begin is included in the range but end is NOT included.
 */

/*
 * The generate_n does the same job as generate upto n elements starting
 * from the element pointed to by the begin iterator.
 */

//Following code demonstrates the implementation of generate :
// C++ program to demonstrate generate function in STL
#include <bits/stdc++.h>     
using namespace std;
 
// function to generate random numbers in range [0-999] :
int randomize() 
{   
    return (rand() % 1000); 
}
 
int main () 
{
  // for different values each time we run the code
  srand(time(NULL)); 
   
  vector<int> vect(10); // declaring the vector
 
  // Fill all elements using randomize()
  generate(vect.begin(), vect.end(), randomize);
 
  // displaying the content of vector
  for (int i=0; i<vect.size(); i++)
     cout << vect[i] << " " ;
  cout << endl;

  generate_n(vect.begin(), 6, randomize);
  // displaying the content of vector
  for (int i=0; i<vect.size(); i++)
     cout << vect[i] << " " ;
  cout << endl;

  return 0;
}
