# Subarray Product Less Than K

Created Time: Dec 01, 2020 11:55 PM
Do Date: Feb 24, 2021
Last edited time: Feb 24, 2021 9:18 AM
Pattern: https://www.notion.so/Sliding-Window-57edd445fc8d49ac98bcd1076bcdd3aa
Points: 1500
Pomos (25 mins): 2
Source: https://leetcode.com/problems/subarray-product-less-than-k
Status: done

Your are given an array of positive integers `nums`.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than `k`.

**Example 1:**

```
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

```

**Note:**

- `0 < nums.length <= 50000`.
- `0 < nums[i] < 1000`.
- `0 <= k < 10^6`.

```cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0; 
        long long right = 0, left = 0, prod = 1, ans = 0; 
				// for each right -> find the smallest possible left
        for (right = 0; right < nums.size(); right++)
        {
            prod *= nums[right]; 
            while (prod >= k and left <= right) prod /= nums[left], left++;
            ans += right - left + 1; 
        }
        return ans; 
    }
};
```