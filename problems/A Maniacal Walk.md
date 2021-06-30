---
Created Time: Dec 22, 2020 10:28 PM
Do Date: Dec 22, 2020
Last edited time: May 11, 2021 9:01 AM
Points: 1800
Pomos (25 mins): 1
Source: https://binarysearch.com/problems/A-Maniacal-Walk
Status: ok
Topic: [number theory]
Tags: [count, dp]
---

# A Maniacal Walk

A person is placed on a list of length `length`, at index `0`, and on each step, they can move right one index or left one index (without going out of bounds), or stay on that index.
Given that the person can take exactly `n` steps, how many unique walks can the person take and reach back to index `0`? Mod the result by `10 ** 9 + 7`.
**Constraints**
- `length ≤ 1000`
- `n ≤ 500`
### **Example 1**
****Input****
`length = 5`
`n = 3`
****Output****
`4`
### **Explanation**
The four actions are:
- stay, and stay at index `0`.
- right, stay, left.
- right, left, stay.
- stay, right, left.
---
We move from initial state dp(dp[0] = 1) → temp in each iteration. 
```python
int solve(int length, int n) {
    vector<long long> dp(length); 
    dp[0] = 1; 
    const int mod = 1e9 + 7; 
    for (int i = 0; i < n; i++)
    {
        vector<long long> temp(length); 
        for (int j = 0; j < dp.size(); j++)
        {
            temp[j] = ((j ? dp[j - 1] : 0) + dp[j] + (j + 1 < dp.size() ? dp[j + 1] : 0)) % mod; 
        }
        dp = temp; 
    }
    return dp[0]; 
}
```
Patterns: [Number Theory](Number%20Theory.md)