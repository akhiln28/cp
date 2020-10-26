/*
    title: a_linova_and_kingdom.cpp
    author: Akhil
    date: 2020-10-20
    time: 20:12:22
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

int dfs(vector<vector<int>> &tree, vector<int> &dist, int i, int depth, vector<bool> &vis)
{
    vis[i] = true; 
    int size = 0; 
    for (auto j : tree[i])
    {
        if (vis[j] == true) continue; 
        size += dfs(tree, dist, j, depth + 1, vis);     
    }
    dist[i - 1] = size - depth + 1; 
    return size + 1; 
}

int main()
{
    int n, k; cin >> n >> k;
    vector<vector<int>> v(n + 1); 
    for (int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b; 
        v[a].push_back(b); 
        v[b].push_back(a); 
    }
    vector<int> dist(n); 
    vector<bool> vis(n + 1); 
    dfs(v, dist, 1, 1, vis); 
    sort(dist.rbegin(), dist.rend()); 
    long long ans = accumulate(dist.begin(), dist.begin() + n - k, 0LL);
    cout << ans << endl;
    return 0;
}