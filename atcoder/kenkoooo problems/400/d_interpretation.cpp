/*
    title: d_interpretation.cpp
    author: Akhil
    date: 2020-11-09
    time: 20:14:59
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

// #define debug

using namespace std;

struct union_find
{
    vector<int> par, size;
    union_find(int n) : par(n), size(n, 1)
    {
        for (int i = 0; i < n; i++) par[i] = i; 
    }
    int find(int x)
    {
        return (par[x] == x) ? x : (par[x] = find(par[x])); 
    }
    void unite(int x, int y)
    {
        int parx = find(x), pary = find(y); 
        if (parx == pary) return;
        if (size[parx] > size[pary])
        {
            par[pary] = parx; 
            size[parx] += size[pary];
        }
        else 
        {
            par[parx] = pary; 
            size[pary] += size[parx];
        }
    }
};

int main()
{
    int n, m; cin >> n >> m; 
    vector<vector<int>> participants(m); 
    for (int i = 0; i < n; i++)
    {
        int size; cin >> size; 
        for (int j = 0; j < size; j++)
        {
            int x; cin >> x; 
            participants[x - 1].push_back(i); 
        }
    }
    union_find uf(n); 
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < (int) participants[i].size(); j++)
        {
            uf.unite(participants[i][j], participants[i][j - 1]); 
        }
    }
    bool ans = (uf.size[uf.find(0)] == n); 
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

