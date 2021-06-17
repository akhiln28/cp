# Create Maximum Number - Leetcode

Created Time: Feb 16, 2021 8:43 AM
Last edited time: May 23, 2021 8:53 AM
Pattern: https://www.notion.so/Number-Theory-02e26369bab8475881b8a6a9d7b33ca9
Points: 2000
Source: https://leetcode.com/problems/create-maximum-number/
Status: waiting

Given two arrays of length `m` and `n` with digits `0-9` representing two numbers. Create the maximum number of length `k <= m + n` from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the `k` digits.

**Note:** You should try to optimize your time and space complexity.

**Example 1:**

```
Input:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
Output:[9, 8, 6, 5, 3]
```

**Example 2:**

```
Input:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
Output:[6, 7, 6, 0, 4]
```

**Example 3:**

```
Input:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
Output:[9, 8, 9]
```

---