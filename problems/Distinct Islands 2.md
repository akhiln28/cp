---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 20, 2020
Last edited time: Mar 01, 2021 8:43 AM
Points: 1800
Source: https://binarysearch.com/problems/Distinct-Islands
Status: done
Tags: connected components
---

# Distinct Islands

Given a two-dimensional integer `matrix` of `1`s and `0`s, return the number of distinct "islands" in the matrix. A `1` represents land and `0` represents water, so an island is a group of 1s that are neighboring whose perimeter is surrounded by water. Two islands are distinct if their shapes are different.
**Constraints**
- `n, m ≤ 100` where `n` and `m` are the number of rows and columns in `matrix`
### **Example 1**
****Input****
```cpp
matrix = [
    [1, 0, 0, 0, 0],
    [0, 0, 1, 1, 0],
    [0, 1, 1, 0, 0],
    [0, 0, 0, 0, 0],
    [1, 1, 0, 1, 1],
    [1, 1, 0, 1, 1]
]
```
****Output****
`3`
### **Explanation**
This matrix has 4 islands, but only 3 distinct islands since the islands at the bottom are identical.
---
Patterns: [Matrix](Matrix.md)[DFS](DFS.md)