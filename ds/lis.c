// Last Update:2018-03-02 13:49:12
/**
 * @file lis.c
 * @brief 
 * @author bliu@suse.com
 * @version 0.1.00
 * @date 2018-03-02
 */
#include <iostream>
#include <vector>
 
// Binary search (note boundaries in the caller)
int CeilIndex(std::vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }
 
    return r;
}
 
int LongestIncreasingSubsequenceLength(std::vector<int> &v, std::vector<int> &tail) {
    if (v.size() == 0)
        return 0;
 
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            // new smallest value
            tail[0] = v[i];
        else if (v[i] > tail[length-1])
            // v[i] extends largest subsequence
            tail[length++] = v[i];
        else
            // v[i] will become end candidate of an existing subsequence or
            // Throw away larger elements in all LIS, to make room for upcoming grater elements than v[i]
            // (and also, v[i] would have already appeared in one of LIS, identify the location and replace it)
            tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    }
 
    return length;
}
 
int main() {
    std::vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    std::vector<int> v1(v.size(), 0);
    int length = LongestIncreasingSubsequenceLength(v, v1);

    std::cout << "Length of Longest Increasing Subsequence is " << length << "\n";
    for(size_t i = 0; i < length; i++)
        std::cout << v1[i] << " ";
    std::cout << "\n";
   return 0;
}
