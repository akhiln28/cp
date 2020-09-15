#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

// #pending

#define alphabet 26

using namespace std;

void explore(vector<vector<int>> &graph, int idx, vector<int> &dis, vector<bool> &vis, int dist)
{
    vis[idx] = true;
    dis[idx] = dist;
    for (int i = 0; i < graph[idx].size(); i++)
    {
        if (!vis[graph[idx][i]])
            explore(graph, graph[idx][i], dis, vis, dist + 1);
    }
}

void dfs(vector<vector<int>> &graph, int idx, vector<vector<int>> &dis)
{
    vector<bool> vis(graph.size(), false);
    explore(graph, idx, dis[idx], vis, 0);
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        string s, e;
        cin >> s >> e;
        vector<vector<int>> mping(alphabet);
        int m;
        cin >> m;
        string str;
        for (int i = 0; i < m; i++)
        {
            cin >> str;
            mping[str[0] - 'a'].push_back(str[3] - 'a');
        }
        if (s.length() != e.length())
        {
            cout << "NO" << endl;
            continue;
        }
        vector<vector<int>> dis(alphabet, vector<int>(alphabet, INT_MAX));
        for (int i = 0; i < alphabet; i++)
        {
            if (mping[i].size())
            {
                dfs(mping, i, dis);
            }
        }
        bool flag = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (dis[s[i] - 'a'][e[i] - 'a'] == INT_MAX)
            {
                flag = false;
                break;
            }
        }
        cout << ((flag) ? "YES" : "NO") << endl;
    }
}