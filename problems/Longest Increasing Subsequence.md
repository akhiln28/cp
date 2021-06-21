---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Jan 02, 2021
Last edited time: Mar 01, 2021 8:46 AM
Points: 2000
Pomos (25 mins): 3
Relates: Minimum%20Operations%20to%20Make%20a%20Subsequence%20-%20Leetcod%2001e610d2b8a54dc6bfb4b35b31ff2669.md
Source: https://leetcode.com/problems/longest-increasing-subsequence/
Status: ok
Tags: new
---

# Longest Increasing Subsequence

Given an integer array `nums`, return the length of the longest strictly increasing subsequence.
A **subsequence** is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, `[3,6,2,7]` is a subsequence of the array `[0,3,1,6,2,2,7]`.
**Example 1:**
```
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```
**Example 2:**
```
Input: nums = [0,1,0,3,2,3]
Output: 4
```
**Example 3:**
```
Input: nums = [7,7,7,7,7,7,7]
Output: 1
```
**Constraints:**
- `1 <= nums.length <= 2500`
- `-10^4 <= nums[i] <= 10^4`
**Follow up:**
- Could you come up with the `O(n^2)` solution?
- Could you improve it to `O(n log(n))` time complexity?
---
The standard O(n^2) solution. 
Below is the O (n log n) solution. I don't understand how it is working. 
```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0; 
        if (nums.size() == 1) return 1; 
        vector<int> arr; 
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = lower_bound(arr.begin(), arr.end(), nums[i]);
            if (it == arr.end()) arr.push_back(nums[i]); 
            else *it = nums[i];  
            // for (int i = 0; i < arr.size(); i++) cout << arr[i] << " "; cout << endl;
        }
        return arr.size(); 
    }
};
```
Patterns: [Dp](Dp.md)