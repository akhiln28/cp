---
Created Time: Feb 16, 2021 8:37 AM
Last edited time: May 23, 2021 8:53 AM
Points: 1700
Pomos (25 mins): 1
Relates: Find%20the%20Most%20Competitive%20Subsequence%20-%20Leetcode%2061f1994174a84126854d541b91b58202.md
Source: https://leetcode.com/problems/remove-k-digits/
Status: waiting
Tags: like, new
---

# Remove K Digits - LeetCode

Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
**Note:**
- The length of num is less than 10002 and will be ≥ k
- The given  num does not contain any leading zero
**Example 1:**
```
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
```
**Example 2:**
```
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
```
**Example 3:**
```
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
```
---
This is like choosing n - k digits to form the least number.
Patterns: [patterns/Greedy](patterns/Greedy.md)[Number%20Theory](Number%20Theory.md)[Stack](Stack.md)