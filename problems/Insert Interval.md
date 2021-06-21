---
Created Time: Dec 22, 2020 11:48 AM
Do Date: Dec 22, 2020
Last edited time: Mar 04, 2021 8:12 AM
Source: https://leetcode.com/problems/insert-interval/
Status: done
---

# Insert Interval

Given a list of non-overlapping intervals sorted by their start time, **insert a given interval at the correct position** and merge all necessary intervals to produce a list that has only mutually exclusive intervals.
**Example 1:**
```
Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,6]
Output: [[1,3], [4,7], [8,12]]
Explanation: After insertion, since [4,6] overlaps with [5,7], we merged them into one [4,7].
```
**Example 2:**
```
Input: Intervals=[[1,3], [5,7], [8,12]], New Interval=[4,10]
Output: [[1,3], [4,12]]
Explanation: After insertion, since [4,10] overlaps with [5,7] & [8,12], we merged them into [4,12].
```
**Example 3:**
```
Input: Intervals=[[2,3],[5,7]], New Interval=[1,4]
Output: [[1,4], [5,7]]
Explanation: After insertion, since [1,4] overlaps with [2,3], we merged them into one [1,4].
```
---
I was thinking about a method which does not use extra storage, but the below method looks good. 
```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans; 
        int i = 0, n = intervals.size(); 
				// intervals before
        while (i < n and intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]); 
            i++; 
        }
				// intervals intersecting
        while (i < n and intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]); 
            i++; 
        }
				// merged interval
        ans.push_back(newInterval); 
				// intervals after
        while (i < n) 
        {
            ans.push_back(intervals[i]); 
            i++; 
        }
        return ans; 
    }
};
```
Patterns: [Intervals](Intervals.md)