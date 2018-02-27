// Last Update:2018-03-07 15:04:49
/**
 * @file maximum-profit-by-buying-and-selling-a-share-at-most-twice.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-07
 */
#include <iostream>
using namespace std;

int maxProfit(int price[], int n)
{
    int * profit = new int[n];
    for(int i=0; i < n; i++)
        profit[i] = 0;

    int max_price = price[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        if(price[i] > max_price)
            max_price = price[i];

        profit[i] = max(profit[i + 1], max_price - price[i]);
    }

    int min_price = price[0];
    for(int i = 1; i < n; i++)
    {
        if(price[i] < min_price)
            min_price = price[i];

        profit[i] = max(profit[i - 1], profit[i] + (price[i] - min_price));
    }
    int result = profit[n - 1];
    delete []profit;
    return result;
}

int main()
{
    int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = sizeof(price)/sizeof(price[0]);
    cout << "Maximum Profit = " << maxProfit(price, n) << endl;
    return 0;
}
