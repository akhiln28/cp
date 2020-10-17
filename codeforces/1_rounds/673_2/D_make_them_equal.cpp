/*
    title: D.cpp
    author: Akhil
    date: 2020-09-27
    time: 22:16:14
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <unordered_map>
#include <set> 
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
        int n; cin >> n; 
        vector<int> v(n); 
        for (int &i : v) cin >> i; 
        int sum = accumulate(v.begin(), v.end(), 0); 
        if (sum % n != 0) {cout << - 1 << endl; continue;}
        int val = sum/n; 
        vector<vector<int>> ans; 
        for (int i = 1; i < n; i++)
        {
            if (v[i] % (i + 1) == 0) 
            {
                ans.push_back({i + 1, 1, v[i]/(i + 1)});
                v[0] += v[i], v[i] = 0; 
            }
            else 
            {
                int t = (i + 1) - v[i] % (i + 1);
                ans.push_back({1, i + 1, t}); 
                v[0] -= t, v[i] += t;
                ans.push_back({i + 1, 1, v[i]/(i + 1)}); 
                v[0] += v[i], v[i] = 0; 
            }
        }
        for (int i = 1; i < n; i++)
        {
            ans.push_back({1, i + 1, val}); 
            v[i] = val, v[0] -= val; 
        }
        cout << ans.size() << endl; 
        for (auto i : ans)
        {
            for (auto j : i) cout << j << " ";
            cout << endl;
        }
    }
    return 0;
}
