#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

bool check(int n, int m, int i, int j)
{
    return (i >= 0 && j >= 0 && i < n && j < m);
}

int dfs(vector<vector<int>> &country, int i, int j, vector<vector<bool>> &vis)
{
    vis[i][j] = true;
    vector<pair<int, int>> t{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}};
    int count = 1;
    for (auto it : t)
    {
        if (check(country.size(), country[0].size(), it.first, it.second) &&
            country[i][j] == country[it.first][it.second] &&
            !vis[it.first][it.second])
        {
            count += dfs(country, it.first, it.second, vis);
        }
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> country(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> country[i][j];
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int max_size = 0, min_s = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                int t = dfs(country, i, j, vis);
                if (max_size < t)
                    max_size = t, min_s = country[i][j];
                else if (max_size == t)
                    min_s = min(min_s, country[i][j]);
            }
        }
    }
    cout << min_s << " " << max_size << endl;
}
