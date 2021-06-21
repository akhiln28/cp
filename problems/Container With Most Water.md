---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Jan 15, 2021
Last edited time: Mar 01, 2021 3:43 PM
Points: 1500
Status: ok
Tags: new
---

# Container With Most Water

Given `n` non-negative integers `a1, a2, ..., an` , where each represents a point at coordinate `(i, ai)`. `n` vertical lines are drawn such that the two endpoints of the line `i` is at `(i, ai)` and `(i, 0)`. Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
**Notice** that you may not slant the container.
**Example 1:**
![https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)
```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```
**Example 2:**
```
Input: height = [1,1]
Output: 
```
**Example 3:**
```
Input: height = [4,3,2,1,4]
Output: 16
```
**Example 4:**
```
Input: height = [1,2,1]
Output: 2
```
**Constraints:**
- `n == height.length`
- `2 <= n <= 3 * 10^4`
- `0 <= height[i] <= 3 * 10^4`
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int p1 = 0, p2 = height.size() - 1;
        while (p1 <= p2)
        {
            ans = max(ans, (p2 - p1) * min(height[p1], height[p2]));
            if (height[p1] < height[p2]) p1++; 
            else p2--;
        }
        return ans;
    }
};
```
Patterns: [Two%20Pointers](Two%20Pointers.md)[patterns/Greedy](patterns/Greedy.md)