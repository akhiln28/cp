# Swapping Nodes in a Linked List - Leetcode

Created Time: Jan 09, 2021 9:51 AM
Do Date: Jan 09, 2021
Last edited time: May 11, 2021 9:04 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Traversal-dca46f72f93e4db583e0e72ba3dc6fdb
Points: 1000
Source: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
Status: done

I find the below solution useful. 

[](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/discuss/1009800/C%2B%2B-One-Pass)

When we reach `k`-th node, we set `n1` to the current node, and `n2` - to the head.

We continue traversing the list, but now we also move `n2`. When we reach the end, `n2` will points to `k`-th node from end.