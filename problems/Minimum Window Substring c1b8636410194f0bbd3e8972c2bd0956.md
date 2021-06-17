# Minimum Window Substring

Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 31, 2020
Last edited time: May 23, 2021 8:53 AM
Pattern: https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Sliding-Window-57edd445fc8d49ac98bcd1076bcdd3aa
Points: 2000
Pomos (25 mins): 2
Status: waiting

Given two strings `s` and `t`, return *the minimum window in `s` which will contain all the characters in `t`*. If there is no such window in `s` that covers all characters in `t`, return *the empty string `""`*.

**Note** that If there is such a window, it is guaranteed that there will always be only one unique minimum window in `s`.

**Example 1:**

```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"

```

**Example 2:**

```
Input: s = "a", t = "a"
Output: "a"

```

**Constraints:**

- `1 <= s.length, t.length <= 105`
- `s` and `t` consist of English letters.

**Follow up:**

Could you find an algorithm that runs in O(n) time?

---

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> tmap; 
        for (auto ch : t)
        {
            tmap[ch]++; 
        }
        int end = 0, count = tmap.size(); 
        if (tmap.find(s[0]) != tmap.end()) 
        {
            tmap[s[0]]--; 
            if (tmap[s[0]] == 0) count--; 
        }
        pair<int, int> p{0, s.length() + 1}; // substring as a pair
        for (int start = 0; start <= (int) s.length() - (int) t.length(); start++)
        {
            while (count and end + 1 < s.length())
            {
                end++;
                if (tmap.find(s[end]) != tmap.end()) 
                {
                    tmap[s[end]]--;
                    if (tmap[s[end]] == 0) count--; 
                }
            }
            if (count == 0 and p.second - p.first + 1 > end - start + 1)
            {
                p = {start, end}; 
            }
            if (tmap.find(s[start]) != tmap.end())
            {
                if (tmap[s[start]] == 0) count++; 
                tmap[s[start]]++;
            }
        }
        if (p.second != s.length() + 1) return s.substr(p.first, p.second - p.first + 1); 
        return ""; 
    }
};
```