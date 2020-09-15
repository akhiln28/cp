#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

#define mod 1000000007

using namespace std;

int dfs(vector<vector<int>> &graph, int i, vector<bool> &vis)
{
    vis[i] = true;
    int count = 1; 
    for (int j = 0; j < graph[i].size(); j++)
    {
        if (!vis[graph[i][j]])
            count += dfs(graph, graph[i][j], vis);
    }
    return count;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, m; cin >> n >> m;
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < m; i++)
        {
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        vector<bool> vis(graph.size(), false);
        vector<int> comps;
        for (int i = 1; i < graph.size(); i++)
        {
            if (!vis[i])
                comps.push_back(dfs(graph, i, vis));
        }
        long long ans = 1;
        for (int i = 0; i < comps.size(); i++)
        {
            ans = (ans * comps[i]) % mod;
        }
        cout << comps.size() << " " << ans << endl;
    }
}
