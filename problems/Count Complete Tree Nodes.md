---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Jan 30, 2021
Last edited time: May 11, 2021 9:11 AM
Points: 1500
Problem Statement: Given a binary tree find the number of nodes in it?
Source: https://leetcode.com/problems/count-complete-tree-nodes/
Status: ok
---

# Count Complete Tree Nodes

Given the `root` of a **complete** binary tree, return the number of the nodes in the tree.
According to **[Wikipedia](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees)**, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between `1` and `2h` nodes inclusive at the last level `h`.
**Example 1:**
![https://assets.leetcode.com/uploads/2021/01/14/complete.jpg](https://assets.leetcode.com/uploads/2021/01/14/complete.jpg)
```
Input: root = [1,2,3,4,5,6]
Output: 6
```
**Example 2:**
```
Input: root = []
Output: 0
```
**Example 3:**
```
Input: root = [1]
Output: 1
```
**Constraints:**
- The number of nodes in the tree is in the range `[0, 5 * 104]`.
- `0 <= Node.val <= 5 * 104`
- The tree is guaranteed to be **complete**.
**Follow up:**
Traversing the tree to count the number of nodes in the tree is an easy solution but with `O(n)` complexity. Could you find a faster algorithm?
```cpp
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0; 
        int height = 0; 
        auto l = root, r = root; 
        while (r)
        {
            l = l->left; 
            r = r->right; 
            height++;
        }
        if (l == nullptr)
        {
            return (1 << height) - 1; 
        }
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
};
```
Patterns: [Binary%20Tree](Binary%20Tree.md)