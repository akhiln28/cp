---
Created Time: Jan 07, 2021 1:37 PM
Last edited time: May 11, 2021 8:58 AM
Points: 1800
Source: https://leetcode.com/problems/largest-rectangle-in-histogram/
Status: done
Tags: standard
---

# Largest Rectangle in Histogram - LeetCode

Given *n* non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
![Largest%20Rectangle%20in%20Histogram%20-%20LeetCode%20edf49e4b65e348caa0c4d68c3f31c3b5/histogram.png](Largest%20Rectangle%20in%20Histogram%20-%20LeetCode%20edf49e4b65e348caa0c4d68c3f31c3b5/histogram.png)
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3] .
The largest rectangle is shown in the shaded area, which has area = `10` unit.
**Example:**
```
Input: [2,1,5,6,2,3]
Output: 10
```
**Example 1:**
![Largest%20Rectangle%20in%20Histogram%20-%20LeetCode%20edf49e4b65e348caa0c4d68c3f31c3b5/histogram.jpg](Largest%20Rectangle%20in%20Histogram%20-%20LeetCode%20edf49e4b65e348caa0c4d68c3f31c3b5/histogram.jpg)
```
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
```
**Example 2:**
![Largest%20Rectangle%20in%20Histogram%20-%20LeetCode%20edf49e4b65e348caa0c4d68c3f31c3b5/histogram-1.jpg](Largest%20Rectangle%20in%20Histogram%20-%20LeetCode%20edf49e4b65e348caa0c4d68c3f31c3b5/histogram-1.jpg)
```
Input: heights = [2,4]
Output: 4
```
**Constraints:**
- `1 <= heights.length <= 10^5`
- `0 <= heights[i] <= 10^4`
---
[https://youtu.be/SSpnMY5TrTw?t=1116](https://youtu.be/SSpnMY5TrTw?t=1116)
consider the consider the following algorithm by errich
```cpp
void rec(L, R)
	min = find_min(L,.., R) // can be done in O(1) using sparse table
	ans = max(ans, min * (R - L + 1))
	rec(L, pos_min - 1)
	rec(pos_min + 1, R)
```
I did the following. 
1. for each element, find previous smaller and next smaller. 
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left_min(heights.size(), -1), right_min(heights.size(), heights.size());
        stack<int> st, st1;
        for (int i = 0; i < heights.size(); i++)
        {
            if (st.empty())
            {
                st.push(i);
            }
            else if (heights[i] < heights[st.top()])
            {
                while (!st.empty() && heights[i] < heights[st.top()])
                {
                    right_min[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
            else st.push(i);
        }
        for (int i = 0; i < heights.size(); i++)
        {
            if (st1.empty())
            {
                st1.push(i);
            }
            else if (heights[i] > heights[st1.top()])
            {
                left_min[i] = st1.top();
                st1.push(i);
            }
            else if (heights[i] <= heights[st1.top()])
            {
                while (!st1.empty() && heights[i] <= heights[st1.top()])
                {
                    st1.pop();
                }
                if (!st1.empty())
                {
                    left_min[i] = st1.top();
                }
                st1.push(i);
            }
        }
        int ans = 0; 
        for (int i = 0; i < heights.size(); i++)
        {
            ans = max(ans, heights[i] * (right_min[i] - left_min[i] - 1));
        }
        return ans;
    }
};
```
Patterns: [patterns/Greedy](patterns/Greedy.md)[Number%20Theory](Number%20Theory.md)[Stack](Stack.md)