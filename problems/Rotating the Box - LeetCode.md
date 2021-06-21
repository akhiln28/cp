---
Created Time: May 19, 2021 10:05 AM
Last edited time: May 31, 2021 9:50 AM
Points: 1500
Source: https://leetcode.com/problems/rotating-the-box/
Status: ok
---

# Rotating the Box - LeetCode

You are given an `m x n` matrix of characters `box` representing a side-view of a box. Each cell of the box is one of the following:
- A stone `'#'`
- A stationary obstacle `'*'`
- Empty `'.'`
The box is rotated **90 degrees clockwise**, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity **does not** affect the obstacles' positions, and the inertia from the box's rotation **does not** affect the stones' horizontal positions.
It is **guaranteed** that each stone in `box` rests on an obstacle, another stone, or the bottom of the box.
Return *an* `n x m` *matrix representing the box after the rotation described above*.
### Constraints
- `m == box.length`
- `n == box[i].length`
- `1 <= m, n <= 500`
- `box[i][j]` is either `'#'`, `'*'`, or `'.'`.
### **Examples**
**Example 1:**
![Rotating%20the%20Box%20-%20LeetCode%20f13dc1324d2f46fea8bd9653e791a302/rotatingtheboxleetcodewithstones.png](Rotating%20the%20Box%20-%20LeetCode%20f13dc1324d2f46fea8bd9653e791a302/rotatingtheboxleetcodewithstones.png)
```
Input: box = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]
```
**Example 2:**
![Rotating%20the%20Box%20-%20LeetCode%20f13dc1324d2f46fea8bd9653e791a302/rotatingtheboxleetcode2withstones.png](Rotating%20the%20Box%20-%20LeetCode%20f13dc1324d2f46fea8bd9653e791a302/rotatingtheboxleetcode2withstones.png)
```
Input: box = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]
```
**Example 3:**
![Rotating%20the%20Box%20-%20LeetCode%20f13dc1324d2f46fea8bd9653e791a302/rotatingtheboxleetcode3withstone.png](Rotating%20the%20Box%20-%20LeetCode%20f13dc1324d2f46fea8bd9653e791a302/rotatingtheboxleetcode3withstone.png)
```
Input: box = [["#","#","*",".","*","."],
              ["#","#","#","*",".","."],
              ["#","#","#",".","#","."]]
Output: [[".","#","#"],
         [".","#","#"],
         ["#","#","*"],
         ["#","*","."],
         ["#",".","*"],
         ["#",".","."]]
```
---
## Algorithm
```python
```
### Explanation
## Solution
```jsx
```
Patterns: [patterns/Greedy](patterns/Greedy.md)[Array](Array.md)[Rearrange](Rearrange.md)