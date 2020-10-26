#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <list>
#include <numeric>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

pair<int, int> explore(vector<bool> &vis, int i, vector<vector<int>> &v, list<int> &ls)
{
    vis[i] = true;
    pair<int, int> p{i, 0};
    for (int j = 0; j < v[i].size(); j++)
    {
        if (!vis[v[i][j]]) 
        {
            auto p1 = explore(vis, v[i][j], v, ls);
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
    list<int> ls;
    return explore(vis, i, v, ls);
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
    }
}