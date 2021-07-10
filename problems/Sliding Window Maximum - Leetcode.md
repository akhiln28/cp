---
Created Time: Feb 11, 2021 8:41 AM
Do Date: Feb 11, 2021
Last edited time: May 11, 2021 9:00 AM
Points: 2000
Pomos (25 mins): 1
Source: https://leetcode.com/problems/sliding-window-maximum/
Status: done
Tags: new, standard
---

# Sliding Window Maximum - Leetcode

You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.
Return *the max sliding window*.
**Example 1:**
```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```
**Example 2:**
```
Input: nums = [1], k = 1
Output: [1]
```
**Example 3:**
```
Input: nums = [1,-1], k = 1
Output: [1,-1]
```
**Example 4:**
```
Input: nums = [9,11], k = 2
Output: [11]
```
**Example 5:**
```
Input: nums = [4,-2], k = 2
Output: [4]
```
**Constraints:**
- `1 <= nums.length <= 10^5`
- `10^4 <= nums[i] <= 10^4`
- `1 <= k <= nums.length`
---
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
				// the elements in the window are always in decreasing order
        deque<int> window;
        for (int i = 0; i < nums.size(); i++)
        {
            while (window.size() and window.front() < i - k + 1)
								window.pop_front();
            while (window.size() and nums[window.back()] < nums[i])
								window.pop_back();
            window.push_back(i);
            if (i >= k - 1) ans.push_back(nums[window.front()]);
        }
        return ans;
    }
};
```
```jsx
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int, greater<int>> window;
        for (int i = 0; i < k; i++)
        {
            window.insert(nums[i]);
        }
        ans.push_back(*window.begin());
        for (int i = k; i < nums.size(); i++)
        {
            window.erase(window.find(nums[i - k]));
            window.insert(nums[i]);
            ans.push_back(*window.begin());
        }
        return ans;
    }
};
```
Patterns: [patterns/Greedy](patterns/Greedy.md)[[Sliding Window]]