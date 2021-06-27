---
created at: 2021-06-20 
author: akhiln
tags: [problem]
level: 1500
status: pending
---

# Count Sub Islands 
### Problem Statement
Given two grids grid1 and grid2, find the number of islands in grid2 that are sub islands in grid1. 

#### Examples
![](https://assets.leetcode.com/uploads/2021/06/10/test1.png)
output: 3

### Solution
```python
Find all the islands in the grid2. 
	DFS on a cell will visit all its neighbors
For island in islands:
	check if all cells in island are land in the grid1
	if yes then Answer += 1
Store the islands as a vector sorted coordinates. 
```

Getting TLE for some reason. The complexity of my algorithm is $O(m \times n)$

So, the complexity should be even more optimized or that I am missing some test case. 
```cpp
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis, vector<pair<int, int>>& comp) {
        int m = grid.size(), n = grid[0].size();
        vis[i][j] = true; 
        comp.push_back({i, j});
        vector<vector<int>> nb{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        auto valid = [&](int x, int y) {
          return (x >= 0 and x < m) and (y >= 0 and y < n);   
        };
        for (auto nbr: nb)
        {
            int x = i + nbr[0], y = j + nbr[1]; 
            if (valid(x, y) and grid[x][y] and vis[x][y] == false) 
            {
                dfs(x, y, grid, vis, comp); 
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n));
        int ans = 0; 
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (grid2[i][j] == 1 and vis[i][j] == false) 
                {
                    vector<pair<int, int>> comp; 
                    bool flag = grid1[i][j];
                    if (flag) dfs(i, j, grid2, vis, comp);
                    for (auto p : comp) {
                        if (flag == false) break; 
                        flag = grid1[p.first][p.second];
                    }
                    ans += flag; 
                }
            }
        }
        return ans; 
    }
};
```

After removing the lambda function and vector `nb` for `dfs` it is working. 
```cpp
class Solution {
public:
    void dfs(int i, int j, bool& flag, vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        if (i < 0 or i >= m or j < 0 or j >= n or grid2[i][j] == 0) return;
        grid2[i][j] = 0;
        if (grid1[i][j] == 0) flag = false; 
        dfs(i + 1, j, flag, grid1, grid2); 
        dfs(i - 1, j, flag, grid1, grid2);
        dfs(i, j + 1, flag, grid1, grid2);
        dfs(i, j - 1, flag, grid1, grid2); 
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size(), n = grid1[0].size();
        int ans = 0; 
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (grid2[i][j] == 1) 
                {
                    bool flag = grid1[i][j];
                    dfs(i, j, flag, grid1, grid2);
                    ans += flag; 
                }
            }
        }
        return ans; 
    }
};
```
Still not sure how this is working. 
#### References
Patterns: [DFS](DFS.md)