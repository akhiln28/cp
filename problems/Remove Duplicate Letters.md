---
Created Time: May 11, 2021 9:30 AM
Last edited time: May 23, 2021 8:52 AM
Points: 1600
Source: https://leetcode.com/problems/remove-duplicate-letters/
Status: done
---

# Remove Duplicate Letters

Given a string `s`, remove duplicate letters so that every letter appears once and only once. You must make sure your result is **the smallest in lexicographical order** among all possible results.
**Note:** This question is the same as 1081: [https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)
### Constraints
- `1 <= s.length <= 10^4`
- `s` consists of lowercase English letters.
---
### **Examples**
**Input**
```
Input: s = "bcabc"
Output: "abc"
```
---
**Input**
```
Input: s = "cbacdcbc"
Output: "acdb"
```
---
## Algorithm
```python
```
### Explanation
Let `ret` be the answer. Now iterate the whole string. If 
## Solution
```cpp
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans; 
        vector<int> v(26);
        vector<bool> vis(26, false);
        for (int i = 0; i < s.length(); i++) v[s[i] - 'a']++; 
        for (int i = 0; i < s.length(); i++)
        {
            if (vis[s[i] - 'a'] == true) {
                v[s[i] - 'a']--;
                continue; 
            } 
            if (ans.length() == 0) ans += s[i], v[s[i] - 'a']--, vis[s[i] - 'a'] = true; 
            else if (v[ans.back() - 'a'] > 0 and ans.back() > s[i]) 
            {
                while (ans.length() and v[ans.back() - 'a'] > 0 and ans.back() > s[i])
                    vis[ans.back() - 'a'] = false, ans.pop_back();
                ans.push_back(s[i]), v[s[i] - 'a']--, vis[s[i] - 'a'] = true; 
            }
            else ans += s[i], vis[s[i] - 'a'] = true, v[s[i] - 'a']--; 
            // cout << ans << endl;
        }
        return ans; 
    }
};
```
Patterns: [patterns/Greedy](patterns/Greedy.md)