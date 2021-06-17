# Find the Most Competitive Subsequence - Leetcode

Created Time: Feb 16, 2021 8:52 AM
Do Date: Feb 16, 2021
Last edited time: May 11, 2021 8:58 AM
Pattern: https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Number-Theory-02e26369bab8475881b8a6a9d7b33ca9, https://www.notion.so/Stack-67154e5bf7324feab7a8a732f028898b
Points: 1500
Pomos (25 mins): 1
Related To: Remove%20K%20Digits%20-%20LeetCode%20d9636684c1a749f08543542303c03063.md
Source: https://leetcode.com/problems/find-the-most-competitive-subsequence/
Status: done

Given an integer array `nums` and a positive integer `k`, return *the most **competitive** subsequence of* `nums` *of size* `k`.

An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence `a` is more **competitive** than a subsequence `b` (of the same length) if in the first position where `a` and `b` differ, subsequence `a` has a number **less** than the corresponding number in `b`. For example, `[1,3,4]` is more competitive than `[1,3,5]` because the first position they differ is at the final number, and `4` is less than `5`.

**Example 1:**

```
Input: nums = [3,5,2,6], k = 2
Output: [2,6]
Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
```

**Example 2:**

```
Input: nums = [2,4,3,3,5,4,9,6], k = 4
Output: [2,3,3,4]
```

**Constraints:**

- `1 <= nums.length <= 105`
- `0 <= nums[i] <= 109`
- `1 <= k <= nums.length`

---

Smallest subsequence.

```cpp
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size(); 
        k = n - k; 
        vector<int> ans; 
        for (int i = 0; i < n; i++)
        {
            while (ans.size() and ans.back() > nums[i] and k) k--, ans.pop_back();
            ans.push_back(nums[i]);
        }
        while (k) k--, ans.pop_back();
        return ans; 
    }
};
```