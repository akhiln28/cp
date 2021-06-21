---
Created Time: Mar 05, 2021 10:35 AM
Last edited time: Mar 05, 2021 10:40 AM
Points: 1600
Source: https://leetcode.com/problems/reorder-list/
Status: ok
---

# Reorder List - Leetcode

You are given the head of a singly linked-list. The list can be represented as:
```
L0 → L1 → … → Ln - 1 → Ln
```
*Reorder the list to be on the following form:*
```
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
```
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
**Example 1:**
![Reorder%20List%20-%20Leetcode%2095f2a0c356f143538869f2602a80e846/reorder1linked-list.jpg](Reorder%20List%20-%20Leetcode%2095f2a0c356f143538869f2602a80e846/reorder1linked-list.jpg)
```
Input: head = [1,2,3,4]
Output: [1,4,2,3]
```
**Example 2:**
![Reorder%20List%20-%20Leetcode%2095f2a0c356f143538869f2602a80e846/reorder2linked-list.jpg](Reorder%20List%20-%20Leetcode%2095f2a0c356f143538869f2602a80e846/reorder2linked-list.jpg)
```
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
```
**Constraints:**
- The number of nodes in the list is in the range `[1, 5 * 10&4]`.
- `1 <= Node.val <= 1000`
---
Patterns: [Linked%20List](Linked%20List.md)