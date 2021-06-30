---
created at: 2021-06-28
author: akhiln
tags: [problem, binary_tree]
level: unknown
---

# Count the Number of Binary Search Trees present in a Binary Tree
### Problem Statement
Given a binary tree find the number of binary search trees which are subtrees of it.

#### Examples

### Solution
- For each node find the minimum and maximum value in the whole subtree rooted at that node.
- Also we store the number of BST's with root as the current node.


```python
# bstCount(node) -> denotes the number of BST's rooted at this node
for node in nodes:
	# we have
	bstCount(node.left)
	bstCount(node.right)
	bstCount(node)
```

#### References
1. similar to [[Number of subtrees in a binary tree]]