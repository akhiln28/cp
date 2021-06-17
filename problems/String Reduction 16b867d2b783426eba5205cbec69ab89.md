# String Reduction

Created Time: Dec 14, 2020 9:48 AM
Do Date: Dec 14, 2020
Last edited time: Feb 18, 2021 7:45 AM
Points: 1600
Pomos (25 mins): 1
Problem Statement: Given a string containing only characters a, b and c. You can replace (ab|ba → c), (bc|cb → a) and (ca|ac → b). Find the length of the shortest string using such operations?
Source: coderbyte.com
Status: waiting
Tags: doxel ai

Given a string containing only characters a, b and c. You can replace (ab|ba → c), (bc|cb → a) and (ca|ac → b). Find the length of the shortest string using such operations?

---

```cpp
countA
countB
countC

if ((countA == 0 + countB == 0 + countC == 0) == 2) return str.length()
if (all three are even or all three are odd) return 2
else return 1
```