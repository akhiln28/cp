---
Created Time: Mar 21, 2021 8:56 AM
Do Date: Mar 22, 2021
Last edited time: Mar 28, 2021 10:50 PM
Source: https://binarysearch.com/problems/Number-of-Concatenations-to-Create-Subsequence
Status: done
---

# Number of Concatenations to Create Subsequence | binarysearch

You are given two lowercase alphabet strings `s` and `t`. Return the minimum number of times we must concatenate `s` such that `t` is a subsequence of `s`. For example, if we concatenate `"abc"` three times, we'd get `"abcabcabc"`. If it's not possible, return `-1`.
**Constraints**
- `1 ≤ n ≤ 100,000` where `n` is the length of `s`
- `1 ≤ m ≤ 100,000` where `m` is the length of `t`
### **Output**
### **Explanation**
If we concatenate `a = "dab"` three times, we can get `"dabdabdab"`. And `"abbd"` is a subsequence of `"dabdabdab"`.
### **Output**
### **Explanation**
It's impossible to make `t` a subsequence of `s`.
Patterns: 