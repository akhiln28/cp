# Kth Smallest Element in a BST - LeetCode

Created Time: Feb 09, 2021 7:59 AM
Do Date: Feb 09, 2021
Last edited time: May 11, 2021 9:11 AM
Pattern: https://www.notion.so/Binary-Tree-2b7ef3f8a3684c2c8790ae61ff7ddaea
Points: 1200
Pomos (25 mins): 1
Relates: BST%20%5Bgetting%20the%20kth%20smallest%20element%5D%20c4eab2aacf694a73a4a3ed60e2ddb104.md
Source: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
Status: done

Given the `root` of a binary search tree, and an integer `k`, return *the* `kth` (**1-indexed**) *smallest element in the tree*.

**Example 1:**

```
Input: root = [3,1,4,null,2], k = 1
Output: 1

```

**Example 2:**

![Kth%20Smallest%20Element%20in%20a%20BST%20-%20LeetCode%2048715518ea7946aaad7afe4a249f0188/kthtree2.jpg](kthtree2.jpg)

```
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

```

**Constraints:**

- The number of nodes in the tree is `n`.
- `1 <= k <= n <= 104`
- `0 <= Node.val <= 104`

**Follow up:** If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

---

```cpp
class Solution {
public:
    int count = 0, ans; 
    void inorder_traversal(TreeNode* root, int k)
    {
        if (root == nullptr) return;
        inorder_traversal(root->left, k); 
        if (count == k - 1)
        {
            ans = root->val;
        }
        count++;
        inorder_traversal(root->right, k); 
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder_traversal(root, k); 
        return ans; 
    }
};
```