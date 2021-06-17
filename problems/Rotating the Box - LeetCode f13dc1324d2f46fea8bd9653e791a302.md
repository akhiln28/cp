# Rotating the Box - LeetCode

Created Time: May 19, 2021 10:05 AM
Last edited time: May 31, 2021 9:50 AM
Pattern: https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Rearrange-aa0f5fc6b69d46c2b136548102c6f0d4
Points: 1500
Source: https://leetcode.com/problems/rotating-the-box/
Status: ok

# Problem Statement

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

![Rotating%20the%20Box%20-%20LeetCode%20f13dc1324d2f46fea8bd9653e791a302/rotatingtheboxleetcodewithstones.png](rotatingtheboxleetcodewithstones.png)

```
Input: box = [["#",".","#"]]
Output: [["."],
         ["#"],
         ["#"]]
```

**Example 2:**

![Rotating%20the%20Box%20-%20LeetCode%20f13dc1324d2f46fea8bd9653e791a302/rotatingtheboxleetcode2withstones.png](rotatingtheboxleetcode2withstones.png)

```
Input: box = [["#",".","*","."],
              ["#","#","*","."]]
Output: [["#","."],
         ["#","#"],
         ["*","*"],
         [".","."]]
```

**Example 3:**

![Rotating%20the%20Box%20-%20LeetCode%20f13dc1324d2f46fea8bd9653e791a302/rotatingtheboxleetcode3withstone.png](rotatingtheboxleetcode3withstone.png)

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