---
Created Time: Feb 01, 2021 8:18 AM
Do Date: Feb 01, 2021
Last edited time: May 11, 2021 9:12 AM
Points: 1500
Pomos (25 mins): 1
Source: https://leetcode.com/problems/counting-bits/
Status: done
---

# Counting Bits - LeetCode

Given a non negative integer number **num**. For every numbers **i** in the range **0 ≤ i ≤ num** calculate the number of 1's in their binary representation and return them as an array.
**Example 1:**
```
Input: 2
Output: [0,1,1]
```
**Example 2:**
```
Input: 5
Output: [0,1,1,2,1,2]
```
**Follow up:**
- It is very easy to come up with a solution with run time **O(n*sizeof(integer))**. But can you do it in linear time **O(n)** /possibly in a single pass?
- Space complexity should be **O(n)**.
- Can you do it like a boss? Do it without using any builtin function like **__builtin_popcount** in c++ or in any other language.
---
The number of count bits in each iteration (1 iteration → all numbers with same number of digits) has a pattern. 
```cpp
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> prev{1};
        if (num == 0) return {0}; 
        vector<int> ans{0, 1}; 
        while (ans.size() < num + 1)
        {
            int s = prev.size(); 
            for (int i = 0; i < s; i++) prev.push_back(prev[i] + 1);
            for (int i = 0; i < prev.size(); i++)
            {
                if (ans.size() == num + 1) break; 
                ans.push_back(prev[i]); 
            }
        }
        return ans; 
    }
};
```
Patterns: [Custom%20datastructures](Custom%20datastructures.md)[Bits](Bits.md)