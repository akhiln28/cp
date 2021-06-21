---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Jan 09, 2021
Last edited time: Mar 01, 2021 8:41 AM
Points: 1700
Pomos (25 mins): 1
Problem Statement: take out first or the last element from array and add it to the sum. try to make X
Source: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
Status: done
Tags: binary search
---

# Minimum Operations to Reduce X to Zero

You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this **modifies** the array for future operations.
Return *the **minimum number** of operations to reduce* `x` *to **exactly*** `0` *if it's possible, otherwise, return* `-1`.
**Example 1:**
```
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
```
**Example 2:**
```
Input: nums = [5,6,7,8,9], x = 4
Output: -1
```
**Example 3:**
```
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
```
**Constraints:**
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`
- `1 <= x <= 10^9`
---
Create prefix and suffix arrays as shown below. 
```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int pref[n], suff[n];
         
        // calculating prefix and suffix sums
        pref[0] = nums[0]; 
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + nums[i]; 
        }
        suff[n - 1] = nums[n - 1]; 
        for (int i = n - 2; i >= 0; i--)
        {
            suff[i] = suff[i + 1] + nums[i]; 
        }
        reverse(suff, suff + n);
        int ans = INT_MAX; 
        for (int i = 0; i < n; i++)
        {
            if (pref[i] > x) break; 
            if (pref[i] == x) 
            {
                ans = min(ans, i + 1); 
                break;
            }
            if (i == n - 1) break;
            auto it = lower_bound(suff, suff + n - i - 1, x - pref[i]); 
            if (it != suff + n - i - 1 and *it == x - pref[i])
            {
                ans = min(ans, i + 1 + (int) (it - suff) + 1); 
            }
        }        auto it = lower_bound(suff, suff + n, x);
        if (it != suff + n and *it == x)
        {
            ans = min(ans, (int) (it - suff) + 1); 
        }
        // cout << ans << endl;
        return (ans == INT_MAX) ? -1 : ans; 
    }
};
```
Patterns: [Array](Array.md)[Cumulative](Cumulative.md)