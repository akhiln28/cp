---
Created Time: Dec 01, 2020 11:55 PM
Last edited time: Mar 01, 2021 8:46 AM
Points: 1500
Problem Statement: Given a string, return the longest palindromic substring?
Source: https://leetcode.com/problems/longest-palindromic-substring/
Status: done
---

# Longest Palindromic Substring

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool> (s.length(), false));
        string ans; 
        for (int i = s.length() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.length(); j++)
            {
                if (j == i) dp[i][j] = true;
                else if (j == i + 1) dp[i][j] = s[i] == s[j];
                else 
                {
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                }
                if (dp[i][j] && ans.length() < j - i + 1)
                        ans = s.substr(i, j - i + 1);
            }
        }
        return ans;
    }
};
```
Patterns: [Dp](Dp.md)