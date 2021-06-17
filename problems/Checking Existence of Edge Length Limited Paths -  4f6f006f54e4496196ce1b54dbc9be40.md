# Checking Existence of Edge Length Limited Paths - LeetCode

Created Time: Dec 19, 2020 5:12 PM
Last edited time: May 20, 2021 9:55 AM
Pattern: https://www.notion.so/Union-Find-cedb0985a13849fd91014bde5731e6ec
Points: 2000
Pomos (25 mins): 2
Source: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/
Status: waiting
Tags: hard

An undirected graph of `n` nodes is defined by `edgeList`, where `edgeList[i] = [ui, vi, disi]` denotes an edge between nodes `ui` and `vi` with distance `disi`. Note that there may be **multiple** edges between two nodes.

Given an array `queries`, where `queries[j] = [pj, qj, limitj]`, your task is to determine for each `queries[j]` whether there is a path between `pj` and `qj`such that each edge on the path has a distance **strictly less than** `limitj` .

Return *a **boolean array*** `answer`*, where* `answer.length == queries.length` *and the* `jth` *value of* `answer` *is* `true` *if there is a path for* `queries[j]` *is* `true`*, and* `false` *otherwise*.

**Example 1:**

![Checking%20Existence%20of%20Edge%20Length%20Limited%20Paths%20-%20%204f6f006f54e4496196ce1b54dbc9be40/h.png](h.png)

```
Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
Output: [false,true]
Explanation: The above figure shows the given graph. Note that there are two overlapping edges between 0 and 1 with distances 2 and 16.
For the first query, between 0 and 1 there is no path where each distance is less than 2, thus we return false for this query.
For the second query, there is a path (0 -> 1 -> 2) of two edges with distances less than 5, thus we return true for this query.
```

**Example 2:**

![Checking%20Existence%20of%20Edge%20Length%20Limited%20Paths%20-%20%204f6f006f54e4496196ce1b54dbc9be40/q.png](q.png)

```
Input: n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
Output: [true,false]
Exaplanation: The above figure shows the given graph.
```

**Constraints:**

- `2 <= n <= 10^5`
- `1 <= edgeList.length, queries.length <= 10^5`
- `edgeList[i].length == 3`
- `queries[j].length == 3`
- `0 <= ui, vi, pj, qj <= n - 1`
- `ui != vi`
- `pj != qj`
- `1 <= disi, limitj <= 10^9`
- There may be **multiple** edges between two nodes.

---

Initially I tried to solve it using brute force. I got TLE. 

```cpp
class Solution {
public:
    vector<bool> vis;
    bool dfs(vector<vector<pair<int, int>>>& graph, int i, int e, int limit)
    {
        if (i == e) return true; 
        vis[i] = true; 
        bool ans = false;
        for (auto [j, l] : graph[i])
        {
            if (vis[j] == true or l >= limit) continue; 
            ans |= dfs(graph, j, e, limit);
            if (ans) break;
        }
        return ans; 
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> graph(n); 
        vis.resize(n);
        for (auto &e : edgeList)
        {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        vector<bool> ans; 
        for (auto &q : queries)
        {
            for (int i = 0; i < n; i++) vis[i] = false;
            ans.push_back(dfs(graph, q[0], q[1], q[2]));
        }
        return ans; 
    }
};
```