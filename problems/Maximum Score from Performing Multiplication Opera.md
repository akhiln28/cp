---
Created Time: Feb 20, 2021 11:22 PM
Do Date: Feb 21, 2021
Last edited time: Mar 04, 2021 9:28 AM
Points: 1600
Pomos (25 mins): 4
Related To: Stone%20Game%20VII%202888cd0740d34f57bd073f679581ed73.md
Source: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
Status: done
---

# Maximum Score from Performing Multiplication Operations - Leetcode

You are given two integer arrays `nums` and `multipliers` of size `n` and `m` respectively, where `n >= m`. The arrays are **1-indexed**.
You begin with a score of `0`. You want to perform **exactly** `m` operations. On the `ith` operation **(1-indexed)**, you will:
- Choose one integer `x` from **either the start or the end** of the array `nums`.
- Add `multipliers[i] * x` to your score.
- Remove `x` from the array `nums`.
Return *the **maximum** score after performing* `m` *operations.*
**Example 1:**
```
Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
```
**Example 2:**
```
Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
The total score is 50 + 15 - 9 + 4 + 42 = 102.
```
**Constraints:**
- `n == nums.length`
- `m == multipliers.length`
- `1 <= m <= 10^3`
- `m <= n <= 10^5`
- `1000 <= nums[i], multipliers[i] <= 1000`
---
```cpp
class Solution {
public:
    int memo[1001][1001]; 
    int dp(int l, int i, vector<int>& nums, vector<int>& mult)
    {
        if (i == mult.size()) return 0; 
        if (memo[l][i] != -1) return memo[l][i]; 
        // (l) + (n - r - 1) = i -> r = n - i + l - 1
        int r = nums.size() - i + l - 1; 
				// pick left
        memo[l][i] = max(memo[l][r], mult[i] * nums[l] + dp(l + 1, i + 1, nums, mult));
				// pick right
				memo[l][r] = max(memo[l][r], mult[i] * nums[r] + dp(l, i + 1, nums, mult));
        return memo[l][i];
    }
    int maximumScore(vector<int>& nums, vector<int>& mult) {
        int n = nums.size(), m = mult.size(); 
        memset(memo, -1, 1001 * 1001 * sizeof(int)); 
        // dp[l][s] denotes the maximum multiplication when you consider 0..l in nums and  n - 1..r (can be computed) and 0...i
        return dp(0, 0, nums, mult); 
    }
};
```
Patterns: [Two%20Pointers](Two%20Pointers.md)[Dp](Dp.md)