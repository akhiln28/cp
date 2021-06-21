---
Created Time: Dec 19, 2020 7:01 PM
Do Date: Jan 23, 2021
Last edited time: Mar 01, 2021 3:43 PM
Points: 2000
Pomos (25 mins): 2
Source: https://leetcode.com/problems/get-the-maximum-score/
Status: waiting
Tags: hard
---

# Get the Maximum Score - LeetCode

You are given two **sorted** arrays of distinct integers `nums1` and `nums2.`
A **validpath** is defined as follows:
- Choose array nums1 or nums2 to traverse (from index-0).
- Traverse the current array from left to right.
- If you are reading any value that is present in `nums1` and `nums2` you are allowed to change your path to the other array. (Only one repeated value is considered in the valid path).
*Score* is defined as the sum of uniques values in a valid path.
Return the maximum *score* you can obtain of all possible **valid paths**.
Since the answer may be too large, return it modulo 10^9 + 7.
**Example 1:**
![Get%20the%20Maximum%20Score%20-%20LeetCode%20ecb7cd4d21234ba1a9065452b25f4184/sample_1_1893.png](Get%20the%20Maximum%20Score%20-%20LeetCode%20ecb7cd4d21234ba1a9065452b25f4184/sample_1_1893.png)
```
Input: nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
Output: 30
Explanation: Valid paths:
[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],  (starting from nums1)
[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]    (starting from nums2)
The maximum is obtained with the path in green [2,4,6,8,10].
```
**Example 2:**
```
Input: nums1 = [1,3,5,7,9], nums2 = [3,5,100]
Output: 109
Explanation: Maximum sum is obtained with the path [1,3,5,100].
```
**Example 3:**
```
Input: nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
Output: 40
Explanation: There are no common elements between nums1 and nums2.
Maximum sum is obtained with the path [6,7,8,9,10].
```
**Example 4:**
```
Input: nums1 = [1,4,5,8,9,11,19], nums2 = [2,3,4,11,12]
Output: 61
```
**Constraints:**
- `1 <= nums1.length <= 10^5`
- `1 <= nums2.length <= 10^5`
- `1 <= nums1[i], nums2[i] <= 10^7`
- `nums1` and `nums2` are strictly increasing.
---
Patterns: [Two%20Pointers](Two%20Pointers.md)[patterns/Greedy](patterns/Greedy.md)