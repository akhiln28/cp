---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Jan 15, 2021
Last edited time: May 11, 2021 9:04 AM
Points: 1500
Related To: Maximum%20Sum%20Subarray%200909dcbaaf4a4f6690d10dcf46771e20.md
Status: ok
---

# Maximum Product Subarray

Given an integer array `nums`, find the contiguous subarray within an array (containing at least one number) which has the largest product.
**Example 1:**
```
Input: [2,3,-2,4]
Output: 6Explanation: [2,3] has the largest product 6.
```
**Example 2:**
```
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
```
---
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxe = nums[0], mine = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int t = mine;
            mine = min({nums[i], mine * nums[i], maxe * nums[i]});
            maxe = max({nums[i], t * nums[i], maxe * nums[i]});
            ans = max(ans, maxe);
        }
        return ans;
    }
};
```
Patterns: [Array](Array.md)[patterns/Greedy](patterns/Greedy.md)[Traversal](Traversal.md)