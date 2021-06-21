---
Created Time: Jan 02, 2021 3:44 PM
Do Date: Jan 06, 2021
Last edited time: Mar 01, 2021 3:43 PM
Points: 800
Source: https://leetcode.com/problems/is-subsequence/
Status: done
---

# Is Subsequence - LeetCode

Given a string **s** and a string **t**, check if **s** is subsequence of **t**.
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, `"ace"` is a subsequence of `"abcde"` while `"aec"` is not).
**Follow up:**
 If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
**Credits:**
 Special thanks to [@pbrother](https://leetcode.com/pbrother/) for adding this problem and creating all test cases.
**Example 1:**
```
Input: s = "abc", t = "ahbgdc"
Output: true
```
**Example 2:**
```
Input: s = "axc", t = "ahbgdc"
Output: false
```
**Constraints:**
- `0 <= s.length <= 100`
- `0 <= t.length <= 10^4`
- Both strings consists only of lowercase characters.
---
Patterns: [Two%20Pointers](Two%20Pointers.md)[String](String)[patterns/Greedy](patterns/Greedy.md)