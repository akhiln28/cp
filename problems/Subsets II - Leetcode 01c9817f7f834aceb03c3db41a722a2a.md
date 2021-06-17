# Subsets II - Leetcode

Created Time: Feb 08, 2021 1:37 PM
Last edited time: Feb 18, 2021 7:45 AM
Points: 1500
Related To: Subsets%20-%20LeetCode%20d36cff854e0c4b7c8313352e2c614392.md
Source: https://leetcode.com/problems/subsets-ii/
Status: waiting

Given an integer array `nums` that may contain duplicates, return *all possible subsets (the power set)*.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

**Example 1:**

```
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
```

**Example 2:**

```
Input: nums = [0]
Output: [[],[0]]
```

**Constraints:**

- `1 <= nums.length <= 10`
- `10 <= nums[i] <= 10`

---

What is the number of subsets in this case? 

Suppose each element appears $k_1, k_2, ..., k_n$ times. Then the number of possible subsets is given by 

$$(1+k_1)(1+k_2)...(1+k_n)$$

[](https://leetcode.com/problems/subsets-ii/discuss/30168/C%2B%2B-solution-and-explanation)

- [ ]  solve this question using iteration.