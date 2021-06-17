# Binary Tree Cameras - LeetCode

Created Time: Jan 26, 2021 2:31 PM
Do Date: Jan 27, 2021
Last edited time: Mar 01, 2021 8:46 AM
Pattern: https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee
Points: 2000
Pomos (25 mins): 1
Source: https://leetcode.com/problems/binary-tree-cameras/
Status: ok
Tags: microsoft

Given a binary tree, we install cameras on the nodes of the tree.

Each camera at a node can monitor **its parent, itself, and its immediate children**.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

**Example 1:**

```
Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

```

**Example 2:**

```
Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

```

**Note:**

1. The number of nodes in the given tree will be in the range `[1, 1000]`.
2. **Every** node has value 0.

---