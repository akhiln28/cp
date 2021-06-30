---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 27, 2020
Last edited time: May 11, 2021 9:11 AM
Points: 1500
Pomos (25 mins): 1
Relates: Count%20the%20Number%20of%20Binary%20Search%20Trees%20present%20in%20537f1545528a49469e86ec421698a027.md
Status: done
---

# Validate Binary Search Tree

Given the `root` of a binary tree, *determine if it is a valid binary search tree (BST)*.
A **valid BST** is defined as follows:
- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.
**Example 1:**
![https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)
```
Input: root = [2,1,3]
Output: true
```
**Example 2:**
![https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)
```
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```
**Constraints:**
- The number of nodes in the tree is in the range `[1, 104]`.
- `231 <= Node.val <= 231 - 1`
---
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool recur(TreeNode* root, pair<long long, long long> range)
    {
        if (root == nullptr) return true; 
        bool flag = (root->val < range.second and root->val > range.first); 
        if (!flag) return false; 
        return recur(root->right, {root->val, range.second}) and recur(root->left, {range.first, root->val}); 
    }
    bool isValidBST(TreeNode* root) {
        return recur(root, {-1e18, 1e18}); 
    }
};
```
Patterns: [Binary%20Tree](patterns/Binary%20Tree.md)