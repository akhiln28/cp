---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 19, 2020
Last edited time: May 11, 2021 8:58 AM
Points: 1500
Pomos (25 mins): 1
Source: https://leetcode.com/problems/subarray-sum-equals-k/
Status: done
Tags: subarray
---

# Subarray Sum Equals K

Given an array of integers `nums` and an integer `k`, return *the total number of continuous subarrays whose sum equals to `k`*.
**Example 1:**
```
Input: nums = [1,1,1], k = 2
Output: 2
```
**Example 2:**
```
Input: nums = [1,2,3], k = 3
Output: 2
```
**Constraints:**
- `1 <= nums.length <= 2 * 104`
- `1000 <= nums[i] <= 1000`
- `107 <= k <= 107`
---
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0]++; int cum = 0;
        int ans = 0; 
        for (int i = 0; i < nums.size(); i++)
        {
            cum += nums[i];
            if (mp.find(cum - k) != mp.end())
                ans += mp[cum - k];
            mp[cum]++;
        }
        return ans;
    }
};
```
Patterns: [Matrix](Matrix.md)[Hashing](Hashing.md)