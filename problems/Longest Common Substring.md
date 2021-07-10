---
Created Time: Dec 19, 2020 10:58 PM
Do Date: Dec 19, 2020
Last edited time: Mar 01, 2021 8:47 AM
Points: 1500
Pomos (25 mins): 1
Source: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
Status: done
Tags: standard
---

# Maximum Length of Repeated Subarray - Length of longest common substring

Given two integer arrays `A` and `B`, return the maximum length of an subarray that appears in both arrays.
**Example 1:**
```
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].
```
**Note:**
1. 1 <= len(A), len(B) <= 1000
2. 0 <= A[i], B[i] < 100
---
**`dp[i][j]` denotes the length of the longest substring ending at $i$ in `A` and ending at `j` in `B`**

```cpp
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size(); 
        vector<vector<int>> dp(n, vector<int> (m));
        int ans = 0; 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (A[i] == B[j]) dp[i][j] = 1 + ((i and j) ? dp[i - 1][j - 1] : 0);
                ans = max(ans, dp[i][j]); 
            }
        }
        return ans; 
    }
};
```
Patterns: [[Two Pointer DP]]