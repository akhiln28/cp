---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Feb 24, 2021
Last edited time: Mar 01, 2021 8:43 AM
Points: 1500
Source: https://leetcode.com/problems/course-schedule/
Status: done
Tags: standard
---

# Course Schedule

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.
- For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.
Return `true` if you can finish all courses. Otherwise, return `false`.
**Example 1:**
```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
```
**Example 2:**
```
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
```
**Constraints:**
- `1 <= numCourses <= 105`
- `0 <= prerequisites.length <= 5000`
- `prerequisites[i].length == 2`
- `0 <= ai, bi < numCourses`
- All the pairs prerequisites[i] are **unique**.
---
```cpp
class Solution {
public:
    bool cycle(vector<vector<int>> &graph, int i, vector<bool> &vis1, vector<bool> &vis2)
    {
        vis1[i] = true;
        vis2[i] = true;
        bool is_cycle = false;
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (vis2[graph[i][j]]) return true;
            if (!vis1[graph[i][j]]) is_cycle |= cycle(graph, graph[i][j], vis1, vis2);
        }
        vis2[i] = false;
        return is_cycle;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis1(numCourses, false), vis2(numCourses, false);
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < graph.size(); i++)
        {
            if (!vis1[i] and cycle(graph, i, vis1, vis2)) return false;
        }
        return true;
    }
};
```
Patterns: [Graphs](Graphs.md)[DFS](DFS.md)