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
    title: abc_199_d.cpp
    author: Akhil
    date: 2021-04-24
    time: 18:02:53
    ==================================================
    Given a graph (n <= 20), find the number of 3 coloring graphs
    a - b - c - a
    For each connected component, find the number of ways.
*/

long long dfs(vector<vector<int>>& graph, int i, vector<int>& color)
{
    bool red = true;
    bool blue = true;
    bool green = true;
    for (auto nb : graph[i]) {
        if (color[nb] == 1) red = false;
        else if (color[nb] == 2) blue = false;
        else if (color[nb] == 3) green = false;
    }
    int ans = 0;
    if (red + blue + green)
    {
        for (auto nb : graph[i])
        {
            if (color[nb] > 0) continue;
            if (red)
            {
                color[i] = 1;
                ans += dfs(graph, nb, color);
            }
            if (blue)
            {
                color[i] = 2;
                ans += dfs(graph, nb, color);
            }
            if (green)
            {
                color[i] = 3;
                ans += dfs(graph, nb, color);
            }
        }
        if (color[i] == 0) ans = red + blue + green;
    }
    color[i] = 0;
    return ans;
}

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    vector<int> color(n, -1);
    long long ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            ans *= dfs(graph, i, color);
        }
    }
    cout << ans << endl;
    return 0;
}