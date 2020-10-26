#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

class unf
{
    vector<int> par, sz;
    int components;
    unf(int n) : par(n), sz(n, 1)
    {
        components = n;
        iota(par.begin(), par.end(), 0);
    }
    int find(int x)
    {
        return par[x] == x ? x : (par[x] = find(par[x]));
    }
    bool unite(int x, int y)
    {
        int parx = find(x), pary = find(y);
        if (parx == pary) return false;
        if (sz[parx] > sz[pary])
        {
            par[pary] = parx;
            sz[parx] += sz[pary];
        }
        else
        {
            par[parx] = pary;
            sz[pary] += sz[parx];
        }
        return true;
    }
};

int main()
{
int T; cin >> T;
for (int t = 1; t <= T; t++)
{}
}