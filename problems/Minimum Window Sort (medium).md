---
Created Time: Dec 22, 2020 10:49 AM
Do Date: Dec 22, 2020
Last edited time: Mar 01, 2021 3:43 PM
Points: 1600
Pomos (25 mins): 1
Source: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
Status: done
---

# Minimum Window Sort (medium)

Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array.
**Example 1:**
```
Input: [1, 2, 5, 3, 7, 10, 9, 12]
Output: 5
Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted
```
**Example 2:**
```
Input: [1, 3, 2, 0, -1, 7, 10]
Output: 5
Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the whole array sorted
```
**Example 3:**
```
Input: [1, 2, 3]
Output: 0
Explanation: The array is already sorted
```
---
I think it can easily be solved using prefix max and suffix min arrays. 
1. From the beginning and end of the array, find the first elements that are out of the sorting order. The two elements will be our candidate subarray.
2. Find the maximum and minimum of this subarray.
3. Extend the subarray from beginning to include any number which is bigger than the minimum of the subarray.
4. Similarly, extend the subarray from the end to include any number which is smaller than the maximum of the subarray.
---
```cpp
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1; 
        
        while (i + 1 < n and nums[i] <= nums[i + 1]) i++;
        while (j - 1 >= 0 and nums[j] >= nums[j - 1]) j--;
        
        if (i == n - 1) return 0; 
        
       
        int mine = *min_element(nums.begin() + i, nums.begin() + j + 1); 
        int maxe = *max_element(nums.begin() + i, nums.begin() + j + 1); 
                
        while (i >= 0 and nums[i] > mine) i--; 
        while (j < n and nums[j] < maxe) j++; 
        
        return j - i - 1; 
    }
};
```
Patterns: [Two%20Pointers](Two%20Pointers.md)[patterns/Greedy](patterns/Greedy.md)