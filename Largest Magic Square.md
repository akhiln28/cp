---
created at: 2021-06-23 
author: akhiln
tags: [problem, brute-force]
level: 
---

# Largest Magic Square 
### Problem Statement
A magic square is a square matrix whose sum of elements in every row, every column and two diagonals are equal. 

Given an `m x n` matrix, find the side of the largest magic square?

#### Examples

### Solution
x = min(m, n)
$$x^2 + (x - 1)^2.2^2 + (x - 2)^2.3^2 + ... + (1)^2.(x^2)$$

#### References

