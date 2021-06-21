---
Created Time: Jan 27, 2021 11:12 PM
Do Date: Jan 28, 2021
Last edited time: May 11, 2021 9:04 AM
Points: 1500
Source: https://codeforces.com/contest/1478/problem/C#
Status: done
---

# C. Nezzar and Symmetric Array

![C%20Nezzar%20and%20Symmetric%20Array%20c424ec5468f94287be74e406c9976646/Untitled.png](C%20Nezzar%20and%20Symmetric%20Array%20c424ec5468f94287be74e406c9976646/Untitled.png)
---
Suppose $a_1, ..., a_n$ are the required positive distint integers. We have, 
$d_i = (i - 1)a_i - s_{i - 1} + s_n - s_i - (n - i)a_i + n.a_i + s_n$
$= 2.s_n + 2.(i - 1).a_i - 2.s_{i - 1}$
$d_i = 2 \times (s_n + (i - 1)\times a_i - s_{i - 1})$
$d_i = d_{i - 1} + 2 (i - 1) (a_i - a_{i - 1})$
Patterns: [Array](Array.md)[patterns/Greedy](patterns/Greedy.md)[Traversal](Traversal.md)