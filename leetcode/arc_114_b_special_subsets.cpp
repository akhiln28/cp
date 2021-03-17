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

const int mod = 998244353;  

// simple dfs for finding the connected components
void dfs(vector<vector<int>>& graph, int i, vector<bool>& vis)
{
    vis[i] = true; 
    for (int j : graph[i])
    {
        if (vis[j] == true) continue; 
        dfs(graph, j, vis);
    }
}

int mpow2(int i)
{
    if (i == 0) return 1; 
    long long sub = mpow2(i/2); 
    if (i & 1) return (sub * sub * 2) % mod; 
    else return (sub * sub) % mod; 
}

int main()
{ 
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        v[i]--;
    vector<vector<int> > graph(n); 
    for (int i = 0; i < n; i++)
    {
        graph[i].push_back(v[i]);
        graph[v[i]].push_back(i);
    }
    int comps = 0;
    vector<bool> vis(n); 
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            comps++; 
            dfs(graph, i, vis);
        }
    }
    cout << mpow2(comps) - 1 << endl;
    return 0;
}