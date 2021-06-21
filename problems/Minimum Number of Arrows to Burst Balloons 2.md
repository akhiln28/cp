---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 18, 2020
Last edited time: Mar 04, 2021 8:13 AM
Points: 1600
Related To: Activity%20Selection%20Problem%20b98e4f278b8745d182d05ec2bebc05ef.md
Status: done
Tags: interval
---

# Minimum Number of Arrows to Burst Balloons

There are some spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. The start is always smaller than the end.
An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with `xstart` and `xend` bursts by an arrow shot at `x` if `xstart ≤ x ≤ xend`. There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.
Given an array `points` where `points[i] = [xstart, xend]`, return *the minimum number of arrows that must be shot to burst all balloons*.
**Example 1:**
```
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).
```
**Example 2:**
```
Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
```
**Example 3:**
```
Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
```
**Example 4:**
```
Input: points = [[1,2]]
Output: 1
```
**Example 5:**
```
Input: points = [[2,3],[2,3]]
Output: 1
```
**Constraints:**
- `0 <= points.length <= 104`
- `points[i].length == 2`
- `231 <= xstart < xend <= 231 - 1`
---
Sort the intervals based on the starting times merge intervals having intersection. 
```cpp
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](auto p1, auto p2){
            if (p1[0] < p2[0]) return true; 
            if (p1[0] > p2[0]) return false;
            return p1[1] > p2[1]; 
        });
        vector<vector<int>> balloons; 
        for (int i = 0; i < points.size(); i++)
        {
            if (balloons.size() == 0) balloons.push_back(points[i]); 
            else
            {
                auto back = balloons.back(); 
                if (back[1] >= points[i][0])
                {
                    balloons.pop_back(); 
                    balloons.push_back({points[i][0], min(points[i][1], back[1])});
                }
                else balloons.push_back(points[i]); 
            }
        }
        return balloons.size(); 
    }
};
```
Patterns: [Two%20Pointers](Two%20Pointers.md)[patterns/Greedy](patterns/Greedy.md)[Intervals](Intervals.md)