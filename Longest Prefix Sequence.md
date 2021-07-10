---
created at: 2021-07-07 
author: akhiln
tags: [problem]
level: 
---

# Longest Prefix Sequence 
## Problem Statement
Given list of `n` words. Find the length of the longest chain you can construct such that each word in the chain is a prefix of the next word.

$n \le 10^5$
$m \le 10^5$ -> `m` length of the longest string

### Examples
Input: words = ["abc", "ab", "x", "xy", "abcd"]
Output: 3

## Approach
Brute force approach:

for (i, j) in range(n):
	check if there is a directed connection between word[i] and word[j]

After forming all the connections, find the length of the longest path in the DAG using DP.

Complexity will be $O(n^2)$ which will fail. 

The next best approach I can think of is to use **trie** data structure for storing all the words. That way we can form all the connections in $O(n)$. Because we need the prefix relation between all the words. 

- for word in words:
	- adding to trie:
		- while adding add connections to all the words you have visited

- [ ] need to learn how to implement trie in python

## Solution

### References

