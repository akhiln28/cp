---
Created Time: Dec 27, 2020 8:22 AM
Do Date: Dec 27, 2020
Last edited time: May 11, 2021 9:11 AM
Points: 1500
Source: https://leetcode.com/problems/unique-binary-search-trees/
Status: done
Tags: O(n^2)
---

# Unique Binary Search Trees - LeetCode

Given *n*, how many structurally unique **BST's** (binary search trees) that store values 1 ... *n*?
**Example:**
```
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```
**Constraints:**
- `1 <= n <= 19`
---
I used dp as shown below. 
```cpp
class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 1; 
        vector<int> dp(n + 1);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += (dp[j - 1] * dp[i - j]);
            }
        }
        return dp[n]; 
    }
};
```
Patterns: [Binary%20Tree](patterns/Binary%20Tree.md)