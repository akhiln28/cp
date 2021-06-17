# Surrounded Regions - LeetCode

Created Time: Feb 12, 2021 8:10 AM
Do Date: Feb 12, 2021
Last edited time: Mar 01, 2021 8:43 AM
Pattern: https://www.notion.so/Matrix-4e063cbec5124ef1af380e9e5daf8ffb, https://www.notion.so/DFS-ba39c3dceb894d178f88767d81fa001a
Points: 1500
Source: https://leetcode.com/problems/surrounded-regions/
Status: done

Given a 2D board containing `'X'` and `'O'` (**the letter O**), capture all regions surrounded by `'X'`.

A region is captured by flipping all `'O'`s into `'X'`s in that surrounded region.

**Example:**

```
X X X X
X O O X
X X O X
X O X X
```

After running your function, the board should be:

```
X X X X
X X X X
X X X X
X O X X
```

**Explanation:**

Surrounded regions shouldn’t be on the border, which means that any `'O'` on the border of the board are not flipped to `'X'`. Any `'O'` that is not on the border and it is not connected to an `'O'` on the border will be flipped to `'X'`. Two cells are connected if they are adjacent cells connected horizontally or vertically.

---

```cpp
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board)
    {
        int n = board.size(), m = board[0].size(); 
        board[i][j] = 'V';
        if (i + 1 < n and board[i + 1][j] == 'O') dfs(i + 1, j, board); 
        if (i - 1 >= 0 and board[i - 1][j] == 'O') dfs(i - 1, j, board); 
        if (j + 1 < m and board[i][j + 1] == 'O') dfs(i, j + 1, board); 
        if (j - 1 >= 0 and board[i][j - 1] == 'O') dfs(i, j - 1, board); 
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        int n = board.size(), m = board[0].size(); 
        for (int i = 0; i < m; i++) 
        {
            if (board[0][i] == 'O') dfs(0, i, board); 
        }
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O') dfs(i, 0, board); 
        }
        for (int j = 0; j < m; j++)
        {
            if (board[n - 1][j] == 'O') dfs(n - 1, j, board); 
        }
        for (int i = 0; i < n; i++)
        {
            if (board[i][m - 1] == 'O') dfs(i, m - 1, board); 
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O') board[i][j] = 'X'; 
                else if (board[i][j] == 'V') board[i][j] = 'O'; 
            }
        }
    }
};
```