---
Created Time: Feb 13, 2021 11:12 AM
Do Date: Feb 13, 2021
Last edited time: May 11, 2021 9:04 AM
Points: 1600
Source: https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/
Status: done
---

# Minimum Degree of a Connected Trio in a Graph - LeetCode

You are given an undirected graph. You are given an integer `n` which is the number of nodes in the graph and an array `edges`, where each `edges[i] = [ui, vi]` indicates that there is an undirected edge between `ui` and `vi`.
A **connected trio** is a set of **three** nodes where there is an edge between **every** pair of them.
The **degree of a connected trio** is the number of edges where one endpoint is in the trio, and the other is not.
Return *the **minimum** degree of a connected trio in the graph, or* `-1` *if the graph has no connected trios.*
**Example 1:**
![Minimum%20Degree%20of%20a%20Connected%20Trio%20in%20a%20Graph%20-%20Le%20fd7c4326c2d8412ebc2bf2965b643cd9/trios1.png](Minimum%20Degree%20of%20a%20Connected%20Trio%20in%20a%20Graph%20-%20Le%20fd7c4326c2d8412ebc2bf2965b643cd9/trios1.png)
```
Input: n = 6, edges = [[1,2],[1,3],[3,2],[4,1],[5,2],[3,6]]
Output: 3
Explanation: There is exactly one trio, which is [1,2,3]. The edges that form its degree are bolded in the figure above.
```
**Example 2:**
![Minimum%20Degree%20of%20a%20Connected%20Trio%20in%20a%20Graph%20-%20Le%20fd7c4326c2d8412ebc2bf2965b643cd9/trios2.png](Minimum%20Degree%20of%20a%20Connected%20Trio%20in%20a%20Graph%20-%20Le%20fd7c4326c2d8412ebc2bf2965b643cd9/trios2.png)
```
Input: n = 7, edges = [[1,3],[4,1],[4,3],[2,5],[5,6],[6,7],[7,5],[2,6]]
Output: 0
Explanation: There are exactly three trios:
1) [1,4,3] with degree 0.
2) [2,5,6] with degree 2.
3) [5,6,7] with degree 2.
```
**Constraints:**
- `2 <= n <= 400`
- `edges[i].length == 2`
- `1 <= edges.length <= n * (n-1) / 2`
- `1 <= ui, vi <= n`
- `ui != vi`
- There are no repeated edges.
---
```cpp
class Solution {
public:
    int inf = 1e9 + 7; 
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1); 
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]); 
            graph[edges[i][1]].push_back(edges[i][0]); 
        }
        vector<vector<int>> matrix(n + 1, vector<int>(n + 1)); 
        for (auto e : edges)
        {
            matrix[e[1]][e[0]] = 1; 
            matrix[e[0]][e[1]] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            sort(graph[i].begin(), graph[i].end());
        }
        int ans = inf; 
        vector<bool> vis(n + 1); 
        for (auto e : edges)
        {
            vector<int>& v1 = graph[e[0]]; 
            vector<int>& v2 = graph[e[1]]; 
            for (auto v : v1)
            {
                if (matrix[v][e[1]] and v != e[1])
                {
                    ans = min(ans, (int) v1.size() + (int) v2.size() + (int) graph[v].size() - 6);
                }
            }
        }
        
        return (ans != inf) ? ans : -1; 
    }
};
```
Patterns: [Array](Array.md)[patterns/Greedy](patterns/Greedy.md)[Traversal](Traversal.md)