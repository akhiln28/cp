# Largest Consecutive Subset

Created Time: Feb 18, 2021 9:00 AM
Do Date: Feb 19, 2021
Last edited time: May 11, 2021 9:04 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Traversal-dca46f72f93e4db583e0e72ba3dc6fdb
Points: 1500
Status: ok
Tags: own

Given a array of integers. Find the largest subset (where all elements in the subset are consecutive) in the array?

---

Store all the elements in an hash map. Now for each element traverse to the left and right as much as possible (and mark the elements visited).

Complexity: O(n)