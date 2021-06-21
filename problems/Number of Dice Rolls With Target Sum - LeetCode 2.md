---
Created Time: Feb 28, 2021 7:26 AM
Do Date: Feb 28, 2021
Last edited time: Feb 28, 2021 7:47 AM
Points: 1500
Pomos (25 mins): 1
Relates: Closest%20Dessert%20Cost%20-%20LeetCode%204430e31229504edcab9f6a9045854b3d.md
Source: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
Status: done
---

# Number of Dice Rolls With Target Sum - LeetCode

You have `d` dice, and each die has `f` faces numbered `1, 2, ..., f`.
Return the number of possible ways (out of `fd` total ways) **modulo `10^9 + 7`** to roll the dice so the sum of the face up numbers equals `target`.
**Example 1:**
```
Input: d = 1, f = 6, target = 3
Output: 1
Explanation: 
You throw one die with 6 faces.  There is only one way to get a sum of 3.
```
**Example 2:**
```
Input: d = 2, f = 6, target = 7
Output: 6
Explanation: 
You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
```
**Example 3:**
```
Input: d = 2, f = 5, target = 10
Output: 1
Explanation: 
You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.
```
**Example 4:**
```
Input: d = 1, f = 2, target = 3
Output: 0
Explanation: 
You throw one die with 2 faces.  There is no way to get a sum of 3.
```
**Example 5:**
```
Input: d = 30, f = 30, target = 500
Output: 222616187
Explanation: 
The answer must be returned modulo 10^9 + 7.
```
**Constraints:**
- `1 <= d, f <= 30`
- `1 <= target <= 1000`
---
The required answer is equal to the number of solutions of the equation, $x_1 + x_2...+ x_d = target, x_i \in [1, f]$
Total number of ways to throw the dice is $f^d$. 
$$F(d, target) = \sum F(d - 1, target - i)$$
Complexity will be $d \times f \times target$
```cpp
class Solution {
public:
    long long dp[31][1001]; 
    const int mod = 1e9 + 7; 
    int func(int d, int f, int target)
    {
        if (d == 0)
        {
            return (target == 0); 
        }
        if (target == 0) return 0; 
        if (dp[d][target] != -1) return dp[d][target]; 
        
        dp[d][target] = 0; 
        for (int i = 1; i <= f; i++)
        {
            if (target >= i) dp[d][target] = (dp[d][target] + func(d - 1, f, target - i)) % mod; 
        }
        return dp[d][target]; 
    }
    int numRollsToTarget(int d, int f, int target) {
        memset(dp, -1, sizeof(dp));
        return func(d, f, target); 
    }
};
```
Patterns: [Dp](Dp.md)