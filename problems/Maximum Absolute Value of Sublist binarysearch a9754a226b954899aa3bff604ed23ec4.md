# Maximum Absolute Value of Sublist | binarysearch

Created Time: Mar 03, 2021 8:18 AM
Last edited time: Mar 03, 2021 8:18 AM
Pattern: https://www.notion.so/Subarray-ef1d425ad64945bf849cd2e45d4ee4aa, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3
Points: 1500
Source: https://binarysearch.com/problems/Maximum-Absolute-Value-of-Sublist
Status: done

You are given a list of integers `nums`. Return the maximum possible `abs(nums[i] + nums[i + 1] + ... + nums[j])` for any `i <= j`.

**Constraints**

- `0 ≤ n ≤ 100,000` where `n` is the length of `nums`

### **Explanation**

We can take the sublist `[-7, -2]` to get `abs(-7 + -2) = 9`.