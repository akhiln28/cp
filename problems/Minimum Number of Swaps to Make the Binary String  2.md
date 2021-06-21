---
Created Time: May 16, 2021 9:23 AM
Day Completed: https://www.notion.so/17-May-21-Monday-e59b42d68145406195040c6d206d286b
Last edited time: May 16, 2021 9:30 AM
Points: 1500
Pomos (25 mins): 2
Source: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
Status: done
---

# Minimum Number of Swaps to Make the Binary String Alternating - LeetCode

Given a binary string `s`, return *the **minimum** number of character swaps to make it **alternating**, or* `-1` *if it is impossible.*
Any two characters may be swapped, even if they are **not adjacent**.
### Constraints
- `1 <= s.length <= 1000`
- `s[i]` is either `'0'` or `'1'`
### **Examples**
```
Input: s = "111000"
Output: 1
Explanation: Swap positions 1 and 4: "111000" -> "101010"
The string is now alternating.
```
```
Input: s = "010"
Output: 0
Explanation: The string is already alternating, no swaps are needed.
```
---
```
Input: s = "1110"
Output: -1
```
---
## Algorithm
```python
```
### Explanation
If the difference between the number of '1' and '0' is greater than 1, then there is no way to convert it into alternating. 
There are atmost two possibilities for the alternating string. We can compare the possibilities with the given string. The half of the number of mismatches is our answer
## Solution
```cpp
class Solution {
public:
    int minSwaps(string s) {
        // 11110000 -> 10110010 -> 10101010
        int n = s.length();
        int ones = 0, zeroes = 0;
        string str1, str2; 
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1') ones++;
            else if (s[i] == '0') zeroes++; 
        }
        if (abs(ones - zeroes) > 1) return -1; 
        if (ones < zeroes)
        {
            for (int i = 0; i < n; i++)
            {
                if (i & 1) str1 += '1';
                else str1 += '0';
            }
        }
        else if (ones > zeroes)
        {
            for (int i = 0; i < n; i++)
            {
                if (!(i & 1)) str1 += '1';
                else str1 += '0';
            }
        }
        else 
        {
            for (int i = 0; i < n; i++)
            {
                if (i & 1) str1 += '1';
                else str1 += '0';
            }
            for (int i = 0; i < n; i++)
            {
                if (!(i & 1)) str2 += '1';
                else str2 += '0';
            }
        }
        int diff1 = 0; 
        for (int i = 0; i < n; i++)
        {
            diff1 += str1[i] != s[i]; 
        }
        if (str2.size() == 0) return diff1/2; 
        int diff2 = 0; 
        for (int i = 0; i < n; i++)
        {
            diff2 += str2[i] != s[i]; 
        }
        return min(diff1, diff2)/2;
    }
};
```
Patterns: [String](String)[Construction](Construction.md)