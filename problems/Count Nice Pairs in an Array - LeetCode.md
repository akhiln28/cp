---
Created Time: Apr 05, 2021 7:22 AM
Last edited time: Apr 05, 2021 7:22 AM
Points: 1500
Source: https://leetcode.com/problems/count-nice-pairs-in-an-array/
Status: done
---

# Count Nice Pairs in an Array - LeetCode

![LeetCode_Sharing.png](Count%20Nice%20Pairs%20in%20an%20Array%20-%20LeetCode%2003145e70dd6e4eaa99c1c8d96ee99e77/LeetCode_Sharing.png)
You are given an array `nums` that consists of non-negative integers. Let us define `rev(x)` as the reverse of the non-negative integer `x`. For example, `rev(123) = 321`, and `rev(120) = 21`. A pair of indices `(i, j)` is **nice** if it satisfies all of the following conditions:
- `0 <= i < j < nums.length`
- `nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])`
Return *the number of nice pairs of indices*. Since that number can be too large, return it **modulo** `109 + 7`.
**Example 1:**
```
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
```
**Example 2:**
```
Input: nums = [13,10,35,24,76]
Output: 4
```
**Constraints:**
- `1 <= nums.length <= 105`
- `0 <= nums[i] <= 109`
Patterns: 