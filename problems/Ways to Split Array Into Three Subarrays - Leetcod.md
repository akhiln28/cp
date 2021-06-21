---
Created Time: Jan 02, 2021 3:39 PM
Do Date: Jan 06, 2021
Last edited time: Mar 01, 2021 8:38 AM
Points: 1500
Pomos (25 mins): 2
Source: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
Status: done
Tags: O(n^2)
---

# Ways to Split Array Into Three Subarrays - Leetcode

A split of an integer array is **good** if:
- The array is split into three **non-empty** contiguous subarrays - named `left`, `mid`, `right` respectively from left to right.
- The sum of the elements in `left` is less than or equal to the sum of the elements in `mid`, and the sum of the elements in `mid` is less than or equal to the sum of the elements in `right`.
Given `nums`, an array of **non-negative** integers, return *the number of **good** ways to split* `nums`. As the number may be too large, return it **modulo** `10^9 + 7`.
**Example 1:**
```
Input: nums = [1,1,1]
Output: 1
Explanation: The only good way to split nums is [1] [1] [1].
```
**Example 2:**
```
Input: nums = [1,2,2,2,5,0]
Output: 3
Explanation: There are three good ways of splitting nums:
[1] [2] [2,2,5,0]
[1] [2,2] [2,5,0]
[1,2] [2,2] [5,0]
```
**Example 3:**
```
Input: nums = [3,2,1]
Output: 0
Explanation: There is no good way to split nums.
```
**Constraints:**
- `3 <= nums.length <= 10^5`
- `0 <= nums[i] <= 104`
---
```cpp
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> cums(n); 
        cums[0] = nums[0]; 
        for (int i = 1; i < n; i++) cums[i] = cums[i - 1] + nums[i]; 
        long long ans = 0, mod = 1e9 + 7; 
        for (int i = 0; i < n; i++)
        {
            int lower = 2 * cums[i], higher = (cums[n - 1] + cums[i])/2; 
            // cout << lower << " " << higher << endl;
            auto it1 = lower_bound(cums.begin() + i + 1, cums.end() - 1, lower); 
            auto it2 = upper_bound(cums.begin() + i + 1, cums.end() - 1, higher);  
            
            int loweridx = it1 - cums.begin(); 
            if (loweridx == n) continue; 
            
            int higheridx = it2 - cums.begin() - 1; 
            
            // cout << "idx " << loweridx << " " << higheridx << endl;
            
            if (higheridx >= loweridx) 
                ans = (ans +  (higheridx - loweridx + 1)) % mod; 
        }
        return ans; 
    }
};
```
Patterns: [Two%20Pointers](Two%20Pointers.md)