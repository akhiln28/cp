---
created at: 2021-06-27 
author: akhiln
tags: [problem, substring]
level: medium
---

# Count number of homogeneous substrings 
### Problem Statement
A string is called homogeneous if all the characters of the string are same. Given a string of length `n` ($n \le 10^5$). Return the number of homogeneous substrings. 

#### Examples
**Example 1:**
```
**Input:** s = "abbcccaa"
**Output:** 13
**Explanation:** The homogenous substrings are listed as below:
"a"   appears 3 times.
"aa"  appears 1 time.
"b"   appears 2 times.
"bb"  appears 1 time.
"c"   appears 3 times.
"cc"  appears 2 times.
"ccc" appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
```

```
**Example 2:**

**Input:** s = "xy"
**Output:** 2
**Explanation:** The homogenous substrings are "x" and "y".

**Example 3:**

**Input:** s = "zzzzz"
**Output:** 15
```
### Solution
Just grouping all the adjacent characters would do the job. 

```cpp
class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9 + 7; 
        long long ans = 0; 
        long long count = 1; 
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] != s[i - 1])
            {
                ans += (count * (count + 1) / 2); 
                count = 1; 
            }
            else count++; 
        }
        ans += (count * (count + 1) / 2); 
        return (ans % mod); 
    }
};
```
#### References
1. [[Number of Substrings]]