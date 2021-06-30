---
created at: 2021-06-27 
author: akhiln
tags: [problem]
level: 
---

# Maximum number of non-overlapping substrings 
### Problem Statement
Given a string `s` of lowercase letters, you need to find the maximum number of **non-empty** substrings of `s` that meet the following conditions:

1.  The substrings do not overlap, that is for any two substrings `s[i..j]` and `s[k..l]`, either `j < k` or `i > l` is true.
2.  A substring that contains a certain character `c` must also contain all occurrences of `c`.

Find _the maximum number of substrings that meet the above conditions_. If there are multiple solutions with the same number of substrings, _return the one with minimum total length._ It can be shown that there exists a unique solution of minimum total length.

Notice that you can return the substrings in **any** order.

#### Examples

### Solution

#### References
1. [Number of Substrings](Number%20of%20Substrings.md)

[Source](https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/)