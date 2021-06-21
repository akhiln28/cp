---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 16, 2020
Last edited time: Mar 01, 2021 8:46 AM
Points: 1500
Problem Statement: Given a set of coins. (each can be used unlimited number of times). Find the minimumn number of coins need to get total of exactly amount?
Relates: Coin%20Change%20Number%20of%20ways%20063bc03f10324e5fba2f4c9e1144c2bc.md
Source: https://leetcode.com/problems/coin-change/
Status: done
---

# Coin Change [Minimum #coins]

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return `-1`.
You may assume that you have an infinite number of each kind of coin.
**Example 1:**
```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```
**Example 2:**
```
Input: coins = [2], amount = 3
Output: -1
```
**Example 3:**
```
Input: coins = [1], amount = 0
Output: 0
```
**Example 4:**
```
Input: coins = [1], amount = 1
Output: 1
```
**Example 5:**
```
Input: coins = [1], amount = 2
Output: 2
```
**Constraints:**
- `1 <= coins.length <= 12`
- `1 <= coins[i] <= 231 - 1`
- `0 <= amount <= 104`
---
$dp[i] = min_i(dp[i - c_i])$
```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount + 1, INT_MAX);
        sort(coins.begin(), coins.end());
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                else break; 
            }
        }
        return (dp[amount] < INT_MAX ? dp[amount] : -1);
    }
};
```
Patterns: [Dp](Dp.md)