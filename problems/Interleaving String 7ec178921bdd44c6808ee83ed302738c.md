# Interleaving String

Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 22, 2020
Last edited time: Mar 01, 2021 8:46 AM
Pattern: https://www.notion.so/Two-Pointers-5f3e09475eb74b08b0880a7c6e1baa74, https://www.notion.so/String-31fee88325084b2db1f8d82cce81360c, https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee
Points: 2000
Pomos (25 mins): 2
Problem Statement: string dp
Status: done

Given strings `s1`, `s2`, and `s3`, find whether `s3` is formed by an **interleaving** of `s1` and `s2`.

An **interleaving** of two strings `s` and `t` is a configuration where they are divided into **non-empty** substrings such that:

- `s = s1 + s2 + ... + sn`
- `t = s1 + t2 + ... + tm`
- `|n - m| <= 1`
- The **interleaving** is `s1 + t1 + s2 + t2 + s3 + t3 + ...` or `t1 + s1 + t2 + s2 + t3 + s3 + ...`

**Note:** `a + b` is the concatenation of strings `a` and `b`.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/09/02/interleave.jpg](https://assets.leetcode.com/uploads/2020/09/02/interleave.jpg)

```
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
```

**Example 2:**

```
Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
```

**Example 3:**

```
Input: s1 = "", s2 = "", s3 = ""
Output: true
```

**Constraints:**

- `0 <= s1.length, s2.length <= 100`
- `0 <= s3.length <= 200`
- `s1`, `s2`, and `s3` consist of lower-case English letters.

---

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false; 
        vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1));
        dp[0][0] = true; 
        for (int i = 0; i <= s1.length(); i++)
        {
            for (int j = 0; j <= s2.length(); j++)
            {
                if (!i and !j) continue; 
                if (!j) dp[i][j] = (s1[i - 1] == s3[i - 1] and dp[i - 1][j]);
                if (!i) dp[i][j] = (s2[j - 1] == s3[j - 1] and dp[i][j - 1]); 
                if (i and j) 
                    dp[i][j] = (s1[i - 1] == s3[i + j - 1] and dp[i - 1][j]) or (s2[j - 1] == s3[i + j - 1] and dp[i][j - 1]);
            }
        }
        return dp[s1.length()][s2.length()]; 
    }
};
```