# Number of Restricted Paths From First to Last Node - Leetcode

Created Time: Mar 06, 2021 4:48 PM
Do Date: Mar 06, 2021
Last edited time: Mar 06, 2021 4:51 PM
Pattern: https://www.notion.so/Algorithms-1c9aec7b298b42618a56ab794407b400, https://www.notion.so/Graphs-429761a7bf524bd984bacb37409f2858
Points: 1600
Pomos (25 mins): 2
Source: https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/
Status: done

There is an undirected weighted connected graph. You are given a positive integer `n` which denotes that the graph has `n` nodes labeled from `1` to `n`, and an array `edges` where each `edges[i] = [ui, vi, weighti]` denotes that there is an edge between nodes `ui` and `vi` with weight equal to `weighti`.

A path from node `start` to node `end` is a sequence of nodes `[z0, z1, z2, ..., zk]` such that `z0 = start` and `zk = end` and there is an edge between `zi` and `zi+1` where `0 <= i <= k-1`.

The distance of a path is the sum of the weights on the edges of the path. Let `distanceToLastNode(x)` denote the shortest distance of a path between node `n` and node `x`. A **restricted path** is a path that also satisfies that `distanceToLastNode(zi) > distanceToLastNode(zi+1)` where `0 <= i <= k-1`.

Return *the number of restricted paths from node* `1` *to node* `n`. Since that number may be too large, return it **modulo** `10^9+ 7`.

**Example 1:**

![Number%20of%20Restricted%20Paths%20From%20First%20to%20Last%20Node%20dfcebd1a9e8240e594af0f0aecf6bdaa/restricted_paths_ex1.png](restricted_paths_ex1.png)

```
Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
Output: 3
Explanation: Each circle contains the node number in black and itsdistanceToLastNode value in blue.The three restricted paths are:
1) 1 --> 2 --> 5
2) 1 --> 2 --> 3 --> 5
3) 1 --> 3 --> 5
```

**Example 2:**

![Number%20of%20Restricted%20Paths%20From%20First%20to%20Last%20Node%20dfcebd1a9e8240e594af0f0aecf6bdaa/restricted_paths_ex22.png](restricted_paths_ex22.png)

```
Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
Output: 1
Explanation: Each circle contains the node number in black and itsdistanceToLastNode value in blue.The only restricted path is 1 --> 3 --> 7.
```

**Constraints:**

- `1 <= n <= 2 * 104`
- `n - 1 <= edges.length <= 4 * 104`
- `edges[i].length == 3`
- `1 <= ui, vi <= n`
- `ui != vi`
- `1 <= weighti <= 105`
- There is at most one edge between any two nodes.
- There is at least one path between any two nodes.

---

```cpp
class Solution {
public:
    const int inf = 1e9 + 7; 
    int numpaths(int i, vector<vector<pair<int, int>>>& graph, vector<int>& dist, vector<int>& ans)
    {
        if (i == graph.size() - 1) return ans[i] = 1; 
        if (ans[i] != -1) return ans[i]; 
        ans[i] = 0; 
        for (auto p : graph[i])
        {
            if (dist[p.first] >= dist[i]) continue; 
            ans[i] = (ans[i] + numpaths(p.first, graph, dist, ans)) % inf; 
        }
        return ans[i]; 
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        // using dijkstra's to find the all shortest paths from 1, 2, .. n - 1 to n;
        // and then using dfs will do the job
        vector<vector<pair<int, int>>> graph(n + 1); 
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int> dist(n + 1, inf); 
        dist[n] = 0; 
        set<pair<int, int>> pq;
        for (int i = 1; i < dist.size(); i++) pq.insert({dist[i], i});
        while (pq.size())
        {
            auto it = pq.begin();
            auto p = *it; 
            pq.erase(it); 
            for (auto p1 : graph[p.second])
            {
                if (dist[p1.first] <= dist[p.second] + p1.second) continue; 
                pq.erase({dist[p1.first], p1.first});
                dist[p1.first] = min(dist[p1.first], dist[p.second] + p1.second);
                pq.insert({dist[p1.first], p1.first});
            }
        }
        // for (int i = 1; i <= n; i++) cout << dist[i] << " "; cout << endl;
        vector<int> ans(n + 1, -1); 
        return numpaths(1, graph, dist, ans); 
    }
};
```