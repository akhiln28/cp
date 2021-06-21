---
Created Time: Jan 30, 2021 10:31 AM
Do Date: Jan 30, 2021
Last edited time: Mar 01, 2021 8:46 AM
Points: 1600
Source: https://leetcode.com/problems/palindrome-partitioning-iv/
Status: done
---

# Palindrome Partitioning IV - LeetCode

Given a string `s`, return `true` *if it is possible to split the string* `s` *into three **non-empty** palindromic substrings. Otherwise, return* `false`.​​​​​
A string is said to be palindrome if it the same string when reversed.
**Example 1:**
```
Input: s = "abcbdd"
Output: true
Explanation: "abcbdd" = "a" + "bcb" + "dd", and all three substrings are palindromes.
```
**Example 2:**
```
Input: s = "bcbddxy"
Output: false
Explanation: s cannot be split into 3 palindromes.
```
**Constraints:**
- `3 <= s.length <= 2000`
- `s`​​​​​​ consists only of lowercase English letters.
Patterns: [Dp](Dp.md)