---
Created Time: Feb 20, 2021 7:39 AM
Do Date: Feb 20, 2021
Last edited time: Feb 22, 2021 9:57 PM
Points: 1500
Pomos (25 mins): 1
Related To: Spiral%20Matrix%2059bb07ea77464b4881b0135bcd8e2e95.md
Source: https://leetcode.com/problems/spiral-matrix-ii/
Status: done
---

# Spiral Matrix II - LeetCode

Given a positive integer `n`, generate an `n x n` `matrix` filled with elements from `1` to `n2` in spiral order.
**Example 1:**
![Spiral%20Matrix%20II%20-%20LeetCode%2095b1eda25bbc41648389668ddfb577b4/spiraln.jpg](Spiral%20Matrix%20II%20-%20LeetCode%2095b1eda25bbc41648389668ddfb577b4/spiraln.jpg)
```
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
```
**Example 2:**
```
Input: n = 1
Output: [[1]]
```
**Constraints:**
- `1 <= n <= 20`
---
The spiral traversal technique. 
```cpp
class Solution {
public:
    int floorMod(int x, int y) {
        return ((x % y) + y) % y;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result (n, vector<int>(n));
        int cnt = 1;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
       int d = 0;
        int row = 0;
        int col = 0;
        while (cnt <= n * n) {
            result[row][col] = cnt++;
            int r = floorMod(row + dir[d][0], n);
            int c = floorMod(col + dir[d][1], n);
            // change direction if next cell is non zero
            if (result[r][c] != 0) d = (d + 1) % 4;
            row += dir[d][0];
            col += dir[d][1];
        }
        return result;
    }
};
```
Recursion
```cpp
class Solution {
public:
    void fill_spiral(vector<vector<int>>& matrix, int val, int r, int c, int n)
    {
        if (n == 0) return;
        if (n == 1) 
        {
            matrix[r][c] = val++; return;
        }
        for (int j = c; j < c + n; j++)
        {
            matrix[r][j] = val++; 
        }
        for (int i = r + 1; i < r + n; i++)
        {
            matrix[i][c + n - 1] = val++;
        }
        for (int j = c + n - 2; j >= c; j--)
        {
            matrix[r + n - 1][j] = val++; 
        }
        for (int i = r + n - 2; i > r; i--)
        {
            matrix[i][c] = val++;
        }
        fill_spiral(matrix, val, r + 1, c + 1, n - 2); 
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        fill_spiral(matrix, 1, 0, 0, n); 
        return matrix; 
    }
};
```
Patterns: [Matrix](Matrix.md)