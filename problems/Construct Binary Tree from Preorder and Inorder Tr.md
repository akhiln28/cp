---
Created Time: Dec 01, 2020 11:55 PM
Last edited time: May 11, 2021 9:11 AM
Points: 1500
Status: done
---

# Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.
**Note:**You may assume that duplicates do not exist in the tree.
For example, given
```
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
```
Return the following binary tree:
```
    3
   / \
  9  20
    /  \
   15   7
```
---
```cpp
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr; 
        if (preorder.size() == 1) return (new TreeNode(preorder[0])); 
        
        TreeNode *root = new TreeNode(preorder[0]); 
        int idx = -1; 
        for (int i = 0; i < inorder.size(); i++)
        {
            if (preorder[0] == inorder[i])
            {
                idx = i; 
                break; 
            }
        }
        vector<int> v1(inorder.begin(), inorder.begin() + idx), v2(inorder.begin() + idx + 1, inorder.end()); 
        vector<int> v3(preorder.begin() + 1, preorder.begin() + idx + 1), v4(preorder.begin() + idx + 1, preorder.end()); 
        TreeNode *left = buildTree(v3, v1);
        TreeNode *right = buildTree(v4, v2); 
        root->left = left;
        root->right = right; 
        return root; 
    }
};
```
Patterns: [Binary%20Tree](patterns/Binary%20Tree.md)