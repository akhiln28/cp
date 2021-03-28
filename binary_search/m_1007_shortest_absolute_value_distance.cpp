#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

/*
    title: m_shortest_absolute_value_distance.cpp
    author: Akhil
    date: 2021-03-28
    time: 07:14:49
    =============================================
    shortest distance from source to destination. and there are distance values between adjacent nodes.
    first building the graph and applying the dijkstra's algorithm would do the job.
*/

int solve(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<pair<int, int>>> graph(m * n);
    auto is_valid = [&](int i, int j){
        return (i < m and j < n and i >= 0 and j >= 0);
    };
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vector<vector<int>> nbs{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            for (int k = 0; k < nbs.size(); k++)
            {
                int i1 = i + nbs[k][0], j1 = j + nbs[k][1];
                if (is_valid(i1, j1))
                {
                    graph[n * i + j].push_back({n * i1 + j1, abs(matrix[i][j] - matrix[i1][j1])});
                }
            }
        }
    }
    // now will have to apply dijkstra's algorithm
    vector<int> dist(m * n, INT_MAX);
    vector<bool> vis(m * n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0] = 0;
    for (int i = 0; i < m * n; i++)
    {
        pq.push({dist[i], i});
    }
    while (pq.size())
    {
        auto top = pq.top(); pq.pop();
        int idx = top.second;
        if (vis[idx]) continue;
        dist[idx] = top.first;
        for (auto nb : graph[idx])
        {
            if (dist[nb.first] > dist[idx] + nb.second)
            {
                dist[nb.first] = dist[idx] + nb.second;
                pq.push({dist[nb.first], nb.first});
            }
        }
        vis[idx] = true;
    }
    return dist[m * n - 1];
}

int main()
{
    // vector<vector<int>> matrix{{1, 100, 1},
    //                             {2, 5, 3},
    //                             {1, 2, 3}};
    vector<vector<int>> matrix{{1, 7, 1},
                                {3, 9, 3},
                                {12, 2, 7}};
    auto ret = solve(matrix);
    cout << ret << endl;
    return 0;
}