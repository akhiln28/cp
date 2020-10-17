/*
    title: B.cpp
    author: Akhil
    date: 2020-09-27
    time: 20:33:05
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
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, u; cin >> n >> u; 
        vector<int> v(n), ans(n); 
        for (auto &i : v) cin >> i;
        if (u & 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (v[i] & 1) cout << "1 "; 
                else cout << "0 "; 
            }
            cout << endl;
            continue;
        }
        unordered_map<int, vector<int>> mp; 
        for (int i = 0; i < n; i++)
        {
            if (mp.find(u - v[i]) != mp.end())
            {
                int id = mp[u - v[i]].back(); 
                ans[i] = 1 - ans[id]; 
            }
            else ans[i] = 1; 
            mp[v[i]].push_back(i); 
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}

