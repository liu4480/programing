/*
 * Before going into deep let us first have a look on the normal 
 * ‘overloaded assignment operator’ that we use.
 * Simple C++ program to demonstrate overloading of assignment operator.
 */

#include <iostream>
#include <cstring>
using namespace std;
 
class anyArrayClass
{
    int size;
    int *ptr;
public:
 
    // Initializer list
    anyArrayClass(int s=0):size(s),
        ptr(size? new int[size]:nullptr) {}
 
    // Copy constructor
    anyArrayClass(const anyArrayClass& obj):size(obj.size),
        ptr(size? new int[size]:nullptr)
    {
        memmove(ptr, obj.ptr, size*sizeof(int));
    }
 
    // Overloaded assignment operator
    anyArrayClass& operator=(const anyArrayClass& obj)
    {
        // self assignment check
        if (this != &obj)
        {
            delete ptr;
            size = obj.size;
            ptr = size? new int[size]: nullptr;
            memmove(ptr, obj.ptr, size*sizeof(int));
            return *this;
        }
    }
    ~anyArrayClass()
    {
        delete[] ptr;
    }
}

/*
 * The above assignment operator does the following things:
 * 1. Self assignment check.
 * 2. If there assignment is not to self, then it does following.
 * a) Deallocating memory assigned to this->ptr
 * b) Allocating new memory to this->ptr and copying the values
 * c) Returning *this
 *
 * Drawbacks of above approach:
 * 1. The self assignment check: Self allocation is done very rarely so the 
 * self assignment check is not relevant in most of the scenarios. This 
 * just slows down the code.
 * 2. Memory deallocation and allocation: As it can be seen that first the 
 * memory is deallocated (leaving the pointer dangling) and then the new 
 * chunk of memory is allocated. Now if due to some reason the memory is not
 * allocated and an exception is thrown than the ‘this->ptr’ will be left 
 * dangling pointing to a deallocated memory. The scenario should be either 
 * the assignment is successful or the object should not be altered at all.
 */

/*
 * Here comes the role of copy-and-swap approach. This approach elegantly 
 * solves the above issue and also provides a scope for code re-usability. 
 * Lets see what exactly is it.
 */

// Simple C++ program to demonstrate use of copy-and-swap
// idiom by improving above code.
#include <iostream>
#include <cstring>
using namespace std;
 
class anyArrayClass
{
    int size;
    int *ptr;
public:
    anyArrayClass(int s=0):size(s),
     ptr(size? new int[size]:nullptr) {}
 
    // Copy constructor
    anyArrayClass(const anyArrayClass& obj):size(obj.size),
                           ptr(size? new int[size]:nullptr)
    {
        memmove(ptr, obj.ptr, size*sizeof(int));
    }
 
    friend void swap(anyArrayClass& obj1, anyArrayClass& obj2)
    {
        std::swap(obj1.size, obj2.size);
        std::swap(obj1.ptr, obj2.ptr);
    }
     
    // overloaded assignment operator
    // argument passed by value. calls copy ctor
    anyArrayClass& operator=(anyArrayClass obj) 
    {
        // calling friend function
        swap(*this, obj);
        return *this;
    }
 
    ~anyArrayClass()
    {
        delete[] ptr;
    }
}

/*
 * In the above example, the parameter to the ‘operator=()’ is passed by
 * value which calls copy constructor to create a anyArrayClass object
 * local to the ‘operator=()’. Than the value of the temp object is
 * swapped with ‘*this’ object (LHS of assignment operator call).
 *
 * Advantages:
 *
 * 1. No more self assignment check needed as the parameter is passed by
 * value (This means no more memory deallocation is needed). Moreover as 
 * self allocation is very rare so the overhead of copying in case of self
 * assignment should not be a problem.
 * 2. Now as copy constructor is used to create the temp object therefore,
 * the swapping will only be done if the temp object is at all created.
 * Basically what we were doing manually there, the compiler is doing it
 * for us in here.
 * 3. Code re-useability: as we can see the ‘operator=()’ does not have
 * much code in its body rather, we are using the copy constructor and
 * swap function to do the job.
 */
