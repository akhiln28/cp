/*
    title: D.cpp
    author: Akhil
    date: 2020-10-24
    time: 21:09:45
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

#define ll long long

using namespace std;

void dfs(vector<vector<int>> &tree, int i, vector<ll> &pop, 
        vector<ll> &leaves, vector<ll> &size, ll &ans)
{
    if (tree[i].size() == 0) leaves[i] = 1; 
    size[i] = pop[i]; 
    for (auto j : tree[i])
    {
        dfs(tree, j, pop, leaves, size, ans);
        size[i] += size[j]; 
        leaves[i] += leaves[j]; 
    }
    ans = max(ans, (size[i] + leaves[i] - 1)/leaves[i]);
}

int main()
{
    int n; cin >> n;
    vector<vector<int>> tree(n); 
    for (int i = 0; i < n - 1; i++)
    {
        int p; cin >> p; 
        tree[p - 1].push_back(i + 1); 
    }
    vector<ll> leaves(n), size(n), pop(n); 
    for (int i = 0; i < n; i++) cin >> pop[i]; 
    ll ans = 0; 
    dfs(tree, 0, pop, leaves, size, ans); 
    cout << ans << endl;
    return 0;
}
