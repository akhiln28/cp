#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <utility>
#include <assert.h>

using namespace std;

int dfs(vector<vector<int>> &graph, int i, int p, vector<int> &sub, vector<int> &par)
{
    if (sub[i]) return sub[i];
    sub[i] = 1;
    par[i] = p;
    for (int j : graph[i])
    {
        if (!sub[j]) sub[i] += dfs(graph, j, i, sub, par);
    }
    return sub[i];
}

int main()
{
    int T; cin >> T; 
    for (int t = 0; t < T; t++)
    {
        int n; cin >> n;
        vector<vector<int>> graph(n + 1);
        for (int i = 1; i < n; i++)
        {
            int x, y; cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        vector<int> sub(n + 1), par(n + 1);
        dfs(graph, 1, 0, sub, par);
        vector<int> centroids;
        for (int i = 1; i <= n; i++)
        {
            if (sub[i] * 2 == n) centroids.push_back(i), centroids.push_back(par[i]);
        }
        if (!centroids.size())
        {
            cout << 1 << " " << graph[1][0] << endl;
            cout << 1 << " " << graph[1][0] << endl;
        }
        else
        {
            for (auto j : graph[centroids[0]])
            {
                if (j != centroids[1])
                {
                    cout << centroids[0] << " " << j << endl;
                    cout << centroids[1] << " " << j << endl;
                    break;
                }
            }
        }
    }
    return 0; 
}