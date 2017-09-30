/*
 *
 * Templates are the foundation of generic programming, which involve 
 * writing code in a way that is independent of any particular type.
 * 
 * A Macro is a fragment of code which has been given a name. Whenever
 * the name is used, it is replaced by the contents of the macro.
 * 
 * Vectors are same as dynamic arrays with the ability to resize itself
 * automatically when an element is inserted or deleted, with their
 * storage being handled automatically by the container.
 */

/* 
 * 1. Using Range based for loop: This is very cool feature in C++11 and
 * would be considered best if you want to iterate from begins to end.
 * This code shows how to use ranged for loops to iterate through an
 * array and a vector:
 */
// C++ program to demonstrate range based for
// loops for accessing vector and array elements
#include<iostream>
#include <vector>
using namespace std;
 
int main()
{
    // Create a vector object that
    // contains 5 elements
    vector<int> vec = {0, 1, 2, 3, 4};
 
    // Type inference by reference using auto.
    // Range based loops are preferred when no
    // modification is needed in value
    for (const auto &value : vec)
        cout << value << ' ';
 
    cout << '\n';
 
    // Basic 5 element integer array
    int array[]= {1, 2, 3, 4, 5};
    for (const auto &value: array)
        cout << value << " ";
 
    return 0;
}

/* 
 * 2. Initializer list: This type is used to access the values in a C++ 
 * initialization list. Here the objects of this type are automatically
 * constructed by the compiler from initialization list declarations,
 * which is a list of comma-separated elements enclosed in braces.
 */
#include<iostream>
 
template<typename T>
void printList(std::initializer_list<T> text)
{
    for (const auto & value: text)
        std::cout << value << " ";
}
 
// Driver program
int main()
{
    // Initialization list
    printList( {"One", "Two", "Three"} );
    return 0;
}

/* 
 * 3. Assigning Maximum or Minimum value: This one is useful to avoid
 * extra effort in writing max() or min() function.
 */
// Call by reference is used in x
template<typename T, typename U>
static inline void amin(T &x, U y)
{
    if (y < x)
        x = y;
}
 
// call by reference is used in x
template<typename T, typename U>
static inline void amax(T &x, U y)
{
    if (x < y)
        x = y;
}
 
// Driver program to find the Maximum and Minimum value
int main()
{
    int max_val = 0, min_val = 1e5;
    int array[]= {4, -5, 6, -9, 2, 11};
 
    for (auto const &val: array)
 
        // Same as max_val = max (max_val, val)
        // Same as min_val = min (min_val,val)
        amax(max_val, val), amin (min_val, val);
 
 
    std::cout << "Max value = " << max_val << "\n"
              << "Min value = " << min_val;
    return 0;
}

/* 
 * 4. Fast Input/Output in C/C++: In Competitive programming, you must 
 * read Input/Output as fast as possible to save valuable time.
 */
#include <bits/stdc++.h>
 
template<typename T> void scan(T &x)
{
    x = 0;
    bool neg = 0;
    register T c = getchar();
 
    if (c == '-')
        neg = 1, c = getchar();
 
    while ((c < 48) || (c > 57))
        c = getchar();
 
    for ( ; c < 48||c > 57 ; c = getchar());
 
    for ( ; c > 47 && c < 58; c = getchar() )
        x= (x << 3) + ( x << 1 ) + ( c & 15 );
 
    if (neg) x *= -1;
}
 
template<typename T> void print(T n)
{
    bool neg = 0;
 
    if (n < 0)
        n *= -1, neg = 1;
 
    char snum[65];
    int i = 0;
    do
    {
        snum[i++] = n % 10 + '0';
        n /= 10;
    }
 
    while (n);
    --i;
 
    if (neg)
        putchar('-');
 
    while (i >= 0)
        putchar(snum[i--]);
 
    putchar('\n');
}
 
// Driver Program
int main()
{
    int value;
 
    // Taking input
    scan(value);
 
    // Printing output
    print(value);
    return 0;
}

/* 
 * 5. Using Macros as for loop: Perhaps, it would not be good to use such
 * micros as it would reduce the readability of code but for writing fast
 * code you can take that risk!
 */
#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
 
 
// Driver program to test above Macros
int main()
{
    int i;
    int array[] = {4, 5, 6, 9, 22, 11};
    int size= sizeof(array)/sizeof(array[0]);
     
    // Default 0 index based loop
    rep(i, size)     
        cout << array[i] << " ";
    cout<<"\n";
     
    // Starting index based loop
    REP(i, 1, size-1)    
        cout << array[i] << " ";
    cout<<"\n";
     
    // Reverse for loop
    REPR(i, size-1,0)    
        cout << array[i] << " ";
    return 0;
}

/* 
 * 6. Using “bits/stdc++.h”: Instead of adding tons of #include lines, 
 * just use #include The files includes all the header files you’ll
 * need in competitive programming, saving a lot of your time.
 */

/*
 * 7. Containers: Using various containers like vector, list, map etc
 * enables * one to use the pre-defined functions and reduces the size
 * of code considerably (more often than not)
 */

/*
 * 8. Fast cin and cout: If you use cin and cout for I/O, just add the
 * following line just after the main().
 * std::ios_base::sync_with_stdio(false);
 */

/*
 * 9. auto: Using auto to declare dataypes can save lot of time during
 * programming contests. When a variable is defined as auto, compiler
 * determines its type during compile-time.
 */

/*
 * 10. Libraries and pre-defined functions: Using builtin functions such
 * as __gcd(A,B), swap, _builtin_popcount(R), _builtin_clz(R) etc wherever
 * thet can be applied.
 */
