# Array Nesting - LeetCode

Created Time: Feb 09, 2021 8:17 PM
Do Date: Feb 10, 2021
Last edited time: May 11, 2021 9:04 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Traversal-dca46f72f93e4db583e0e72ba3dc6fdb
Points: 1500
Source: https://leetcode.com/problems/array-nesting/
Status: done

A zero-indexed array A of length N contains all integers from 0 to N-1. Find and return the longest length of set S, where S[i] = {A[i], A[A[i]], A[A[A[i]]], ... } subjected to the rule below.

Suppose the first element in S starts with the selection of element A[i] of index = i, the next element in S should be A[A[i]], and then A[A[A[i]]]… By that analogy, we stop adding right before a duplicate element occurs in S.

**Example 1:**

```
Input: A = [5,4,0,3,1,6,2]
Output: 4
Explanation: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.

One of the longest S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
```

**Note:**

1. N is an integer within the range [1, 20,000].
2. The elements of A are all distinct.
3. Each element of A is an integer within the range [0, N-1].

---

The array can be divided into many cycles. We need to find the maximum length of the cycle. 

```jsx
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> loc(n); 
        for (int i = 0; i < n; i++)
        {
            loc[nums[i]] = i; 
        }
        vector<bool> vis(n); 
        int ans = 0; 
        for (int i = 0; i < n; i++)
        {
            int start = nums[i]; 
            int count = 0; 
            while (vis[start] == false)
            {
                vis[start] = true; 
                start = nums[start]; 
                count++; 
            }
            ans = max(ans, count); 
        }
        return ans; 
    }
};
```