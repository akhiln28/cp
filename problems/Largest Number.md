---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 26, 2020
Last edited time: May 11, 2021 9:07 AM
Points: 1500
Source: https://leetcode.com/problems/largest-number/
Status: done
Tags: custom sort
---

# Largest Number

Given a list of non-negative integers `nums`, arrange them such that they form the largest number.
**Note:** The result may be very large, so you need to return a string instead of an integer.
**Example 1:**
```
Input: nums = [10,2]
Output: "210"
```
**Example 2:**
```
Input: nums = [3,30,34,5,9]
Output: "9534330"
```
**Example 3:**
```
Input: nums = [1]
Output: "1"
```
**Example 4:**
```
Input: nums = [10]
Output: "10"
```
**Constraints:**
- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 109`
---
Sort the strings based on a custom comparator. 
```cpp
class Solution {
public:
    static bool comp(string str1, string str2)
    {
        int i = 0;  
        if (str1.length() == 0 or str2.length() == 0) return false; 
        while (i < str1.length() and i < str2.length())
        {
            if (str1[i] > str2[i]) return true; 
            else if (str1[i] < str2[i]) return false; 
            else i++; 
        }
        if (i == str1.length() and i < str2.length())
        {
            return comp(str1, str2.substr(i)); 
        }
        if (i == str2.length() and i < str1.length())
        {
            return comp(str1.substr(i), str2); 
        }
        return true; 
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> strs(nums.size());    
        for (int i = 0; i < nums.size(); i++)
        {
            strs[i] = to_string(nums[i]); 
        }
        sort(strs.begin(), strs.end(), comp); 
        string ans = ""; 
        for (int i = 0; i < strs.size(); i++)
        {
            ans += strs[i]; 
        }
        int i = 0; 
        while (ans[i] == '0' and i < ans.length()) i++;
        if (i == ans.length()) return "0"; 
        return ans.substr(i); 
    }
};
```
Patterns: [Array](Array.md)[patterns/Greedy](patterns/Greedy.md)[String%20Sort](String%20Sort.md)