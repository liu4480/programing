/*
1. Exception Handling in C++
One of the advantages of C++ over C is Exception Handling. C++ provides 
following specialized keywords for this purpose.

try: represents a block of code that can throw an exception.

catch: represents a block of code that is executed when a particular 
exception is thrown.

throw: Used to throw an exception. Also used to list the exceptions that a 
function throws, but doesn’t handle itself.

2. Why Exception Handling?

Following are main advantages of exception handling over traditional error handling.

1) Separation of Error Handling code from Normal Code: In traditional error handling codes, there are always if else conditions to handle errors. These conditions and the code to handle errors get mixed up with the normal flow. This makes the code less readable and maintainable. With try catch blocks, the code for error handling becomes separate from the normal flow.

2) Functions/Methods can handle any exceptions they choose: A function can throw many exceptions, but may choose to handle some of them. The other exceptions which are thrown, but not caught can be handled by caller. If the caller chooses not to catch them, then the exceptions are handled by caller of the caller.
In C++, a function can specify the exceptions that it throws using the throw keyword. The caller of this function must handle the exception in some way (either by specifying it again or catching it)

3) Grouping of Error Types: In C++, both basic types and objects can be thrown as exception. We can create a hierarchy of exception objects, group exceptions in namespaces or classes, categorize them according to types.
*/

#include <iostream>
using namespace std;

int main()
{
    int x = -1;

    cout << "Before try\n";
    try{
        cout << "Inside try\n";
        if(x < 0)
        {
            throw 'a';
            cout << "After throw(Never executed)\n";
        }
    }
    catch(int x){
        cout << "Exception caught\n";
    }
    //1. Implicit type conversion doesn’t happen for primitive types.
    //2. There is a special catch block called ‘catch all’ catch(…) that 
    //can be used to catch all types of exceptions.
    //3. If an exception is thrown and not caught anywhere, the program 
    //terminates abnormally. 
    //4. A derived class exception should be caught before a base class 
    //exception
    //5. Like Java, C++ library has a standard exception class which is base
    //class for all standard exceptions. All objects thrown by components 
    //of the standard library are derived from this class. Therefore, all
    //standard exceptions can be caught by catching this type
    //6. Unlike Java, in C++, all exceptions are unchecked. Compiler 
    //doesn’t check whether an exception is caught or not
    //7. In C++, try-catch blocks can be nested. Also, an exception can be 
    //re-thrown using “throw; ”
    //8. When an exception is thrown, all objects created inside 
    //the enclosing try block are destructed before the control is 
    //transferred to catch block.
    catch(...) {
        cout << "Default Exception\n";
    }
    cout << "After catch(Will be executed)\n";
    return 0;
}
