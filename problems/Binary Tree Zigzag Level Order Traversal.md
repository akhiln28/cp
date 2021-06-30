---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Jan 29, 2021
Last edited time: May 11, 2021 9:11 AM
Points: 1500
Status: done
---

# Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
For example:Given binary tree `[3,9,20,null,null,15,7]`,
```
    3
   / \
  9  20
    /  \
   15   7
```
return its zigzag level order traversal as:
```
[
  [3],
  [20,9],
  [15,7]
]
```
---
```cpp
class Solution {
public:
    void level_order(TreeNode *root, vector<vector<int>> &ans, int level)
    {
        if (root == nullptr) return;
        if (level < ans.size()) ans[level].push_back(root->val);
        else if (level == ans.size()) ans.push_back({root->val});
        level_order(root->left, ans, level + 1); 
        level_order(root->right, ans, level + 1); 
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans; 
        level_order(root, ans, 0); 
        for (int i = 0; i < ans.size(); i++)
        {
            if (i & 1) reverse(ans[i].begin(), ans[i].end()); 
        }
        return ans; 
    }
};
```
Patterns: [Binary%20Tree](patterns/Binary%20Tree.md)