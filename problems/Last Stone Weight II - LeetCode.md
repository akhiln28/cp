---
Created Time: Dec 19, 2020 11:45 AM
Do Date: Dec 19, 2020
Last edited time: May 11, 2021 9:10 AM
Points: 1500
Pomos (25 mins): 1
Relates: Last%20Stone%20Weight%20III%20-%20Leetcode%20discuss%20e8024262bedf426e9a2866534b7fcf51.md
Source: https://leetcode.com/problems/last-stone-weight-ii/
Status: done
Tags: goldman sachs, new, puzzle
---

# Last Stone Weight II - LeetCode

We have a collection of rocks, each rock has a positive integer weight.
Each turn, we choose **any two rocks** and smash them together. Suppose the stones have weights `x` and `y` with `x <= y`. The result of this smash is:
- If `x == y`, both stones are totally destroyed;
- If `x != y`, the stone of weight `x` is totally destroyed, and the stone of weight `y` has new weight `y-x`.
At the end, there is at most 1 stone left. Return the **smallest possible** weight of this stone (the weight is 0 if there are no stones left.)
**Example 1:**
```
Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We can combine 2 and 4 to get 2 so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1 so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0 so the array converts to [1] then that's the optimal value.
```
**Note:**
1. `1 <= stones.length <= 30`
2. `1 <= stones[i] <= 100`
---
GSai told me that this problem is similar to "**Split the array into two such that the difference between their sum is minimized**". Now I got the intuition.  Based on this, the following code.
`dp[i][j]` → denotes whether we can obtain a sum of j using stones 0...i. 
```cpp
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0); 
        int n = stones.size(); 
        vector<vector<bool>> dp(n + 1, vector<bool> (sum, 0)); 
        int ans = INT_MAX; 
        dp[0][0] = true; 
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = true; 
            for (int j = 1; j < sum; j++)
            {
                dp[i][j] = dp[i - 1][j]; 
                if (j >= stones[i - 1]) dp[i][j] = dp[i][j] || dp[i - 1][j - stones[i - 1]];
                if (dp[i][j]) ans = min(ans, abs(sum - 2 * j)); 
            }
        }
        return ans; 
    }
};
```
Patterns: [Array](Array.md)[Dp](Dp.md)[patterns/Knapsack](patterns/Knapsack.md)