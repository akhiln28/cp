---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Feb 02, 2021
Last edited time: Mar 07, 2021 9:23 AM
Points: 1600
Pomos (25 mins): 2
Related To: Maximum%20sum%20path%20in%20a%20matrix%20from%20top-left%20to%20bott%20869852d3438e49cbb72b623274579c30.md
Status: done
Tags: path cost
---

# Path with Maximum gold

In a gold mine `grid` of size `m * n`, each cell in this mine has an integer representing the amount of gold in that cell, `0` if it is empty.
Return the maximum amount of gold you can collect under the conditions:
- Every time you are located in a cell you will collect all the gold in that cell.
- From your position you can walk one step to the left, right, up or down.
- You can't visit the same cell more than once.
- Never visit a cell with `0` gold.
- You can start and stop collecting gold from **any** position in the grid that has some gold.
**Example 1:**
```
Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7
```
**Example 2:**
```
Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
```
**Constraints:**
- `1 <= grid.length, grid[i].length <= 15`
- `0 <= grid[i][j] <= 100`
- There are at most **25** cells containing gold.
---
We can use backtracking to find the maximum. 
```cpp
class Solution {
public:
    bool check(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &vis)
    {
        return (i >= 0 and i < grid.size() and j >= 0 and j < grid[0].size() and grid[i][j] != 0 and vis[i][j] == false);
    }
    int max_path(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &vis)
    {
        vis[i][j] = true; 
        vector<pair<int, int>> next{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}}; 
        int ans = grid[i][j], temp = 0; 
        for (auto p : next)
        {
            if (check(grid, p.first, p.second, vis))
                temp = max(temp, max_path(grid, p.first, p.second, vis)); 
        }
        vis[i][j] = false;
        return ans + temp; 
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(); 
        
        int ans = 0; 
        vector<vector<bool>> vis(n, vector<bool> (m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0) continue;  
                int t = max_path(grid, i, j, vis); 
                ans = max(ans, t); 
            }
        }
        return ans; 
    }
};
```
- [ ]  complexity
Patterns: [Matrix](Matrix.md)[Backtracking](Backtracking.md)