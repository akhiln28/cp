# Count the Number of Binary Search Trees present in a Binary Tree - GeeksforGeeks

Created Time: Dec 27, 2020 8:33 AM
Last edited time: May 11, 2021 9:11 AM
Pattern: https://www.notion.so/Binary-Tree-2b7ef3f8a3684c2c8790ae61ff7ddaea
Points: 1500
Related To: Validate%20Binary%20Search%20Tree%203a1ac6b53afb4610b460ef27f8ae4d67.md
Source: https://www.geeksforgeeks.org/count-the-number-of-binary-search-trees-present-in-a-binary-tree/
Status: ok
Tags: alphonso

Given a binary tree, the task is to count the number of Binary Search Trees present in it.

**Examples:**

> Input:      1
   /  \
  2    3
 / \  / \
4   5 6  7 Output: 4Here each leaf node represents a binary search tree and there are total 4 nodes.Input:       11
     /  \
    8    10
   /    /  \
  5    9    8
 / \
4   6 Output: 6 Sub-tree rooted under node 5 is a BST    5
  / \
 4   6 Another BST we have is rooted under the node 8         8    
       /    
      5    
     / \
    4   6 Thus total 6 BSTs are present (including the leaf nodes).

**Approach:** A Binary Tree is a Binary Search Tree if the following are true for every node x.

1. The largest value in left subtree (of x) is smaller than value of x.
2. The smallest value in right subtree (of x) is greater than value of x.

We traverse tree in bottom up manner. For every traversed node, we store the information of maximum and minimum of that subtree, a variable **isBST** to store if it is a BST and variable **num_BST** to store the number of Binary search tree rooted under the current node.
Below is the implementation of the above approach:

Attention reader! Don’t stop learning now. Get hold of all the important DSA concepts with the **[DSA Self Paced Course](https://practice.geeksforgeeks.org/courses/dsa-self-paced?utm_source=geeksforgeeks&utm_medium=article&utm_campaign=gfg_article_dsa_content_bottom)** at a student-friendly price and become industry ready.