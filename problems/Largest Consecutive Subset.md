---
Created Time: Feb 18, 2021 9:00 AM
Do Date: Feb 19, 2021
Last edited time: May 11, 2021 9:04 AM
Points: 1500
Status: ok
Tags: own
---

# Largest Consecutive Subset

Given a array of integers. Find the largest subset (where all elements in the subset are consecutive) in the array?
---
Store all the elements in an hash map. Now for each element traverse to the left and right as much as possible (and mark the elements visited).
Complexity: O(n)
Patterns: [Array](Array.md)[patterns/Greedy](patterns/Greedy.md)[Traversal](Traversal.md)