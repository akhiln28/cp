---
Created Time: Dec 16, 2020 12:39 PM
Do Date: Dec 18, 2020
Last edited time: Feb 22, 2021 9:23 PM
Points: 1500
Related To: Coin%20Change%20%5BMinimum%20#coins%5D%20752ae3763fb44a87b4cf27d7ec89e054.md
Source: https://www.geeksforgeeks.org/coin-change-dp-7/
Status: ok
Tags: de shaw
---

# Coin Change | Number of ways

Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
---
```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1));
        dp[0][0] = 1; 
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1; 
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j) dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][amount]; 
    }
};
```
$dp[i][n] = \sum_k dp[i - 1][n - k \times c_i]$
This method is working in leetcode, (among bottom 5%) [https://leetcode.com/problems/coin-change-2/](https://leetcode.com/problems/coin-change-2/)
```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        vector<vector<int>> dp(n + 1, vector<int> (amount + 1));
        dp[0][0] = 1; 
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = 1; 
            for (int j = 1; j <= amount; j++)
            {
                int k = 0; 
                while (j - k * coins[i - 1] >= 0) dp[i][j] += dp[i - 1][j - k * coins[i - 1]], k++; 
            }
        }
        return dp[n][amount]; 
    }
};
```
- [ ]  I don't understand the below code.
```cpp
class Solution {
public:
    int change(int amnt, vector<int>& arr) {
        int n = arr.size();
        int table[amnt+1];
        memset(table,0,sizeof(table));
        table[0] = 1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i];j<=amnt;j++)
            {
                table[j] += table[j-arr[i]];
            }
        }
        return table[amnt];
    }
};
```
Patterns: [Array](Array.md)