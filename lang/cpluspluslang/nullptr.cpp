#include <iostream>
#include <stdio.h>
using namespace std;
// function with integer argument
int fun(int N)   { cout << "fun(int)"; }
 
// Overloaded function with char pointer argument
int fun(char* s)  { cout << "fun(char *)"; }
 
int main() 
{
    // Ideally, it should have called fun(char *),
    // but it causes compiler error.
    // NULL is typically defined as (void *)0 and 
    // conversion of NULL to integral types is allowed. 
    //fun(NULL);  
    //unlike NULL, nullptr is not implicity convertible
    //or comparable to integral types
    func(nullptr);
}
