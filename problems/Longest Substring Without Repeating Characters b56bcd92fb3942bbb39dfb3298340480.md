# Longest Substring Without Repeating Characters

Created Time: Dec 01, 2020 11:55 PM
Last edited time: May 11, 2021 9:00 AM
Pattern: https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Sliding-Window-57edd445fc8d49ac98bcd1076bcdd3aa
Points: 1500
Status: done
Tags: two pointers

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