---
Created Time: Apr 27, 2021 7:51 AM
Day Completed: https://www.notion.so/30-April-21-cdb6169a08bf4686a2dad950f86feceb
Do Date: Apr 29, 2021
Last edited time: Apr 29, 2021 8:21 AM
Points: 1600
Source: https://leetcode.com/problems/frequency-of-the-most-frequent-element/
Status: done
---

# Frequency of the Most Frequent Element - LeetCode

![LeetCode_Sharing.png](Frequency%20of%20the%20Most%20Frequent%20Element%20-%20LeetCode%20ef7bde2cf3ef4d28beaa097d49086e24/LeetCode_Sharing.png)
The **frequency** of an element is the number of times it occurs in an array.
You are given an integer array `nums` and an integer `k`. In one operation, you can choose an index of `nums` and increment the element at that index by `1`.
Return *the **maximum possible frequency** of an element after performing **at most*** `k` *operations*.
**Example 1:**
```
Input: nums = [1,2,4], k = 5
Output: 3
Explanation: Increment the first element three times and the second element two times to make nums = [4,4,4].
4 has a frequency of 3.
```
**Example 2:**
```
Input: nums = [1,4,8,13], k = 5
Output: 2
Explanation: There are multiple optimal solutions:
- Increment the first element three times to make nums = [4,4,8,13]. 4 has a frequency of 2.
- Increment the second element four times to make nums = [1,8,8,13]. 8 has a frequency of 2.
- Increment the third element five times to make nums = [1,4,13,13]. 13 has a frequency of 2.
```
**Example 3:**
```
Input: nums = [3,9,6], k = 2
Output: 1
```
**Constraints:**
- `1 <= nums.length <= 105`
- `1 <= nums[i] <= 105`
- `1 <= k <= 105`
Patterns: [patterns/Greedy](patterns/Greedy.md)[Sliding%20Window](Sliding%20Window.md)