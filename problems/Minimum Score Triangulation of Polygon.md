---
Created Time: Dec 27, 2020 5:11 PM
Last edited time: Mar 01, 2021 8:48 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee
Points: 1600
Pomos (25 mins): 1
Source: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
Status: waiting
---
# Minimum Score Triangulation of Polygon - LeetCode

Given `N`, consider a convex `N`-sided polygon with vertices labelled `A[0], A[i], ..., A[N-1]` in clockwise order.

Suppose you triangulate the polygon into `N-2` triangles. For each triangle, the value of that triangle is the **product** of the labels of the vertices, and the *total score* of the triangulation is the sum of these values over all `N-2` triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.

**Example 1:**

```
Input: [1,2,3]
Output: 6
Explanation: The polygon is already triangulated, and the score of the only triangle is 6.

```

**Example 2:**

![Minimum%20Score%20Triangulation%20of%20Polygon%20-%20LeetCode%20bec8990d651945e3917e4a6f8b59a02c/minimum-score-triangulation-of-polygon-1.png](minimum-score-triangulation-of-polygon-1.png)

```
Input: [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.  The minimum score is 144.

```

**Example 3:**

```
Input: [1,3,1,4,1,5]
Output: 13
Explanation: The minimum score triangulation has score 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.

```

**Note:**

1. `3 <= A.length <= 50`
2. `1 <= A[i] <= 100`

---

This solution is very good. [https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/286753/C%2B%2B-with-picture](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/discuss/286753/C%2B%2B-with-picture)