#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 100001
#define mod 1000000007

using namespace std;

int explore(vector<vector<int>> &graph, int idx, vector<long long> &vals, vector<bool> &vis)
{
    vis[idx] = true;
    int neighbors = 1;
    for (int j = 0; j < graph[idx].size(); j++)
    {
        if (!vis[graph[idx][j]])
            neighbors += explore(graph, graph[idx][j], vals, vis);
    }
    vals.push_back(neighbors * (graph.size() - 1 - neighbors));
    return neighbors;
}

void dfs(vector<vector<int>> &graph, int idx, vector<long long> &vals)
{
    vector<bool> vis(graph.size());
    explore(graph, idx, vals, vis);
}

void fill(vector<vector<pair<int, int>>> &graph)
{
    int n = graph.size() - 1;
    for (int i = 1; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            bool flag = (graph[i][j].second != 0);
            int nei = graph[i][j].first;
            for (int k = 0; k < graph[nei].size(); k++)
            {
                if (graph[nei][k].first == i)
                {
                    if (flag)
                        graph[nei][k].second = n - graph[i][j].second;
                    else
                        graph[i][j].second = n - graph[nei][k].second;
                    break;
                }
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int m;
        cin >> m;
        vector<int> primes(m);
        for (int i = 0; i < m; i++)
        {
            cin >> primes[i];
        }
        vector<long long> vals;
        dfs(graph, 1, vals);
        long long ans = 0;
        sort(vals.rbegin(), vals.rend()), sort(primes.rbegin(), primes.rend());
        if (m <= n - 1)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (i < primes.size())
                    ans = (ans + (vals[i] * primes[i]) % mod) % mod;
                else ans = (ans + vals[i] % mod) % mod;
            }
        }
        else
        {
            long long lrgstf = 1;
            for (int i = 0; i < m - n + 2; i++)
            {
                lrgstf = (lrgstf * primes[i]) % mod;
            }
            ans += (vals[0] * lrgstf) % mod;
            for (int i = 1; i < n - 1; i++)
            {
                ans = (ans + vals[i] * primes[i + m - n + 1]) % mod;
            }
        }
        cout << ans << endl;
    }

    return 0;
}