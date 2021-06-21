---
Created Time: Feb 14, 2021 4:53 PM
Do Date: Feb 15, 2021
Last edited time: May 11, 2021 9:09 AM
Points: 2000
Pomos (25 mins): 1
Source: https://leetcode.com/problems/construct-target-array-with-multiple-sums/
Status: done
Tags: like
---

# Construct Target Array With Multiple Sums - LeetCode

Given an array of integers `target`. From a starting array, `A` consisting of all 1's, you may perform the following procedure :
- let `x` be the sum of all elements currently in your array.
- choose index `i`, such that `0 <= i < target.size` and set the value of `A` at index `i` to `x`.
- You may repeat this procedure as many times as needed.
Return True if it is possible to construct the `target` array from `A` otherwise return False.
**Example 1:**
```
Input: target = [9,3,5]
Output: true
Explanation: Start with [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
```
**Example 2:**
```
Input: target = [1,1,1,2]
Output: false
Explanation: Impossible to create target array from [1,1,1,1].
```
**Example 3:**
```
Input: target = [8,5]
Output: true
```
**Constraints:**
- `N == target.length`
- `1 <= target.length <= 5 * 10^4`
- `1 <= target[i] <= 10^9`
---
In each iteration, take the largest element and subtract the sum of the remaining elements and insert again. The final array should contain all ones. 
```cpp
class Solution {
public:
    bool isPossible(vector<int>& target) {
        set<int> my_set; 
        int n = target.size(); 
        if (n == 1) return target[0] == 1; 
        long long sum = 0; 
        for (int i = 0; i < n; i++)
        {
            my_set.insert(target[i]); 
            sum += target[i]; 
        }
        while(*prev(my_set.end()) != 1)
        {
						// largest element
            long long end = *prev(my_set.end()); 
            my_set.erase(prev(my_set.end()));
            sum -= end; 
            if (end <= sum) return false; 
            
            end = end % sum; 
            if (!end) end = sum; 
            my_set.insert(end); 
            sum += end; 
        }
        return true; 
    }
};
```
Patterns: [Array](Array.md)[Simulation](Simulation.md)