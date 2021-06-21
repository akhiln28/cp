---
Created Time: Jan 24, 2021 7:10 PM
Do Date: Jan 29, 2021
Last edited time: May 11, 2021 9:04 AM
Points: 1500
Related To: Next%20Permutation%20f72d658cad3e4c02bcd5e732650ec0c7.md
Source: https://www.geeksforgeeks.org/lexicographically-previous-permutation-in-c/
Status: done
---

# Previous Permutation

Given a word, find lexicographically smaller permutation of it. For example, lexicographically smaller permutation of “4321” is “4312” and next smaller permutation of “4312” is “4231”. If the string is sorted in ascending order, the next lexicographically smaller permutation doesn’t exist.
---
Traverse from the right end of the string. until you find i such that $a_i > a_{i + 1}$. Note that numbers $a_{i + 1}...a_n$ are all sorted in increasing order. Find the largest number in this set which is less than $a_i$ and swap them. And then reverse the new $a_{i + 1}...a_n$.
Patterns: [Array](Array.md)[patterns/Greedy](patterns/Greedy.md)[Traversal](Traversal.md)