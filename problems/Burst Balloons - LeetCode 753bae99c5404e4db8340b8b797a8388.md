# Burst Balloons - LeetCode

Created Time: Jan 10, 2021 8:49 AM
Do Date: Jan 12, 2021
Last edited time: Mar 01, 2021 8:48 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee
Points: 2000
Pomos (25 mins): 1
Relates: Minimum%20Cost%20to%20Merge%20Stones%20-%20LeetCode%204b145a50da1c42e5b981de623f1baae4.md
Source: https://leetcode.com/problems/burst-balloons/
Status: done
Tags: O(n^3)

You are given `n` balloons, indexed from `0` to `n - 1`. Each balloon is painted with a number on it represented by an array `nums`. You are asked to burst all the balloons.

If you burst the `ith` balloon, you will get `nums[i - 1] * nums[i] * nums[i + 1]` coins. If `i - 1` or `i + 1` goes out of bounds of the array, then treat it as if there is a balloon with a `1` painted on it.

Return *the maximum coins you can collect by bursting the balloons wisely*.

**Example 1:**

```
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
```

**Example 2:**

```
Input: nums = [1,5]
Output: 10
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 500`
- `0 <= nums[i] <= 100`

---

```cpp
class Solution {
public:
    vector<vector<int>> mem;
    int recur(vector<int>& nums,int i, int j)
    {
        if (mem[i][j] != -1) return mem[i][j]; 
        if (j <= i + 1) 
        {
            mem[i][j] = 0; 
            return mem[i][j]; 
        }
        if (j == i + 2)
        {
            mem[i][j] = nums[i] * nums[i + 1] * nums[i + 2]; 
            return mem[i][j]; 
        }
        int ans = 0; 
        for (int k = i + 1; k <= j - 1; k++)
        {
            int cur = nums[k] * nums[i] * nums[j] + recur(nums, i, k) + recur(nums, k, j); 
            ans = max(ans, cur); 
        }
        mem[i][j] = ans;  
        return ans; 
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size(); 
        nums.insert(nums.begin(), 1); 
        nums.push_back(1); 
        mem.resize(n + 2, vector<int> (n + 2, -1)); 
        return recur(nums, 0, n + 1); 
    }
};
```