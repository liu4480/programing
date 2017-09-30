#include<iostream>
using namespace std;

int main()
{
    char buffer[256];
    //this line will disable sync with stdio, and make program faster
    std::ios::sync_with_stdio(false);
    while (cin >> buffer)
    {
    }
    return 0;
}
