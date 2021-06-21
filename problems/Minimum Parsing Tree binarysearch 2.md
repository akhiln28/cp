---
Created Time: Apr 15, 2021 7:43 AM
Last edited time: May 23, 2021 8:53 AM
Source: https://binarysearch.com/problems/Minimum-Parsing-Tree
Status: waiting
---

# Minimum Parsing Tree | binarysearch

You are given a list of unique and sorted integers `nums` representing breakpoints in a string and want to create a tree out of these rules:
- Nodes have a value `(a, b)` where `a` and `b` are breakpoints. This means the node spans from indices `[a, b)` in the string.
- The root node spans over the all breakpoints (i.e. the whole string).
- The spans of a node's left and right child are ordered, contiguous, and comprise the parent node's span.
- Leaf nodes' index of `a` in `breakpoints` is `1` before the index of `b` in `breakpoints`.
The cost of a tree is defined as the sum of `b - a` for every node in the tree. Return the minimum cost of a feasible tree.
**Constraints**
- `n ≤ 1,000` where `n` is the length of `nums`
Patterns: 