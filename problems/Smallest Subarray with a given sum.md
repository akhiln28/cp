---
Created Time: Dec 20, 2020 6:34 PM
Last edited time: May 11, 2021 9:00 AM
Points: 1500
Status: done
---

# Smallest Subarray with a given sum

Given an array of positive numbers and a positive number ‘S,’ find the length of the **smallest contiguous subarray whose sum is greater than or equal to ‘S’**. Return 0 if no such subarray exists.
**Example 1:**
```
Input: [2, 1, 5, 2, 3, 2], S=7 
Output: 2
Explanation: The smallest subarray with a sum great than or equal to '7' is [5, 2].
```
**Example 2:**
```
Input: [2, 1, 5, 2, 8], S=7 
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].
```
**Example 3:**
```
Input: [3, 4, 1, 1, 6], S=8 
Output: 3
Explanation: Smallest subarrays with a sum greater than or equal to '8' are [3, 4, 1] or [1, 1, 6].
```
---
maintain two pointers, start = end = 0.
```cpp
using namespace std;
#include <iostream>
#include <climits>
#include <limits>
#include <vector>
class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int n = arr.size();
    int start = 0, end = 0;
    int sum = arr[start];
    int ans = INT_MAX;
    while (start < n)
    {
        while (end + 1 < n and sum < S)
        {
            end++;
            sum += arr[end];
        }
        while (sum - arr[start] >= S)
        {
            sum -= arr[start];
            start++;
        }
        if (sum >= S) ans = min(ans, end - start + 1);
        sum -= arr[start], start++;
    }
    return (ans != INT_MAX ? ans : 0);
  }
};
```
Patterns: [patterns/Greedy](patterns/Greedy.md)[[Sliding Window]]