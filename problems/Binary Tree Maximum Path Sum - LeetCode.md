---
Created Time: Feb 10, 2021 9:06 AM
Do Date: Feb 10, 2021
Last edited time: May 11, 2021 9:11 AM
Points: 1800
Relates: Longest%20Univalue%20Path%20-%20LeetCode%2065cafe19478b4f4ca3830cdb472f422b.md
Source: https://leetcode.com/problems/binary-tree-maximum-path-sum/
Status: done
---

# Binary Tree Maximum Path Sum - LeetCode

A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence **at most once**. Note that the path does not need to pass through the root.
The **path sum** of a path is the sum of the node's values in the path.
Given the `root` of a binary tree, return *the maximum **path sum** of any path*.
**Example 1:**
![Binary%20Tree%20Maximum%20Path%20Sum%20-%20LeetCode%2028ebeed1237b40b4a956425aa1a7f1dc/exx1.jpg](Binary%20Tree%20Maximum%20Path%20Sum%20-%20LeetCode%2028ebeed1237b40b4a956425aa1a7f1dc/exx1.jpg)
```
Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
```
**Example 2:**
![Binary%20Tree%20Maximum%20Path%20Sum%20-%20LeetCode%2028ebeed1237b40b4a956425aa1a7f1dc/exx2.jpg](Binary%20Tree%20Maximum%20Path%20Sum%20-%20LeetCode%2028ebeed1237b40b4a956425aa1a7f1dc/exx2.jpg)
```
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
```
**Constraints:**
- The number of nodes in the tree is in the range `[1, 3 * 104]`.
- `1000 <= Node.val <= 1000`
Patterns: [Binary%20Tree](patterns/Binary%20Tree.md)