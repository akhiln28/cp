# Search in Rotated Sorted Array - LeetCode

Created Time: Mar 05, 2021 9:12 PM
Do Date: Mar 05, 2021
Last edited time: Mar 06, 2021 10:06 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Sorting-Algorithms-5c0a4b35496f4ead9e9b40f16582d479, https://www.notion.so/Binary-Search-c1187205516c42ac9b3b3c69f153914a
Points: 1500
Source: https://leetcode.com/problems/search-in-rotated-sorted-array/
Status: ok
Tags: goldman sachs

There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is **rotated** at an unknown pivot index `k` (`0 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` **after** the rotation and an integer `target`, return *the index of* `target` *if it is in* `nums`*, or* `-1` *if it is not in* `nums`.

**Example 1:**

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

```

**Example 2:**

```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

```

**Example 3:**

```
Input: nums = [1], target = 0
Output: -1

```

**Constraints:**

- `1 <= nums.length <= 5000`
- `104 <= nums[i] <= 104`
- All values of `nums` are **unique**.
- `nums` is guaranteed to be rotated at some pivot.
- `104 <= target <= 104`

**Follow up:** Can you achieve this in `O(log n)` time complexity?