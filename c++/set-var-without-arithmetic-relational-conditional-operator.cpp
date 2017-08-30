#include<iostream>
using namespace std;

int calculate1(int a, int b, int c)
{
    return ((1 - c) * a) + (c * b); 
}

int calculate2(int a, int b, int c)
{
    return (a*!c)|(b*c);
}

int calculate3(int a, int b, int c)
{
    return (a+b) - (!c*b)-(c*a);
}

int calculate4(int a, int b, int c)
{
    int arr[] = {a,b};
    return arr[c];
}

int main()
{
   int a = 5, b = 10, c = 0;
     
   int x = calculate1(a, b, c);
   cout << x << endl;
     
   x = calculate2(a, b, c);
   cout << x << endl;

   x = calculate3(a, b, c);
   cout << x << endl;

   x = calculate3(a, b, c);
   cout << x << endl;
   return 0;
}
