#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <set>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 100001

using namespace std;

int dfs(vector<set<int>> &v, int i, vector<bool> &vis)
{
    vis[i] = true;
    int ans = 1; 
    for (auto it : v[i])
    {
        if (!vis[it]) 
            ans += dfs(v, it, vis);
    }
    return ans;
}

int main()
{
    int n, m; cin >> n >> m;
    vector<set<int>> v(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
    }
    int ans = 0; 
    vector<bool> vis(v.size(), false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans = max(ans, dfs(v, i, vis));
        }
    }
    cout << ans << endl;
    return 0;
}