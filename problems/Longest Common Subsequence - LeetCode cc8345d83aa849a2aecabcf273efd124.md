# Longest Common Subsequence - LeetCode

Created Time: Dec 18, 2020 7:01 PM
Do Date: Dec 18, 2020
Last edited time: Mar 01, 2021 8:46 AM
Pattern: https://www.notion.so/Two-Pointers-5f3e09475eb74b08b0880a7c6e1baa74, https://www.notion.so/String-31fee88325084b2db1f8d82cce81360c, https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee
Points: 1200
Relates: LCS%20(Longest%20Common%20Subsequence)%20of%20three%20strings%20%20cbd7da601f8943c4baaa4e12e0f6df28.md
Source: https://leetcode.com/problems/longest-common-subsequence/
Status: done

Given two strings `text1` and `text2`, return the length of their longest common subsequence.

A *subsequence* of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A *common subsequence* of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.

**Example 1:**

```
Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

```

**Example 2:**

```
Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

```

**Example 3:**

```
Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.

```

**Constraints:**

- `1 <= text1.length <= 1000`
- `1 <= text2.length <= 1000`
- The input strings consist of lowercase English characters only.

---

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length(); 
        vector<vector<int>> dp(n + 1, vector<int> (m + 1)); 
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1]; 
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
            }
        }
        return dp[n][m]; 
    }
};
```