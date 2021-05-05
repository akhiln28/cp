#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

/*
    title: m_1850_adjacent_swaps_to_reach_the_kth_smallest_number.cpp
    author: Akhil
    date: 2021-05-03
    time: 09:46:17
    ==================================================
    Kth smaller element starting from num
    Getting the Kth smaller element can be done easily in O(k * n)
    Need to find the minimum number of adjacent swaps needed in num to get the Kth smaller number
        examples:
            412 -> 421 ans: 2
            123 -> 132 ans: 1
            11112 -> 21111 ans: 4
            11122 -> 22111 ans: 4 + 3 = 7
            1234 -> 4321 ans: 3 + 1 + 1 + 3
                1: 1 to 4
                2: 2 to 3
                3: 3 to 2
                4: 4 to 1
                1234 - 1243 - 1423 - 4123 (3 steps)
                4123 - 4132 - 4312 (2 steps)
                4312 - 4321 (1 step)
                1234 - 1243 - 2143 - 2413 - 4213 - 4231 - 4321
            I am guessing, this can be hashing question..
*/
class Solution {
public:
    int min_adjacent_swaps(string num1, string num2)
    {
        int n = num1.length();
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (num1[i] != num2[j]) j++;
            while (i < j)
            {
                swap(num2[j], num2[j - 1]); j--;
                ret++;
            }
        }
        return ret;
    }
    int getMinSwaps(string num, int k) {
        string num1 = num;
        while (k--)
        {
            next_permutation(num1.begin(), num1.end());
        }
        return min_adjacent_swaps(num, num1);
    }
};
int main()
{
    string num = "11112";
    int k = 4;
    Solution obj;
    auto ret = obj.getMinSwaps(num, k);
    cout << ret << endl;
    return 0;
}