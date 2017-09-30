#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printDistinctSubStrs(string str)
{
    map<pair<char, char>, int> dPairs;

    for(int i=0; i < str.size() - 1; i++)
        dPairs[make_pair(str[i], str[i + 1])]++;

    cout << "Distinct sub-strings with counts:\n";

    for(auto it = dPairs.begin(); it != dPairs.end(); it++)
        cout << it->first.first << it->firse.second
             << "-" << it->second << " ";
}

int main()
{
    string str = "abcacdcacabacaassddssklac";
    printDistinctSubStrs(str);
    return 0;
}
