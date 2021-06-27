---
created at: 2021-06-20 
author: akhiln
tags: [problem, subarray]
level: 
status: pending
---

# Minimum Absolute Difference Queries 
### Problem Statement
Minimum absolute difference of an array `a` is minimum value of `|a[i] - a[j]|` where $0 \le i < j < a.size()$ and $a_i \ne a_j$. 

Given queries such as `queries[i] = [l_i, r_i]`, find the minimum absolute difference of the sub array `nums[l_i to r_i]` for each query?

#### Examples
input: nums = [1, 3, 4, 8] queries = {{0,1}, {1,2}, {2,3}, {0,3}}


### Solution
Given an array what it the best way to find the minimum absolute difference?
- i.e. finding the least two elements of the array
	- what is the preprocessing required for finding the least two elements efficiently
	- how about 

#### References

Patterns: [Range Queries](Range%20Queries.md)