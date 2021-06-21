---
Created Time: Dec 24, 2020 5:45 PM
Last edited time: May 11, 2021 9:11 AM
Points: 2000
Status: ok
Tags: de shaw
---

# kth Maximum Element in a bst

I thought about this earlier. But I could not find any good default library for that. 
```cpp
int count = 0; 
int kth_max(Node *root, int k)
{
	kth_max(root->right, k); 
	count++;
	if (count == k) return root->val;
	kth_max(root->left, k); 
}
```
Patterns: [Binary%20Tree](Binary%20Tree.md)