---
Created Time: Dec 01, 2020 11:55 PM
Last edited time: May 11, 2021 9:00 AM
Points: 1500
Status: done
Tags: two pointers
---

# Longest Substring Without Repeating Characters

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int end = 0, n = s.length();
        set<int> inside;
        int ans = 0;
        inside.insert(s[0]);
        for (int start = 0; start < n; start++)
        {
            while (end + 1 < n and inside.count(s[end + 1]) == 0)
            {
                end++;
                inside.insert(s[end]);
            }
            ans = max(ans, end - start + 1);
            inside.erase(s[start]);
        }
        return ans;
    }
};
```
Patterns: [patterns/Greedy](patterns/Greedy.md)[[Sliding Window]]