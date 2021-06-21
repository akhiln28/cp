---
Created Time: Feb 12, 2021 9:15 AM
Do Date: Feb 12, 2021
Last edited time: Feb 12, 2021 9:31 AM
Points: 1500
Source: https://binarysearch.com/problems/Bipartite-Graph
Status: done
---

# Bipartite Graph | binarysearch

Given an undirected graph represented as an adjacency list, return whether the graph is bipartite.
**Constraints**
- `n, m ≤ 250` where `n` and `m` are the number of rows and columns in `graph`
---
Try to 2 color graph using dfs. 
```cpp
bool dfs(int i, int c, vector<int>& color, vector<vector<int>>& graph)
{
    bool ans = true; 
    if (color[i] == -1)
    {
        color[i] = c; 
        for (int j : graph[i])
        {
            ans = (ans && dfs(j, 1 - c, color, graph));
            if (!ans) break; 
        }
    }
    else ans = (color[i] == c); 
    return ans; 
}
bool solve(vector<vector<int>>& graph) {
    int n = graph.size(); 
    vector<int> color(n, -1); 
    bool ans = dfs(0, 0, color, graph); 
    return ans; 
}
```
Patterns: 