/*
 * getchar_unlocked() – faster input in C/C++ for Competitive Programming
 * 1. Since it is not thread safe, all overheads of mutual exclusion are 
 * avoided and it is faster than getchar().
 * 2. Can be especially useful for competitive programming problems with
 * “Warning: Large I/O data, be careful with certain languages (though
 * most should be OK if the algorithm is well designed)”.
 * 3. There is no issue with using getchar_unlocked() even in multithreaded
 * environment as long as the thread using it is the only thread accessing
 * file object
 * 4. One more difference with getchar() is, it is not a C standard library
 * function, but a POSIX function. It may not work on Windows based 
 * compilers.
 * 5. It is a known fact than scanf() is faster than cin and getchar()
 * is faster than scanf() in general. getchar_unlocked() is faster than
 * getchar(), hence fastest of all.
 * 6. Similarly, there are getc_unlocked() putc_unlocked(), and
 * putchar_unlocked() which are non-thread-safe versions of getc(),
 * putc() and putchar() respectively. 
 */

// A simple C program to demonstrate
// working of putchar_unlocked()
#include <stdio.h>
int main()
{
    // Syntax is same as getchar()
    char c = getchar_unlocked();
 
    putchar_unlocked(c);
 
    return 0;
}
