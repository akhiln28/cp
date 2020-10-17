#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <numeric>
#include <climits>
#include <cmath>
#include <stdio.h>

long long inf = 1e15 + 1;

using namespace std;

void dfs_trace_path(vector<unordered_map<long long, long long>> &nb, long long i, vector<long long> &dist, vector<long long> &ans)
{
    if (i == 1) {return;}
    long long d = inf;
    for (auto j : nb[i])
    {
        if (d > dist[j.first] + j.second) {d = dist[j.first] + j.second;}
    }
    for (auto j : nb[i])
    {
        if (d == dist[j.first] + j.second) 
        {
            ans.push_back(j.first), dfs_trace_path(nb, j.first, dist, ans); 
            break;
        }
    }
}

int main()
{
    long long n, m; 
    cin >> n >> m;
    vector<unordered_map<long long, long long>> nb(n + 1);
    for (long long i = 0; i < m; i++)
    {
        long long a, b, w;
        cin >> a >> b >> w;
        if (nb[a].find(b) != nb[a].end()) nb[a][b] = min(w, nb[a][b]), nb[b][a] = min(w, nb[b][a]);
        else nb[a][b] = w, nb[b][a] = w;
    }
    vector<long long> dist(n + 1, inf);
    vector<bool> vis(n + 1, false);
    dist[1] = 0;
    set<pair<long long, long long>> s; // first is dist and second is index;
    for (long long i = 1; i <= n; i++) s.insert({dist[i], i});
    while (s.size())
    {
        long long idx = (*s.begin()).second; s.erase(s.begin());
        vis[idx] = true;
        for (auto j : nb[idx])
        {
            if (vis[j.first]) continue;
            if (dist[j.first] > dist[idx] + j.second) 
            {
                s.erase({dist[j.first], j.first});
                dist[j.first] = dist[idx] + j.second;
                s.insert({dist[j.first], j.first});
            }
        }
    }
    if (dist[n] == inf) {cout << -1 << endl; return 0;}
    vector<long long> ans;
    ans.push_back(n);
    dfs_trace_path(nb, n, dist, ans);
    reverse(ans.begin(), ans.end());
    for (long long i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
    return 0; 
}