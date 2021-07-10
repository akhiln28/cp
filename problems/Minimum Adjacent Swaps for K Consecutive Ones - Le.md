---
Created Time: Jan 07, 2021 2:03 PM
Do Date: Jan 07, 2021
Last edited time: May 11, 2021 9:00 AM
Points: 2000
Related To: Minimum%20distance%20to%20travel%20for%20all%20to%20meet%20in%201D%20a34b0991298444349a7548d5f9587383.md
Source: https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/
Status: done
---

# Minimum Adjacent Swaps for K Consecutive Ones - LeetCode

You are given an integer array, `nums`, and an integer `k`. `nums` comprises of only `0`'s and `1`'s. In one move, you can choose two **adjacent** indices and swap their values.
Return *the **minimum** number of moves required so that* `nums` *has* `k` ***consecutive*** `1`*'s*.
**Example 1:**
```
Input: nums = [1,0,0,1,0,1], k = 2
Output: 1
Explanation: In 1 move, nums could be [1,0,0,0,1,1] and have 2 consecutive 1's.
```
**Example 2:**
```
Input: nums = [1,0,0,0,0,0,1,1], k = 3
Output: 5
Explanation: In 5 moves, the leftmost 1 can be shifted right until nums = [0,0,0,0,0,1,1,1].
```
**Example 3:**
```
Input: nums = [1,1,0,1], k = 2
Output: 0
Explanation: nums already has 2 consecutive 1's.
```
**Constraints:**
- `1 <= nums.length <= 10^5`
- `nums[i]` is `0` or `1`.
- `1 <= k <= sum(nums)`
---
[https://youtu.be/SSpnMY5TrTw?t=4872](https://youtu.be/SSpnMY5TrTw?t=4872)
```cpp
class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> ones;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]) ones.push_back(i);
        }
        int n = ones.size();
        vector<long long> pref(n); pref[0] = ones[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + ones[i];

        long long ans = 1e18;
        auto cum = [&](int i, int j){
            if (j < i) return 0LL;
            if (i == 0) return pref[j];
            return pref[j] - pref[i - 1];
        };
        for (int start = 0; start <= n - k; start++)
        {
            int end = start + k - 1;
            int mid = start + k/2;
            long long countl = mid - start, countr = end - mid;
            long long temp = (ones[mid] * countl - cum(start, mid - 1) + cum(mid + 1, end) - ones[mid] * countr);
            temp -= (countl * (countl + 1)/2 + countr * (countr + 1)/2);
            ans = min(ans, temp);
        }
        return ans;
    }
};
```
Patterns: [patterns/Greedy](patterns/Greedy.md)[[Sliding Window]]