#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

bool dfs(vector<vector<pair<int, float>>> &graph, int i, vector<float> &vals)
{
    bool ans = false; 
    for (auto [j, ratio] : graph[i])
    {
        if (!vals[j]) 
        {
            vals[j] = vals[i] * ratio;
            ans = ans || dfs(graph, j, vals); 
        }
        else if (vals[j] != vals[i] * ratio)
        {
            return true; 
        }
    }
    return ans; 
}

int main()
{
    int n; // number of currencies
    cin >> n;
    int m; // number of mappings
    cin >> m; 
    
    vector<vector<pair<int, float>>> graph(n); 
    for (int i = 0; i < m; i++)
    {
        int a, b; // zero indexed; 
        float ratio; 
        cin >> a >> b >> ratio;
        graph[a].push_back({b, ratio});
        graph[b].push_back({a, 1.0/ratio});
    }
    bool nz_cycle = false; 

    for (int i = 0; i < n; i++)
    {
        vector<float> vals(n, 0);
        vals[i] = 1;
        if (dfs(graph, i, vals)) nz_cycle = true;
    }
    
    cout << (nz_cycle ? "contains non zero cycle" : "no non zero cycle found") << endl;
    return 0;
}