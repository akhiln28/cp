---
created at: 2021-06-22 
author: akhiln
tags: [problem, number_theory, atcoder]
level: 
---

# Base -2 Number 
### Problem Statement
Given an number `N` $\in 10^{-9}, 10^9$. Return the base -2 representation of `N`.

#### Examples
Input: 10
Output:
2 + 8
4 - 2 + 16 - 8 = 11110
2 + 4 = 4 - 2 + 4 = 8 - 2 = 16 - 8 - 2
{1, 2, 4} -> {2, -1, 2, 4} -> {-1, 3, 4} -> {-1, 4, -3, 4} -> {-1, -3, 5} -> {-1, -3, -5, 6}

### Solution
First find the base 2 representation of `N`. For all the odd powers of 2 i.e. $2^n$ and make them $2^{n + 1} - 2^n$. We do this until we can't find the odd powers of 2. 

I am thinking if there is any better way to do it. 

#### References
[Number Theory](Number%20Theory.md)
[[Base of Negative Integer]]