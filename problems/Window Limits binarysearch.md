---
Created Time: Mar 06, 2021 5:46 PM
Do Date: Mar 06, 2021
Last edited time: Mar 06, 2021 5:46 PM
Points: 1600
Pomos (25 mins): 2
Source: https://binarysearch.com/problems/Window-Limits
Status: done
---

# Window Limits | binarysearch

You are given a list of integers `nums` and integers `window` and `limit`. Return whether `abs(nums[i] - nums[j]) ≤ limit` for every `i, j` such that `abs(i - j) < window`.
**Constraints**
- `1 ≤ n ≤ 100,000` where `n` is the length of `nums`
- `1 ≤ window ≤ n`
- `0 ≤ limit < 2 ** 31`
### **Output**
### **Explanation**
Every number within a window of size `2` has pair differences of at most `4` (from `3` and `7`).
### **Output**
### **Explanation**
Within a window size of `3` we have `abs(1 - 7) > 4`, so this is above the limit.
def solve(self, nums, window, limit):
Patterns: [Sliding%20Window](Sliding%20Window.md)