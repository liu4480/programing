// Last Update:2018-04-02 10:05:08
/**
 * @file find_num.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-04-02
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
using namespace std;

bool used[10];
vector <long long> v;

void find(int k, long long a)
{
    if (k && a%k != 0)
        return;
    
    if (k == 9)
    {
        v.push_back(a);
        return;
    }

    for(int i = 1; i <= 9; i++)
    {
        if(!used[i])
        {
            used[i] = 1;
            find(k+1, a*10 + i);
            used[i] = 0;
        }
    }
}

int main()
{
    find(0, 0);
    for(int i = 0; i < v.size(); i++)
        printf("%lld ", v[i]);

    return 0;
}
