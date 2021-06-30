---
Created Time: Feb 10, 2021 9:13 AM
Do Date: Feb 10, 2021
Last edited time: May 11, 2021 9:11 AM
Points: 1500
Related To: Binary%20Tree%20Maximum%20Path%20Sum%20-%20LeetCode%2028ebeed1237b40b4a956425aa1a7f1dc.md
Source: https://leetcode.com/problems/longest-univalue-path/
Status: done
---

# Longest Univalue Path - LeetCode

Given the `root` of a binary tree, return *the length of the longest path, where each node in the path has the same value*. This path may or may not pass through the root.
**The length of the path** between two nodes is represented by the number of edges between them.
**Example 1:**
![Longest%20Univalue%20Path%20-%20LeetCode%2065cafe19478b4f4ca3830cdb472f422b/ex1.jpg](Longest%20Univalue%20Path%20-%20LeetCode%2065cafe19478b4f4ca3830cdb472f422b/ex1.jpg)
```
Input: root = [5,4,5,1,1,5]
Output: 2
```
**Example 2:**
![Longest%20Univalue%20Path%20-%20LeetCode%2065cafe19478b4f4ca3830cdb472f422b/ex2.jpg](Longest%20Univalue%20Path%20-%20LeetCode%2065cafe19478b4f4ca3830cdb472f422b/ex2.jpg)
```
Input: root = [1,4,5,4,4,5]
Output: 2
```
**Constraints:**
- The number of nodes in the tree is in the range `[0, 104]`.
- `1000 <= Node.val <= 1000`
- The depth of the tree will not exceed `1000`.
---
```jsx
class Solution {
public:
    int ans = 0; 
    int path_node(TreeNode* root)
    {
        if (root == nullptr) return 0; 
        int left = path_node(root->left); 
        int right = path_node(root->right); 
        if (root->left)
        {
            left = ((root->left)->val == root->val) * left;
        }
        if (root->right)
        {
            right = ((root->right)->val == root->val) * right; 
        }
        ans = max(ans, 1 + left + right); 
        return 1 + max(left, right); 
    }
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0; 
        path_node(root); 
        return ans - 1; 
    }
};
```
Patterns: [Binary%20Tree](patterns/Binary%20Tree.md)