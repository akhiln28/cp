/*
    title: d_practical_skill_test.cpp
    author: Akhil
    date: 2020-10-14
    time: 16:33:49
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

using namespace std;

int main()
{
    int h, w, d; cin >> h >> w >> d;
    vector<vector<int>> a(h, vector<int>(w));
    vector<int> v; 
    unordered_map<int, pair<int, int>> loc;
    unordered_map<int, long long> cum;
    for (size_t i = 0; i < h; i++)
    {
        for (size_t j = 0; j < w; j++)
        {
            cin >> a[i][j]; 
            v.push_back(a[i][j]); 
            loc[a[i][j]] = {i, j}; 
        }
    }
    sort(v.begin(), v.end());
    for (size_t i = 0; i < v.size(); i++)
    {
        if (cum.find(v[i] - d) == cum.end())
        {
            cum[v[i]] = 0; 
        }
        else 
        {
            auto p1 = loc[v[i] - d], p2 = loc[v[i]]; 
            cum[v[i]] = cum[v[i] - d] + abs(p1.first - p2.first) + abs(p1.second - p2.second); 
        }
    }
    int q; cin >> q; 
    for (size_t i = 0; i < q; i++)
    {
        int l, r; cin >> l >> r; 
        cout << cum[r] - cum[l] << endl;
    }
    return 0;
}
