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
    title: m_1798_maximum_number_of_consecutive_values_you_can_make.cpp
    author: Akhil
    date: 2021-03-24
    time: 07:44:00
    ==================================================
    Given a set of coins, you can choose some elements and get its sum. Find the maximum number of consecutive sums that you can get staring from 0.
    Consider few examples:
    1, 2, 3, 4
        0
        1
        2
        3
        4
        1 + 4
        2 + 4
        3 + 4
        1 + 3 + 4
        2 + 3 + 4
        1 + 2 + 3 + 4
    Each number can be up to 10^4, I guess we cannot use dynamic programming.

    We an try to use a greedy approach i.e. simulation?
    If it is a simulation, we start at 0 -> 1 (should be present in array) ->
    LOGIC: Increasing the horizon
    =============================
    If you have made values from 0 to x and you have a value v (<= x + 1), then you can make 0 to x + v
    1, 2, 5, 7
        initiall at 0
        choose element upto 0 + 1 i.e. 1, remove this from array {2, 5, 7}
        choose element upto 1 + 1 i.e. 2, remove this from array {5, 7}
        choose element upto 3 + 1 i.e. 4 not found break
*/
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.rbegin(), coins.rend());
        int horizon = 0;
        while (coins.size())
        {
            if (coins.back() <= 1 + horizon)
            {
                // expanding the horizon
                horizon += coins.back();
                coins.pop_back();
            }
            else break;
        }
        return 1 + horizon;
    }
};
int main()
{
    vector<int> coins{1, 3};
    Solution obj;
    auto ret = obj.getMaximumConsecutive(coins);
    cout << ret << endl;
    return 0;
}