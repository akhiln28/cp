# Find First and Last Position of Element in Sorted Array - LeetCode

Created Time: Feb 12, 2021 7:34 AM
Do Date: Feb 12, 2021
Last edited time: Mar 31, 2021 8:59 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Binary-Search-c1187205516c42ac9b3b3c69f153914a
Points: 1500
Source: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Status: ok

Given an array of integers `nums` sorted in ascending order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

**Follow up:** Could you write an algorithm with `O(log n)` runtime complexity?

**Example 1:**

```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

```

**Example 2:**

```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

```

**Example 3:**

```
Input: nums = [], target = 0
Output: [-1,-1]

```

**Constraints:**

- `0 <= nums.length <= 105`
- `109 <= nums[i] <= 109`
- `nums` is a non-decreasing array.
- `109 <= target <= 109`