# Minimum Limit of Balls in a Bag - LeetCode

Created Time: Feb 13, 2021 11:05 AM
Do Date: Feb 13, 2021
Last edited time: Apr 01, 2021 7:00 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Binary-Search-c1187205516c42ac9b3b3c69f153914a
Points: 1650
Source: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
Status: done

You are given an integer array `nums` where the `ith` bag contains `nums[i]` balls. You are also given an integer `maxOperations`.

You can perform the following operation at most `maxOperations` times:

- Take any bag of balls and divide it into two new bags with a **positive** number of balls.
    - For example, a bag of `5` balls can become two new bags of `1` and `4` balls, or two new bags of `2` and `3` balls.

Your penalty is the **maximum** number of balls in a bag. You want to **minimize** your penalty after the operations.

Return *the minimum possible penalty after performing the operations*.

**Example 1:**

```
Input: nums = [9], maxOperations = 2
Output: 3
Explanation: 
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.
```

**Example 2:**

```
Input: nums = [2,4,8,2], maxOperations = 4
Output: 2
Explanation:
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] -> [2,4,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] -> [2,2,2,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].
The bag with the most number of balls has 2 balls, so your penalty is 2 an you should return 2.
```

**Example 3:**

```
Input: nums = [7,17], maxOperations = 2
Output: 7
```

**Constraints:**

- `1 <= nums.length <= 105`
- `1 <= maxOperations, nums[i] <= 109`