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
    title: m_1838_frequency_of_the_most_frequent_element.cpp
    author: Akhil
    date: 2021-04-28
    time: 07:44:29
    ==================================================
    Given an array of integers, in one operation you can increase any integer by 1. Find the maximum frequency of any element after atmost k operations.
    (1, 2, 4), k = 5 -> (4,4,4) ✅ when k is larger than n * maxe then ans is n
    (1, 4, 8, 13), k = 5 ->

    first sort the array
    for each element check what is the total ops required to make all the elements to current element.
        you have to iterate from i to 0

*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long cum = 0;
        int ans = 1;
        // cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            cum += nums[i];
            if (i and nums[i] == nums[i - 1]) {ans = i + 1; continue;}
            long long total_required = (i + 1) * (1LL) * nums[i];
            long long rem = total_required - cum;
            if (rem <= k) ans = i + 1;
            else break;
        }
        return ans;
    }
};
int main()
{
    vector<int> nums{9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966};
    int k = 3056;
    Solution obj;
    auto ret = obj.maxFrequency(nums, k);
    cout << ret << endl;
    return 0;
}