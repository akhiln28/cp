---
Created Time: Dec 08, 2020 10:01 PM
Do Date: Dec 08, 2020
Last edited time: May 11, 2021 9:12 AM
Points: 1500
Problem Statement: Given an array in which each element occurs exactly 3 times except for one element. Find that element in O(1) space?
Source: binarysearch.com
Status: done
Tags: puzzle
---

# Lone Integer

Given an array in which each element occurs exactly 3 times except for one element. Find that element in O(1) space?
---
- my solution
    **Brute force method**: We can simply do **sorting** and then find the element which is not equal to the neighbours. 
    ```cpp
    int solve(vector<int>& nums) {
        vector<int> v(31); 
        for (int j = 0; j < 31; j++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                v[j] += (1 & (nums[i] >> j)); 
            }
        }
        
        int ans = 0; 
        for (int i = 0; i < 31; i++)
        {
            ans += (v[i] % 3) * (1 << i);
        }
        return ans; 
    }
    ```
There are 31 bits. For each position find the total number of ones in that position. The ith position of the unique element is the (number of ones in that position) % 3. 
### Complexity
Time: O(n)
Space: O(1)
Patterns: [Custom%20datastructures](Custom%20datastructures.md)[Bits](Bits.md)