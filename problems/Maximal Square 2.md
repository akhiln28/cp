---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 20, 2020
Last edited time: Mar 01, 2021 8:47 AM
Points: 1600
Pomos (25 mins): 1
Problem Statement: largest square containing all ones
Source: https://leetcode.com/problems/maximal-square/
Status: done
Tags: largest square, standard
---

# Maximal Square

Given an `m x n` binary `matrix` filled with `0`'s and `1`'s, *find the largest square containing only* `1`'s *and return its area*.
**Example 1:**
![https://assets.leetcode.com/uploads/2020/11/26/max1grid.jpg](https://assets.leetcode.com/uploads/2020/11/26/max1grid.jpg)
```
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
```
**Example 2:**
![https://assets.leetcode.com/uploads/2020/11/26/max2grid.jpg](https://assets.leetcode.com/uploads/2020/11/26/max2grid.jpg)
```
Input: matrix = [["0","1"],["1","0"]]
Output: 1
```
**Example 3:**
```
Input: matrix = [["0"]]
Output: 0
```
**Constraints:**
- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 300`
- `matrix[i][j]` is `'0'` or `'1'`.
---
Patterns: [Matrix](Matrix.md)[Dp](Dp.md)