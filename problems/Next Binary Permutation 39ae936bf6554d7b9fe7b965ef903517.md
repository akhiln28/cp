# Next Binary Permutation

Created Time: Dec 10, 2020 7:54 PM
Do Date: Feb 02, 2021
Last edited time: May 11, 2021 9:12 AM
Pattern: https://www.notion.so/Custom-datastructures-6c89204250cd4dbb88ef0addf2ca20a3, https://www.notion.so/Bits-e38c7329b88e4b65ac64bfc4a9ffc7ed
Points: 1600
Pomos (25 mins): 2
Problem Statement: Given an integer n, find the smallest integer which is greater than n and contains same number of set bits?
Source: https://binarysearch.com/problems/Next-Binary-Permutation
Status: ok

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