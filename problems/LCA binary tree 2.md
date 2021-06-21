---
Created Time: Dec 04, 2020 7:02 PM
Do Date: Dec 07, 2020
Last edited time: May 11, 2021 9:11 AM
Points: 1500
Problem Statement: Given pointers to two nodes in a bst, find the LCA of the two nodes. 
Status: done
---

# LCA binary tree

```python
LCA(node *root, node *n1, node* n2)
	if (!root or root == n1 or root == n2) return root;
	auto t1 = LCA(root->left, n1, n2)
	auto t2 = LCA(root->right, n1, n2); 
	if (t1 and t2) return root;
	else if (t1 and !t2) return t1; 
	else if (!t1 and t2) return t; 
	else return nullptr; 
```
**BST case**
```python
LCA(node *root, node *n1, node* n2)
	if find(root->left, n1) and find(root->left, n2) return root->left;
	if find(root->right, n1) and find(root->right, n2) return root->right;	
```
Patterns: [Binary%20Tree](Binary%20Tree.md)