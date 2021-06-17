# Cherry Pickup - LeetCode

Created Time: Jan 01, 2021 3:45 PM
Do Date: Jan 01, 2021
Last edited time: Mar 01, 2021 8:47 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee
Points: 2100
Pomos (25 mins): 1
Related To: Food%20delivery%20to%20tech%20park%209a4169968d2d4e1bb1e2badb2f1d70cb.md
Source: https://leetcode.com/problems/cherry-pickup/
Status: waiting
Tags: new

You are given an `n x n` `grid` representing a field of cherries, each cell is one of three possible integers.

- `0` means the cell is empty, so you can pass through,
- `1` means the cell contains a cherry that you can pick up and pass through, or
- `1` means the cell contains a thorn that blocks your way.

Return *the maximum number of cherries you can collect by following the rules below*:

- Starting at the position `(0, 0)` and reaching `(n - 1, n - 1)` by moving right or down through valid path cells (cells with value `0` or `1`).
- After reaching `(n - 1, n - 1)`, returning to `(0, 0)` by moving left or up through valid path cells.
- When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell `0`.
- If there is no valid path between `(0, 0)` and `(n - 1, n - 1)`, then no cherries can be collected.

**Example 1:**

![Cherry%20Pickup%20-%20LeetCode%20a73c725479264cd2a914d52d1a898d4b/grid.jpg](grid.jpg)

```
Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
Output: 5
Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
Then, the player went left, up, up, left to return home, picking up one more cherry.
The total number of cherries picked up is 5, and this is the maximum possible.

```

**Example 2:**

```
Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
Output: 0

```

**Constraints:**

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 50`
- `grid[i][j]` is `1`, `0`, or `1`.
- `grid[0][0] != -1`
- `grid[n - 1][n - 1] != -1`

---

Greedy does not work. Consider the following example 

```cpp
1 1 1 0 0
0 0 1 0 1
1 0 1 0 0
0 0 1 0 0
0 0 1 1 1
```