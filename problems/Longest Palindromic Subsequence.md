---
Created Time: Dec 19, 2020 10:34 PM
Do Date: Dec 19, 2020
Last edited time: Mar 01, 2021 8:47 AM
Points: 1500
Source: https://leetcode.com/problems/longest-palindromic-subsequence/
Status: done
Tags: O(n^2)
---

# Longest Palindromic Subsequence
## Problem Statement
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

**Example 1:**
Input:
```
"bbbab"
```
Output:  One possible longest palindromic subsequence is "bbbb".

**Example 2:**
Input:
```
"cbbd"
```
Output:  One possible longest palindromic Subsequence is "bb".

**Constraints:**
- `1 <= s.length <= 1000`
- `s` consists only of lowercase English letters.

## Solution
$dp[i][j] = max(dp[i + 1][j - 1] + 2 \times (s[i] == s[j]), dp[i + 1][j], dp[i][j - 1])$
```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length(); 
        vector<vector<int>> dp(n, vector<int> (n)); 
        int ans = 0; 
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j) dp[i][j] = 1; 
                else dp[i][j] = max({dp[i + 1][j - 1] + 2 * (s[i] == s[j]), dp[i + 1][j], dp[i][j - 1]});        
                ans = max(ans, dp[i][j]); 
            }
        }
        return ans; 
    }
};
```
Patterns: [Interval DP](Interval%20DP.md), [Intervals](Intervals.md), [Palindrome](Palindrome.md)