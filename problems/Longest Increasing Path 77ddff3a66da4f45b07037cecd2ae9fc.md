# Longest Increasing Path

Created Time: Dec 01, 2020 11:55 PM
Do Date: Dec 19, 2020
Last edited time: May 11, 2021 9:01 AM
Pattern: https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee, https://www.notion.so/Number-Theory-02e26369bab8475881b8a6a9d7b33ca9, https://www.notion.so/Linear-DP-40f64e6224704d17972aa352dc735edb
Points: 1800
Pomos (25 mins): 1
Problem Statement: longest increasing path in a matrix, you can go in all four directions
Relates: Maximum%20Height%20by%20Stacking%20Cuboids%20d04881ce384645b9ba6b0232f94d8575.md
Source: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
Status: done
Tags: DAG, longest path

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

**Example 1:**

```
Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
```

**Example 2:**

```
Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
```

---

Construct a DAG and DFS.

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

### Complexity:

$O(n * m)$