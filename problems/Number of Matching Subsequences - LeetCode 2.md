---
Created Time: Dec 18, 2020 8:13 PM
Do Date: Dec 18, 2020
Last edited time: May 11, 2021 8:58 AM
Points: 1500
Source: https://leetcode.com/problems/number-of-matching-subsequences/
Status: done
Tags: subsequences
---

# Number of Matching Subsequences - LeetCode

Given string `S` and a dictionary of words `words`, find the number of `words[i]` that is a subsequence of `S`.
```
Example :Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
```
**Note:**
- All words in `words` and `S` will only consists of lowercase letters.
- The length of `S` will be in the range of `[1, 50000]`.
- The length of `words` will be in the range of `[1, 5000]`.
- The length of `words[i]` will be in the range of `[1, 50]`.
---
Store the indices of a character in a map. 
```cpp
class Solution {
public:
    bool find(map<int, vector<int>> &mp, string &w)
    {
        int prev = -1; 
        for (int i = 0; i < w.length(); i++)
        {
            vector<int> &v = mp[w[i]]; 
            auto loc = upper_bound(v.begin(), v.end(), prev); 
            if (loc == v.end()) return false; 
            prev = v[loc - v.begin()]; 
        }
        return true; 
    }
    int numMatchingSubseq(string S, vector<string>& words) {
        map<int, vector<int>> mp; 
        for (int i = 0; i < S.length(); i++)
        {
            mp[S[i]].push_back(i); 
        }
        int ans = 0; 
        for (auto &w : words)
        {
            ans += find(mp, w); 
        }
        return ans; 
    }
};
```
Patterns: [Matrix](Matrix.md)[Hashing](Hashing.md)