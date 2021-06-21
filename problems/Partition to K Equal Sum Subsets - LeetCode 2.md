---
Created Time: Jan 31, 2021 2:43 PM
Do Date: Feb 02, 2021
Last edited time: Mar 07, 2021 9:23 AM
Points: 1600
Pomos (25 mins): 1
Source: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
Status: ok
---

# Partition to K Equal Sum Subsets - LeetCode

Given an array of integers `nums` and a positive integer `k`, find whether it's possible to divide this array into `k` non-empty subsets whose sums are all equal.
**Example 1:**
```
Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
Output: True
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
```
**Note:**
- `1 <= k <= len(nums) <= 16`.
- `0 < nums[i] < 10000`.
---
The sum in each subset should be equal to $sum = \frac{total}{k}$.
If the array contains element greater than sum, return false. 
Backtracking...
```cpp
class Solution {
public:
    bool is_possible(vector<int>& nums, int i, int target, vector<int>& subsets)
    {
        if (i == nums.size()) return true; 
        bool ans = false; 
        for (int j = 0; j < subsets.size(); j++)
        {
            if (subsets[j] == target) continue; 
            if (subsets[j] + nums[i] <= target)
            {
                subsets[j] += nums[i]; 
                ans = is_possible(nums, i + 1, target, subsets); 
                subsets[j] -= nums[i];
                if (ans) break; 
            }
        }
        return ans; 
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % k != 0) return false; 
        
        target /= k; 
        for (auto e : nums)
        {
            if (e > target) return false;
        }
        vector<int> subsets(k);
        return is_possible(nums, 0, target, subsets); 
    }
};
```
- [ ]  complexity
Patterns: [Array](Array.md)[Backtracking](Backtracking.md)