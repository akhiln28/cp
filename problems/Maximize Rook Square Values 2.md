---
Created Time: Feb 17, 2021 8:51 AM
Do Date: Feb 17, 2021
Last edited time: May 23, 2021 8:53 AM
Points: 1800
Pomos (25 mins): 1
Source: https://binarysearch.com/contest/Weekly-Contest-46-Wgbjnsf4qw?questionsetIndex=3
Status: waiting
---

# Maximize Rook Square Values

You are given a two-dimensional list of integers `board` representing a chess board. Return the maximum sum you can attain by placing two rooks in the board such that they can't attack each other. The sum is made by adding the two numbers where the rooks are placed.
**Constraints**
- `2 ≤ n * m ≤ 200,000` where `n` and `m` are the number of rows and columns in `board`
---
Please understand the below code: (#pending)
[binarysearch | Learn Algorithms Together](https://binarysearch.com/contest/Weekly-Contest-46-Wgbjnsf4qw/editorials/3776807?questionsetIndex=3)
```cpp
int solve(vector<vector<int>>& board) {
    int n = board.size(), m = board[0].size(); 
    vector<vector<int>> m1(board), m2(board), m3(board), m4(board); 
    const int inf = 1e9; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t = -inf; 
            if (i) t = max(t, m1[i - 1][j]);
            if (j) t = max(t, m1[i][j - 1]);
            if (i and j) t = max(t, m1[i - 1][j - 1]);
            m1[i][j] = max(m1[i][j], t);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            int t = -inf;
            if (i + 1 < n) t = max(t, m2[i + 1][j]);
            if (j) t = max(t, m2[i][j - 1]);
            if (i + 1 < n and j) t = max(t, m2[i + 1][j - 1]);
            m2[i][j] = max(m2[i][j], t); 
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int t = -inf;
            if (j + 1 < m) t = max(t, m3[i][j + 1]);
            if (i) t = max(t, m3[i - 1][j]); 
            if (j + 1 < m and i) t = max(t, m3[i - 1][j + 1]);
            m3[i][j] = max(m3[i][j], t); 
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int t = -inf;
            if (j + 1 < m) t = max(t, m4[i][j + 1]);
            if (i + 1 < n) t = max(t, m4[i + 1][j]); 
            if (j + 1 < m and i + 1 < n) t = max(t, m4[i + 1][j + 1]);
            m4[i][j] = max(m4[i][j], t); 
        }
    }
    int ans = -inf; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t = -inf; 
            if (i + 1 < n and j + 1 < m) t = max(t, m4[i + 1][j + 1]);
            if (i + 1 < n and j - 1 >= 0) t = max(t, m2[i + 1][j - 1]);
            if (i - 1 >= 0 and j + 1 < m) t = max(t, m3[i - 1][j + 1]);
            if (i - 1 >= 0 and j - 1 >= 0) t = max(t, m1[i - 1][j - 1]);
            ans = max(board[i][j] + t, ans); 
        }
    }
    return ans; 
}
```
Patterns: [Matrix](Matrix.md)[Cumulative](Cumulative.md)[Dp](Dp.md)