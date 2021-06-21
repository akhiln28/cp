---
Created Time: Feb 17, 2021 8:06 AM
Do Date: Feb 17, 2021
Last edited time: Mar 31, 2021 8:59 AM
Points: 1500
Source: https://binarysearch.com/contest/Weekly-Contest-46-Wgbjnsf4qw?questionsetIndex=1
Status: done
---

# Cut Ribbons of Same Length

You are given a list of positive integers `ribbons` and an integer `k`. Given that you can cut the ribbons as many times as you want, return the largest `r` such that you can have `k` ribbons of length `r`. If there is no solution, return `-1`.
**Constraints**
- `1 ≤ n ≤ 100,000` where `n` is the length of `ribbons`
- `1 ≤ k`
### **Explanation**
We can cut the ribbon of size `9` into `3` pieces of size `3` each. Then cut the ribbon of size `4` into size `1` and `3`. Then we can achieve `5` ribbons of size `3`.
### **Explanation**
1
Patterns: [Array](Array.md)[patterns/Greedy](patterns/Greedy.md)[Binary%20Search](Binary%20Search.md)