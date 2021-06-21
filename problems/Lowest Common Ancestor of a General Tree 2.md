---
Created Time: Jan 27, 2021 7:23 PM
Last edited time: May 20, 2021 9:55 AM
Points: 1600
Related To: Lowest%20Common%20Ancestor%20of%20a%20Binary%20Tree%205d7476a0b21a4386a34eb47814473f49.md
Status: waiting
---

# Lowest Common Ancestor of a General Tree

If we can access the parent, we can create two linked lists (i.e. paths from current nodes to the root). Now the answer is the intersection of two linked lists. Can be done in O(1) space. 
But if we cannot access the parent, then we have to do that in O(n) complexity, like we did for binary tree.
Patterns: 