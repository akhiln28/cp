---
Created Time: Dec 10, 2020 7:54 PM
Do Date: Feb 02, 2021
Last edited time: May 11, 2021 9:12 AM
Points: 1600
Pomos (25 mins): 2
Problem Statement: Given an integer n, find the smallest integer which is greater than n and contains same number of set bits?
Source: https://binarysearch.com/problems/Next-Binary-Permutation
Status: ok
---

# Next Binary Permutation

Given an integer n, find the smallest integer which is greater than n and contains same number of set bits?
---
We will have three cases
101101 → 101110 (01 → 10)
111100 → 1000111 (no 01 pattern)
11111 → 101111 (no zeroes)
10111111 → 11011111
We can do something like below, Identify first zero after one (from right to left). 
1 0 1 0 0 1 1 0 0 
            ^ this one → flip this
1 0 1 0 1 1 1 0 0
1 0 1 0 1 0 0 0 0
1 0 1 0 1 0 0 1 1
---
Patterns: [Custom%20datastructures](Custom%20datastructures.md)[Bits](Bits.md)