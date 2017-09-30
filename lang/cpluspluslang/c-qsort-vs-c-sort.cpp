/*
 * Comparison to qsort and sort()
 * 1. Implementation details:
 * As the name suggests, qsort function uses QuickSort algorithm to sort 
 * the given array, although the C standard does not require it to 
 * implement quicksort.
 * 
 * C++ sort function uses introsort which is a hybrid algorithm. Different
 * implementations use different algorithms. The GNU Standard C++ library, 
 * for example, uses a 3-part hybrid sorting algorithm: introsort is
 * performed first (introsort itself being a hybrid of quicksort and heap
 * sort) followed by an insertion sort on the result.
 * 
 * 2. Complexity :
 * The C standard doesn’t talk about its complexity of qsort. The new C++11
 * standard requires that the complexity of sort to be O(Nlog(N)) in the
 * worst case. Previous versions of C++ such as C++03 allow possible worst
 * case scenario of O(N^2). Only average complexity was required to be 
 * O(N log N).
 * 
 * 3. Running time:
 * STL’s sort ran faster than C’s qsort, because C++’s templates generate
 * optimized code for a particular data type and a particular comparison
 * function.
 *
 * STL’s sort runs 20% to 50% faster than the hand-coded quicksort and 250%
 * to 1000% faster than the C qsort library function. C might be the 
 * fastest language but qsort is very slow.
 *
 * 4. Flexibility:
 * STL’s sort works for all data types and for different data containers
 * like C arrays, C++ vectors, C++ deques, etc and other containers that
 * can be written by the user. This kind of flexibility is rather difficult
 * to achieve in C.
 *
 * 5. Safety:
 * Compared to qsort, the templated sort is more type-safe since it does
 * not require access to data items through unsafe void pointers, as qsort
 * does.
 */

//When we tried to sort one million integers on C++14, Time taken by C qsort() was 0.247883 sec and time taken by C++ sort() was only 0.086125 sec
// C++ program to demonstrate performance of
// C qsort and C++ sort() algorithm
#include <bits/stdc++.h>
using namespace std;
 
// Number of elements to be sorted
#define N 1000000
 
// A comparator function used by qsort
int compare(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}
 
// Driver program to test above functions
int main()
{
    int arr[N], dupArr[N];
 
    // seed for random input
    srand(time(NULL));
 
    // to measure time taken by qsort and sort
    clock_t begin, end;
    double time_spent;
 
    // generate random input
    for (int i = 0; i < N; i++)
        dupArr[i] = arr[i] = rand()%100000;
 
    begin = clock();
    qsort(arr, N, sizeof(int), compare);
    end = clock();
 
    // calculate time taken by C qsort function
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
 
    cout << "Time taken by C qsort() - "
         << time_spent << endl;
 
    time_spent = 0.0;
 
    begin = clock();
    sort(dupArr, dupArr + N);
    end = clock();
 
    // calculate time taken by C++ sort
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
 
    cout << "Time taken by C++ sort() - "
         << time_spent << endl;
 
    return 0;
}
