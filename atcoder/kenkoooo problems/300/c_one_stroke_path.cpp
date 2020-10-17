/*
    title: c_one_stroke_path.cpp
    author: Akhil
    date: 2020-10-14
    time: 19:59:12
*/
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

int dfs(vector<vector<int>> &v, int i, vector<bool> &vis)
{
    vis[i] = true; 
    int ans = 0; 
    for (auto j : v[i])
    {
        if (vis[j]) continue;
        ans += dfs(v, j, vis); 
    }
    if (ans == 0)
    {
        ans = 1; 
        for (int j = 1; j < vis.size(); j++) if (vis[j] == false) ans = 0; 
    }
    vis[i] = false; 
    return ans; 
}

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n + 1); 
    for (size_t i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; 
        v[a].push_back(b); 
        v[b].push_back(a);
    }
    vector<bool> vis(n + 1, false); 
    cout << dfs(v, 1, vis) << endl;
    return 0;
}
