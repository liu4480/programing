#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Number of Strings and Size of String – both the values are fixed.
void func1()
{
    char color[4][10] = {"Blue", "Red", "Orange", "Yellow"};
    for(int i = 0; i < 4; i++)
        cout << color[i] << endl;
}

//Array is of fixed Size, only C++
void func2()
{
    string color[4] = {"Blue", "Red", "Orange", "Yellow"};
    for(int i = 0; i < 4; i++)
        cout << color[i] << endl;
}

//use vector, only C++
void func3()
{
    vector <string> colour;
    colour.push_back("Blue");
    colour.push_back("Red");
    colour.push_back("Orange");
    colour.push_back("Yellow");
                 
    // Print Strings stored in Vector
    for (int i=0; i<colour.size(); i++)    
        cout << colour[i] << "\n"; 
}

int main()
{
    func1();
    func2();
    func3();
    return 0;
}
