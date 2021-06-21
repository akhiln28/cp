---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 22, 2020
Last edited time: Dec 22, 2020 4:27 PM
Points: 1700
Pomos (25 mins): 1
Problem Statement: Find the first missing positive integer from the given list integers. 
Source: https://leetcode.com/problems/first-missing-positive/
Status: ok
---

# First missing positive

Given an unsorted integer array `nums`, find the smallest missing positive integer.
**Follow up:** Could you implement an algorithm that runs in `O(n)` time and uses constant extra space.?
**Example 1:**
```
Input: nums = [1,2,0]
Output: 3
```
**Example 2:**
```
Input: nums = [3,4,-1,1]
Output: 2
```
**Example 3:**
```
Input: nums = [7,8,9,11,12]
Output: 1
```
**Constraints:**
- `0 <= nums.length <= 300`
- `231 <= nums[i] <= 231 - 1`
---
1. sorting takes O(nlogn) - done
2. hashing O(n) time, O(n) space - done
Another method is to place number i at the ith location. Something like below, 
```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(); 
        for (int i = 0; i < n; i++)
        {
            while (nums[i] < n and nums[i] > 0 and nums[i] != nums[nums[i] - 1])
            {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1) return i + 1; 
        }
        return n + 1;
    }
};
```
Previously, I did something like this, (use the array itself as the storage service)
```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> nums1; 
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > 0) nums1.push_back(-nums[i]);
        for (int i = 0; i < nums1.size(); i++)
        {
            if (abs(nums1[i]) <= nums1.size()) nums1[abs(nums1[i]) - 1] = abs(nums1[abs(nums1[i]) - 1]); 
        }
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (nums1[i] < 0) {ans = i + 1; break;}
        }
        if (ans == 0) ans = nums1.size() + 1; 
        return ans; 
    }
};
```
Patterns: 