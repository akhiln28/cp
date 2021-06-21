---
Created Time: Feb 14, 2021 4:52 PM
Last edited time: Feb 24, 2021 9:11 AM
Points: 1600
Pomos (25 mins): 1
Source: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
Status: waiting
Tags: like
---

# Reverse Substrings Between Each Pair of Parentheses - Leetcode

You are given a string `s` that consists of lower case English letters and brackets.
Reverse the strings in each pair of matching parentheses, starting from the innermost one.
Your result should **not** contain any brackets.
**Example 1:**
```
Input: s = "(abcd)"
Output: "dcba"
```
**Example 2:**
```
Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
```
**Example 3:**
```
Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
```
**Example 4:**
```
Input: s = "a(bcdefghijkl(mno)p)q"
Output: "apmnolkjihgfedcbq"
```
**Constraints:**
- `0 <= s.length <= 2000`
- `s` only contains lower case English characters and parentheses.
- It's guaranteed that all parentheses are balanced.
---
```cpp
reverseInParenthesis(s, i, j)
	reverse(i, j)
	first >= i and last <= j
	reverseInParenthesis(first + 1, last - 1)
```
Patterns: [Stack](Stack.md)