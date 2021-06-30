---
created at: 2021-06-29 
author: akhiln
tags: [problem, medium-hard]
status: done
---

# Number of substrings containing all three characters 
### Problem Statement
  
Given a string `s` consisting only of characters _a_, _b_ and _c_.

Return the number of substrings containing **at least** one occurrence of all these characters `a`, `b` and `c`. 

#### Examples
Input: `abcabc`
Output: 10
Explanation:
	`abc`, `abca`, `abcab`, `abcabc`, `abc`, `cabc`, `bcabc`, `abcabc`, `cab`, `bca`
	
### Solution
Naive solution would be to iterate over all the pairs $(i, j)$ and check if it satisfies. We can use cumulative array for that. on $O(n^2)$.

There is definitely a scope for optimization. Because, if we know that $(i, j)$ is a valid substring and all the super strings of $(i, j)$ will also be valid. 

One problem is counting the super strings multiple times.

If we know for each $i \in (0, n - 1)$, the least $j > i$ such that $(i, j)$ is valid, then we know the number of valid strings starting at $i$ is $n - j$.

We can use [[Sliding Window]] to compute such $j$ for each $i$ as $j$ is [[Monotonic]].

Below is not working yet. 
```cpp
class Solution {
public:
    int score(vector<int> &alpha) {
        return (alpha[0] > 0) + (alpha[1] > 0) + (alpha[2] > 0);
    }
    int numberOfSubstrings(string s) {
        int end = 0, n = s.length(); 
        vector<int> alpha(3);
        alpha[s[0] - 'a']++;
        vector<int> f(n, -1);
        for (int start = 0; start < n; start++) {
            while (end + 1 < n and score(alpha) < 3) {
                alpha[s[++end] - 'a']++;
            }
            if (score(alpha) == 3) {
                f[start] = end;
            }
            alpha[s[start] - 'a']--;
        }
        int ans = 0; 
        for (int i = 0; i < n; i++) {
            if (f[i] == -1) break;
            ans += n - f[i];
        }
        return ans; 
    }
};
```
In the above code I made a mistake of not thinking about the operator precedence. I made a mistake as shown below
```cpp
return (alpha[0] > 0 + alpha[1] > 0 + alpha[2] > 0);
```


#### References

1. [source](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)
2. [[Number of Substrings]]