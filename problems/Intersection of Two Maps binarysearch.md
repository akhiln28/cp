---
Created Time: Mar 31, 2021 7:59 AM
Last edited time: May 20, 2021 9:56 AM
Points: 1500
Source: https://binarysearch.com/problems/Intersection-of-Two-Maps
Status: waiting
---

# Intersection of Two Maps | binarysearch

You are given two-dimensional lists of integers `a` and `b`, both of which contains `0`s and `1`s. A `1` represents land and `0` represents water, so an island is a group of 1s that are neighboring whose perimeter is surrounded by water.
Return the number of islands that exist in both `a` and `b` at the exact same coordinates.
**Constraints**
- `1 ≤ n * m ≤ 200,000` where `n` and `m` are the number of rows and columns in `a` and `b`
```
a = [
    [1, 0, 1],
    [1, 0, 0],
    [1, 0, 0]
]
```
```
b = [
    [1, 0, 0],
    [1, 0, 1],
    [1, 0, 0]
]
```
### **Output**
### **Explanation**
The top left island is shared in both `a` and `b`.
```
a = [
    [1, 1, 1],
    [1, 1, 1],
    [1, 1, 1]
]
```
```
b = [
    [1, 1, 0],
    [1, 0, 1],
    [1, 0, 0]
]
```
### **Output**
Patterns: 