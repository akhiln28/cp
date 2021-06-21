---
Created Time: Feb 02, 2021 9:13 AM
Do Date: Feb 04, 2021
Last edited time: Mar 07, 2021 9:23 AM
Points: 1500
Pomos (25 mins): 1
Relates: Print%20Derangements%20c51172033f2f4ba0a8b51955274eebc4.md
Source: https://leetcode.com/problems/permutations/
Status: done
---

# Permutations - LeetCode

Given an array `nums` of distinct integers, return *all the possible permutations*. You can return the answer in **any order**.
**Example 1:**
```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```
**Example 2:**
```
Input: nums = [0,1]
Output: [[0,1],[1,0]]
```
**Example 3:**
```
Input: nums = [1]
Output: [[1]]
```
**Constraints:**
- `1 <= nums.length <= 6`
- `10 <= nums[i] <= 10`
- All the integers of `nums` are **unique**.
---
```jsx
class Solution {
public:
    void permute_util(vector<int>& nums, int i, vector<vector<int>>& ans)
    {
        if (i == nums.size()) ans.push_back(nums); 
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]); 
            permute_util(nums, i + 1, ans); 
            swap(nums[i], nums[j]); 
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        permute_util(nums, 0, ans); 
        return ans; 
    }
};
```
Patterns: [Array](Array.md)[Backtracking](Backtracking.md)