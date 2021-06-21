---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Mar 09, 2021
Last edited time: Mar 09, 2021 8:57 AM
Points: 1600
Pomos (25 mins): 2
Status: ok
---

# Number of Longest Increasing Subsequence

Given an integer array `nums`, return *the number of longest increasing subsequences.*
**Notice** that the sequence has to be **strictly** increasing.
**Example 1:**
```
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
```
**Example 2:**
```
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
```
**Constraints:**
- `1 <= nums.length <= 2000`
- `10^6 <= nums[i] <= 10^6`
---
```cpp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0; 
        if (nums.size() == 1) return 1; 
        vector<int> dp(nums.size(), 1), count(nums.size());
        int maxe = 0; 
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] < nums[j]) dp[i] = max(dp[i], 1 + dp[j]); 
            }
            maxe = max(maxe, dp[i]); 
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (dp[j] == dp[i] - 1 and nums[i] < nums[j]) count[i] += count[j]; 
            }
            count[i] = max(1, count[i]); 
        }
        int ans = 0; 
        for (int i = 0; i < nums.size(); i++)
        {
            if (dp[i] == maxe) ans += count[i]; 
        }
        return ans; 
    }
};
```
Patterns: [Array](Array.md)[Dp](Dp.md)