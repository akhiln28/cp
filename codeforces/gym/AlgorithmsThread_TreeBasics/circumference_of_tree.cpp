#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>
using namespace std;

pair<int, int> explore(vector<bool> &vis, int i, vector<vector<int>> &v)
{
    vis[i] = true;
    pair<int, int> p{i, 0};
    for (int j = 0; j < v[i].size(); j++)
    {
        if (!vis[v[i][j]]) 
        {
            auto p1 = explore(vis, v[i][j], v);
            if (p1.second + 1 > p.second) 
            {
                p.first = p1.first, p.second = p1.second + 1;
            }
        }
    }
    return p;
}

pair<int, int> dfs(int i, vector<vector<int>> &v)
{
    vector<bool> vis(v.size(), false);
    return explore(vis, i, v);
}

int main()
{
    int n; cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    if (v.size() < 2) cout << 0 << endl;
    else
    {
        auto p = dfs(1, v);
        auto p1 = dfs(p.first, v); 
        cout << 3 * p1.second << endl;
    }
    
    return 0;
}


