---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Feb 25, 2021
Last edited time: Feb 25, 2021 8:02 AM
Points: 1500
Pomos (25 mins): 1
Relates: Jump%20Game%20VI%20-%20LeetCode%2054152425686941faa9de152203d89289.md
Status: done
---

# Jump Game

Given an array of non-negative integers `nums`, you are initially positioned at the **first index** of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
**Example 1:**
```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```
**Example 2:**
```
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
```
**Constraints:**
- `1 <= nums.length <= 3 * 104`
- `0 <= nums[i] <= 105`
---
DP approach
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[nums.size() - 1] = true;
        vector<int> cum(nums.size() + 1, 0);
        cum[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            cum[i] = cum[i + 1];
						// i can reach upto i + nums[i], so check if atleast one of them is true
            int last = min((int)nums.size(), i + nums[i] + 1);
            if (cum[i + 1] - cum[last]) dp[i] = true, cum[i] += 1;
        }
        return dp[0];
    }
};
```
Greedy Approach
```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastPos = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (lastPos >= i and nums[i] + i > lastPos) lastPos = i + nums[i];  
        }
        return lastPos >= nums.size() - 1; 
    }
};
```
Patterns: [Array](Array.md)[Dp](Dp.md)[patterns/Greedy](patterns/Greedy.md)