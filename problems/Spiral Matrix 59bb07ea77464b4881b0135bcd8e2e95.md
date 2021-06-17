# Spiral Matrix

Created Time: Dec 01, 2020 11:51 PM
Do Date: Feb 20, 2021
Last edited time: Feb 22, 2021 9:58 PM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb
Points: 1500
Pomos (25 mins): 1
Relates: Spiral%20Matrix%20II%20-%20LeetCode%2095b1eda25bbc41648389668ddfb577b4.md, Spiral%20Matrix%20III%20-%20LeetCode%20c1a07ea290b64a009a2c9ce52f0483e0.md
Source: https://leetcode.com/problems/spiral-matrix/
Status: done

Given an `m x n` `matrix`, return *all elements of the* `matrix` *in spiral order*.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

```

**Example 2:**

![https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg](https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg)

```
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 10`
- `100 <= matrix[i][j] <= 100`

---

```cpp
class Solution {
public:
    void spiral_path(vector<vector<int>> &matrix, int r, int c, int n, int m, vector<int> &ans)
    {
        if (n == 0 or m == 0) return; 
        if (n == 1) {
            for (int j = 0; j < m; j++) ans.push_back(matrix[r][c + j]); 
        }
        else if (m == 1) {
            for (int i = 0; i < n; i++) ans.push_back(matrix[r + i][c]); 
        }
        else {
            for (int j = 0; j < m; j++) ans.push_back(matrix[r][c + j]); 
            for (int i = 1; i < n; i++) ans.push_back(matrix[r + i][c + m - 1]); 
            for (int j = m - 2; j >= 0; j--) ans.push_back(matrix[r + n - 1][c + j]); 
            for (int i = n - 2; i > 0; i--) ans.push_back(matrix[r + i][c]); 
            spiral_path(matrix, r + 1, c + 1, n - 2, m - 2, ans); 
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (!matrix.size()) return {}; 
        vector<int> ans; 
        spiral_path(matrix, 0, 0, matrix.size(), matrix[0].size(), ans); 
        return ans; 
    }
};
```