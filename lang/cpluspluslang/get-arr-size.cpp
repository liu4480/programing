#include <iostream>
#include <bits/stdc++.h>

using namespace std;
 
template <typename T, size_t n>
void findSize(T (&arr)[n])
{
    cout << sizeof(T) * n << endl;
}
 
int main()
{
    int arr[] = {1, 2 ,3 ,4 ,5, 6};
    int size = *(&arr + 1) - arr;
    cout << "Number of elements in arr[] is " << size << endl;
    findSize(arr);
}
