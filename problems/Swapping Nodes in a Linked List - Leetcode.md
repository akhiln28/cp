---
Created Time: Jan 09, 2021 9:51 AM
Do Date: Jan 09, 2021
Last edited time: May 11, 2021 9:04 AM
Points: 1000
Source: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
Status: done
---

# Swapping Nodes in a Linked List - Leetcode

I find the below solution useful. 
[](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/discuss/1009800/C%2B%2B-One-Pass)
When we reach `k`-th node, we set `n1` to the current node, and `n2` - to the head.
We continue traversing the list, but now we also move `n2`. When we reach the end, `n2` will points to `k`-th node from end.
Patterns: [Array](Array.md)[patterns/Greedy](patterns/Greedy.md)[Traversal](Traversal.md)