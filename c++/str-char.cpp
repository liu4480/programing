#include<iostream>
#include<ios> //for streamsize
#include<limits> // for numeric_limits
using namespace std;

int main()
{
    int a;
    char ch[80];

    cin >> a;
    //method 1.discards everything in the input stream including the newline. 
    //cin.ignore(numeric_limits<streamsize>::max(),'\n');
    //2. Typing “cin>>ws” after “cin” statement tells the compiler to ignore buffer and 
    //also to discard all the whitespaces before the actual content of string or character array.
    //3. cin.sync() does not always work, According to C++11 and above standards
    cin >> ws;
    cin.getline(ch, 80);

    cout << a << endl;
    cout << ch << endl;

    return 0;
}
