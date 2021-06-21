---
Created Time: Mar 13, 2021 9:02 PM
Do Date: Mar 15, 2021
Last edited time: Mar 15, 2021 9:17 AM
Points: 1700
Pomos (25 mins): 2
Related To: Trapping%20Rain%20Water%200be342871bde41e39519ca7ecf0096b4.md
Source: https://leetcode.com/problems/maximum-score-of-a-good-subarray/
Status: ok
---

# Maximum Score of a Good Subarray - Leetcode

You are given an array of integers `nums` **(0-indexed)** and an integer `k`.
The **score** of a subarray `(i, j)` is defined as `min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1)`. A **good** subarray is a subarray where `i <= k <= j`.
Return *the maximum possible **score** of a **good** subarray.*
**Example 1:**
```
Input: nums = [1,4,3,7,4,5], k = 3
Output: 15
Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15.
```
**Example 2:**
```
Input: nums = [5,5,4,5,4,1,1,1], k = 0
Output: 20
Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
```
**Constraints:**
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 2 * 10^4`
- `0 <= k < nums.length`
---
```cpp
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k, j = k; 
        int n = nums.size(); 
        int ans = nums[k], mine = nums[k];
        while (i > 0 or j < n - 1)
        {
            if ((i ? nums[i - 1] : 0) > (j < n - 1 ? nums[j + 1] : 0))
            {
                i--;
                mine = min(mine, nums[i]);
            }
            else 
            {
                j++;
                mine = min(mine, nums[j]);
            }
            ans = max(ans, (j - i + 1) * mine);
        }
        return ans; 
    }
};
```
Patterns: [Two%20Pointers](Two%20Pointers.md)[patterns/Greedy](patterns/Greedy.md)