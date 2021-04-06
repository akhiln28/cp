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
    title: m_1814_count_nice_pairs_in_array.cpp
    author: Akhil
    date: 2021-04-06
    time: 07:09:53
    ==================================================
    nums[i] + nums1[j] = nums[j] + nums1[i]; -> where nums1 contains the reverse of elements in nums.
    brute force - O(n^2) i.e. checking all the pairs.
    consider 42, 11, 1, 97
        1, 11, 42, 97
        1, 11, 24, 79
        nums[i] + nums1[j] = nums[j] + nums1[i];
        nums[i] - nums1[i] = nums[j] - nums1[j];
*/

class Solution {
public:
    const int mod = 1e9 + 7;
    int countNicePairs(vector<int>& nums) {

        vector<int> revnums = nums;
        for (int i = 0; i < revnums.size(); i++)
        {
            string str = to_string(revnums[i]);
            reverse(str.begin(), str.end());
            revnums[i] = stoi(str);
        }
        unordered_map<int, long long> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i] - revnums[i]]++;
        }
        long long ans = 0;
        for (auto [k, v] : mp)
        {
            ans = (ans + (v * (v - 1))/2) % mod;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums{13,10,35,24,76};
    Solution obj;
    auto ret = obj.countNicePairs(nums);
    cout << ret << endl;
    return 0;
}