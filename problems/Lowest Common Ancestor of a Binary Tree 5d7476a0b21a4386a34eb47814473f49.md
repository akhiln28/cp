# Lowest Common Ancestor of a Binary Tree

Created Time: Dec 01, 2020 11:55 PM
Do Date: Jan 27, 2021
Last edited time: May 11, 2021 9:11 AM
Pattern: https://www.notion.so/Binary-Tree-2b7ef3f8a3684c2c8790ae61ff7ddaea
Points: 1500
Relates: Lowest%20Common%20Ancestor%20of%20a%20General%20Tree%202e592b3739b5492892b46a706cda6b72.md
Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
Status: done

```jsx
class Solution {
public:
    TreeNode *ans; 
    bool exists(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr) return 0; 
        bool left = exists(root->left, p, q); 
        bool right = exists(root->right, p, q);
        bool mid = (root == p or q == root);
        
        if (left + mid + right >= 2) ans = root; 
        return left + mid + right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        exists(root, p, q); 
        return ans; 
    }
};
```