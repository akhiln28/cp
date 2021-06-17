# Decode Ways - LeetCode

Created Time: Dec 19, 2020 3:34 PM
Do Date: Dec 19, 2020
Last edited time: May 11, 2021 9:01 AM
Pattern: https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee, https://www.notion.so/Number-Theory-02e26369bab8475881b8a6a9d7b33ca9, https://www.notion.so/Linear-DP-40f64e6224704d17972aa352dc735edb
Points: 1500
Pomos (25 mins): 1
Relates: Restore%20The%20Array%20-%20LeetCode%2015424e4675cc485da0ae7080f42dc76b.md
Source: https://leetcode.com/problems/decode-ways/
Status: done

A message containing letters from `A-Z` is being encoded to numbers using the following mapping:

```
'A' -> 1
'B' -> 2
...
'Z' -> 26
```

Given a **non-empty** string containing only digits, determine the total number of ways to decode it.

The answer is guaranteed to fit in a **32-bit** integer.

**Example 1:**

```
Input: s = "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
```

**Example 2:**

```
Input: s = "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
```

**Example 3:**

```
Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with '0'. We cannot ignore a zero when we face it while decoding. So, each '0' should be part of "10" --> 'J' or "20" --> 'T'.
```

**Example 4:**

```
Input: s = "1"
Output: 1
```

**Constraints:**

- `1 <= s.length <= 100`
- `s` contains only digits and may contain leading zero(s).

---

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if (!s.length()) return 0;
        vector<int> dp(s.length());
        dp[0] = 1;
        if (s[0] == '0') return 0;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == '0') 
            {
                if (s[i - 1] == '1' || s[i - 1] == '2') dp[i] = (i >= 2 ? dp[i - 2] : 1);
                else return 0;
            }
            else if ((s[i] - '0') + (s[i - 1] - '0') * 10 <= 26 && s[i - 1] != '0') dp[i] = dp[i - 1] + (i >= 2 ? dp[i - 2] : 1);
            else dp[i] = dp[i - 1];
        }
        return dp[s.length() - 1];
    }
};
```