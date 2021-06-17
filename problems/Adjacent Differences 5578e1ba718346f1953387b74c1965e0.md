# Adjacent Differences

Created Time: Dec 01, 2020 11:55 PM
Last edited time: May 23, 2021 8:53 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3
Points: 1800
Problem Statement: Given a list of integers nums sorted in ascending order. You can remove at most k integers, minimize the maximum gap between consecutive integers
Source: https://binarysearch.com/problems/Adjacent-Differences
Status: waiting
Tags: gaps

Given a list of integers `nums` sorted in ascending order, remove `k` integers from the list such that the maximum difference between any two adjacent integers is minimized, and return the difference.

**Constraints**

- `n ≤ 1,000` where `n` is the length of `nums`

### **Example 1**

****Input****

`nums = [5, 10, 20, 300, 1000]`
`k = 2`

****Output****

`10`

### **Explanation**

Remove `[300, 1000]` to get the result of `10`.

---