---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Jan 16, 2021
Last edited time: Mar 01, 2021 8:48 AM
Points: 2000
Pomos (25 mins): 3
Problem Statement: brute force dp (iterating over previous dp)
Status: done
Tags: difficult, remember
---

# Allocate Mailboxes

Given the array `houses` and an integer `k`. where `houses[i]` is the location of the ith house along a street, your task is to allocate `k` mailboxes in the street.
Return the **minimum** total distance between each house and its nearest mailbox.
The answer is guaranteed to fit in a 32-bit signed integer.
**Example 1:**
![https://assets.leetcode.com/uploads/2020/05/07/sample_11_1816.png](https://assets.leetcode.com/uploads/2020/05/07/sample_11_1816.png)
```
Input: houses = [1,4,8,10,20], k = 3
Output: 5
Explanation: Allocate mailboxes in position 3, 9 and 20.
Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 
```
**Example 2:**
![https://assets.leetcode.com/uploads/2020/05/07/sample_2_1816.png](https://assets.leetcode.com/uploads/2020/05/07/sample_2_1816.png)
```
Input: houses = [2,3,5,12,18], k = 2
Output: 9
Explanation: Allocate mailboxes in position 3 and 14.
Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.
```
**Example 3:**
```
Input: houses = [7,4,6,1], k = 1
Output: 8
```
**Example 4:**
```
Input: houses = [3,6,14,10], k = 4
Output: 0
```
**Constraints:**
- `n == houses.length`
- `1 <= n <= 100`
- `1 <= houses[i] <= 10^4`
- `1 <= k <= n`
- Array `houses` contain unique integers.
---
```cpp
class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size(); 
        sort(houses.begin(), houses.end()); 
				// dp[i][k] denotes the least score for i houses using k mail boxes
        vector<vector<long long>> dp(n + 1, vector<long long> (k + 1, INT_MAX)); 
        
        for (int j = 1; j <= k; j++) dp[0][j] = 0; 
        vector<long long> cum(n + 1); 
        for (int i = 1; i <= n; i++) cum[i] = cum[i - 1] + houses[i - 1]; 
        for (int i = 1; i <= n; i++)
        {
            // for k == 1 case
            dp[i][1] = cum[i] - cum[i/2] - cum[(i + 1)/2]; 
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 2; j <= k; j++)
            {
                for (int l = i; l >= j; l--)
                {
                    // distribute 1 mail box for houses from l to i
                    long long temp = dp[l - 1][j - 1] + cum[i] - cum[(i + l - 1)/2] - cum[(i + l)/2] + cum[l - 1]; 
                    dp[i][j] = min(dp[i][j], temp); 
                }
                if (j >= i) dp[i][j] = 0; 
            }
        }
        return dp[n][k]; 
    }
};
```
Patterns: [Array](Array.md)[Dp](Dp.md)