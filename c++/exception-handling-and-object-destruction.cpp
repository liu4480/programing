//When an exception is thrown, destructors of the objects (whose scope ends 
//with the try block) is automatically called before the catch block gets 
//exectuted. 

// but what happens when an exception is thrown from a constructor?
/*  
 * #include <iostream>
 * using namespace std;
 *  
 * class Test1 {
 * public:
 *   Test1() { cout << "Constructing an Object of Test1" << endl; }
 *   ~Test1() { cout << "Destructing an Object of Test1" << endl; }
 * };
 *  
 * class Test2 {
 * public:
 *   // Following constructor throws an integer exception
 *   Test2() { cout << "Constructing an Object of Test2" << endl; 
 *             throw 20; }
 *   ~Test2() { cout << "Destructing an Object of Test2" << endl; }
 * };
 *  
 * int main() {
 *   try {
 *     Test1 t1;  // Constructed and destructed
 *     Test2 t2;  // Partially constructed
 *     Test1 t3;  // t3 is not constructed as this statement never gets executed
 *   } catch(int i) {
 *     cout << "Caught " << i << endl;
 *   }
 * }
 * 
 * Destructors are only called for the completely constructed objects. 
 * When constructor of an object throws an exception, destructor for that 
 * object is not called.
 */

#include <iostream>
using namespace std;
 
class Test {
  static int count;
  int id;
public:
  Test() {
    count++;
    id = count;
    cout << "Constructing object number " << id << endl;
    if(id == 4)
       throw 4;
  }
  ~Test() { cout << "Destructing object number " << id << endl; }
};
 
int Test::count = 0;
 
int main() {
  try {
    //1,2,3,4 will call Constructing function, but 4 will throw exception
    Test array[5];
  } catch(int i) {
    //Caught the exception, and 4 will not call Destructing function
    cout << "Caught " << i << endl;
  }
}
