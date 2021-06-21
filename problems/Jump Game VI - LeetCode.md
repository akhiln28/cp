---
Created Time: Dec 19, 2020 5:08 PM
Last edited time: Feb 22, 2021 9:23 PM
Points: 1650
Related To: Jump%20Game%2004428277492840a7947a1daa2ce5707d.md
Source: https://leetcode.com/problems/jump-game-vi/
Status: ok
Tags: jumping
---

# Jump Game VI - LeetCode

You are given a **0-indexed** integer array `nums` and an integer `k`.
You are initially standing at index `0`. In one move, you can jump at most `k` steps forward without going outside the boundaries of the array. That is, you can jump from index `i` to any index in the range `[i + 1, min(n - 1, i + k)]` **inclusive**.
You want to reach the last index of the array (index `n - 1`). Your **score** is the **sum** of all `nums[j]` for each index `j` you visited in the array.
Return *the **maximum score** you can get*.
**Example 1:**
```
Input: nums = [1,-1,-2,4,-7,3], k = 2
Output: 7
Explanation: You can choose your jumps forming the subsequence [1,-1,4,3] (underlined above). The sum is 7
```
**Example 2:**
```
Input: nums = [10,-5,-2,4,0,3], k = 3
Output: 17
Explanation: You can choose your jumps forming the subsequence [10,4,3] (underlined above). The sum is 17.
```
**Example 3:**
```
Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
Output: 0
```
**Constraints:**
- `1 <= nums.length, k <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
---
```cpp
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size(); 
        vector<int> dp(n); 
        set<pair<int, int>> se; 
        se.insert({nums[0], 0}); 
        dp[0] = nums[0]; 
        for (int i = 1; i < n; i++)
        {
						// maximum score among (dp[i - k], ...dp[i - 1]) (from set)
            dp[i] = nums[i] + (*prev(se.end())).first;
            if (se.size() == k)
            {
                se.erase({dp[i - k], i - k});
            }
            se.insert({dp[i], i}); 
        }
        return dp[n - 1]; 
    }
};
```
Patterns: [Array](Array.md)