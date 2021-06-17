# Word Break - LeetCode

Created Time: Dec 31, 2020 7:38 PM
Do Date: Jan 07, 2021
Last edited time: May 11, 2021 9:01 AM
Pattern: https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee, https://www.notion.so/Number-Theory-02e26369bab8475881b8a6a9d7b33ca9, https://www.notion.so/Linear-DP-40f64e6224704d17972aa352dc735edb
Points: 1500
Source: https://leetcode.com/problems/word-break/
Status: done
Tags: O(n^2)

Given a **non-empty** string *s* and a dictionary *wordDict* containing a list of **non-empty** words, determine if *s* can be segmented into a space-separated sequence of one or more dictionary words.

**Note:**

- The same word in the dictionary may be reused multiple times in the segmentation.
- You may assume the dictionary does not contain duplicate words.

**Example 1:**

```
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
```

**Example 2:**

```
Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
```

**Example 3:**

```
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
```

---

$dp[i] \rightarrow$ denotes whether $0...i$ can be expressed as using the given word dictionary. 

```python
class Solution {
public:
    unordered_set<string> words;
    bool wordBreak(string s, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); i++)
            words.insert(wordDict[i]); 
        vector<bool> dp(s.length(), false); 
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (words.count(s.substr(j, i - j + 1)) and (j == 0 or dp[j - 1])) dp[i] = true;
            }
        }
        return dp[s.length() - 1]; 
    }
};
```