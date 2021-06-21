---
Created Time: Dec 21, 2020 8:58 AM
Do Date: Dec 21, 2020
Last edited time: May 11, 2021 9:00 AM
Points: 1500
Pomos (25 mins): 1
Source: educative.io
Status: ok
Tags: standard
---

# Smallest Window Containing Substring

Given a string and a pattern, find the **smallest substring** in the given string which has **all the characters of the given pattern**.
**Example 1:**
```
Input: String="aabdec", Pattern="abc"
Output: "abdec"
Explanation: The smallest substring having all characters of the pattern is "abdec"
```
**Example 2:**
```
Input: String="abdbca", Pattern="abc"
Output: "bca"
Explanation: The smallest substring having all characters of the pattern is "bca".
```
**Example 3:**
```
Input: String="adcad", Pattern="abc"
Output: ""
Explanation: No substring in the given string has all characters of the pattern.
```
---
We create a hashmap for pattern. 
```cpp
using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>
class MinimumWindowSubstring {
 public:
  static string findSubstring(const string &str, const string &pattern) {
    unordered_map<char, int> ump;
    for (auto ch : pattern) ump[ch]++;
    int end = -1, n = str.length(), matched = 0; 
    pair<int, int> ans{0, n + 1}; 
    for (int start = 0; start < n - pattern.length(); start++)
    {
        while (end + 1 < n && matched < ump.size())
        {
            if (ump.find(str[end + 1]) != ump.end())
            {
                ump[str[end + 1]]--; 
                if (ump[str[end + 1]] == 0) matched++; 
            }
            end++; 
        }
        if (matched == ump.size())
        {
            if (ans.second - ans.first > end - start) ans = make_pair(start, end);
        }
        if (ump.find(str[start]) != ump.end())
        {
            if (ump[str[start]] == 0) matched--;
            ump[str[start]]++; 
        }
    }
    return (ans.second != n + 1) ? str.substr(ans.first, ans.second - ans.first + 1) : "";
  }
};
```
Patterns: [patterns/Greedy](patterns/Greedy.md)[Sliding%20Window](Sliding%20Window.md)