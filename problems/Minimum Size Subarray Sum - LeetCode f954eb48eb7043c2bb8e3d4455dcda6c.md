# Minimum Size Subarray Sum - LeetCode

Created Time: Dec 19, 2020 11:20 PM
Do Date: Jan 09, 2021
Last edited time: May 11, 2021 9:00 AM
Pattern: https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Sliding-Window-57edd445fc8d49ac98bcd1076bcdd3aa
Points: 1500
Source: https://leetcode.com/problems/minimum-size-subarray-sum/
Status: done
Tags: monotonic, standard

Given an array of **n** positive integers and a positive integer **s**, find the minimal length of a **contiguous** subarray of which the sum ≥ **s**. If there isn't one, return 0 instead.

**Example:**

```
Input: s = 7, nums = [2,3,1,2,4,3]Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
```

---

Easy sliding window.

```cpp
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), left = 0, right = -1; 
        int window = 0, ans = n + 1;
        for (left = 0; left < n; left++)
        {
            while (right + 1 < n and window < s)
            {
                right++; 
                window += nums[right]; 
            }
            if (window >= s) ans = min(ans, right - left + 1); 
            window -= nums[left]; 
        }
        return (ans == n + 1) ? 0 : ans; 
    }
};
```