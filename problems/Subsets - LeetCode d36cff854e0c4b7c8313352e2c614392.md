# Subsets - LeetCode

Created Time: Feb 08, 2021 1:30 PM
Do Date: Feb 08, 2021
Last edited time: Apr 06, 2021 9:02 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Backtracking-90d58a7ffa85438e86ce346981bf35b5, https://www.notion.so/Recursion-cc19c59122e4470f90cfd5d1fcb17409
Points: 1500
Pomos (25 mins): 1
Relates: Subsets%20II%20-%20Leetcode%2001c9817f7f834aceb03c3db41a722a2a.md
Source: https://leetcode.com/problems/subsets/
Status: ok

Given an integer array `nums` of **unique** elements, return *all possible subsets (the power set)*.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

**Example 1:**

```
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

**Example 2:**

```
Input: nums = [0]
Output: [[],[0]]
```

**Constraints:**

- `1 <= nums.length <= 10`
- `10 <= nums[i] <= 10`
- All the numbers of `nums` are **unique**.

---

```jsx
class Solution {
public:
    void subsets_util(vector<int>& nums, vector<vector<int>>& powerset, int i, vector<int>& se)
    {
        if (i == nums.size()) 
        {
            powerset.push_back(se); 
            return;
        }
        subsets_util(nums, powerset, i + 1, se); 
        se.push_back(nums[i]); 
        subsets_util(nums, powerset, i + 1, se); 
        se.pop_back(); 
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerset; 
        vector<int> se;
        subsets_util(nums, powerset, 0, se);
        return powerset;
    }
};
```

- [ ]  solve this question using iteration