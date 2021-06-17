# Longest Increasing Path in a Matrix

Created Time: Dec 01, 2020 11:55 PM
Do Date: Jan 24, 2021
Last edited time: Mar 01, 2021 8:43 AM
Pattern: https://www.notion.so/DFS-ba39c3dceb894d178f88767d81fa001a
Points: 2000
Status: done
Tags: DAG, longest path

Given an `m x n` integers `matrix`, return *the length of the longest increasing path in* `matrix`.

From each cell, you can either move in four directions: left, right, up, or down. You **may not** move **diagonally** or move **outside the boundary** (i.e., wrap-around is not allowed).

**Example 1:**

![https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg](https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg)

```
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

```

**Example 2:**

![https://assets.leetcode.com/uploads/2021/01/05/grid2.jpg](https://assets.leetcode.com/uploads/2021/01/05/grid2.jpg)

```
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

```

**Example 3:**

```
Input: matrix = [[1]]
Output: 1

```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 200`
- `0 <= matrix[i][j] <= 231 - 1`

---

Using dynamic programming. The standard DAG question. 

```cpp
class Solution {
public:
    int dfs(int i, vector<vector<int>> &graph, vector<int> &dis)
    {
        if (dis[i] != -1) return dis[i];
        int ans = 1; 
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (dis[graph[i][j]] == -1)
                dfs(graph[i][j], graph, dis);
            ans = max(ans, 1 + dis[graph[i][j]]);
        }
        dis[i] = ans;
        return ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (!matrix.size()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> graph(n * m);
        vector<int> dis(n * m, -1);
        auto check = [&n, &m](int i, int j){
            return (i < n && i >= 0 && j < m && j >= 0);
        };
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vector<pair<int,int>> ne = {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
                for (auto p : ne)
                {
                    if (check(p.first, p.second) && matrix[p.first][p.second] > matrix[i][j])
                        graph[m * i + j].push_back(m * p.first + p.second);
                }
            }
        }
        int ans = 0; 
        for (int i = 0; i < n * m; i++)
        {
            if (dis[i] == -1)
            {
                dfs(i, graph, dis);
            }
            ans = max(ans, dis[i]);
        }
        return ans;
    }
};
```