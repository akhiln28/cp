/*
    title: C1.cpp
    author: Akhil
    date: 2020-09-27
    time: 21:37:18
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
        int n; cin >> n; 
        vector<int> v(n + 1); 
        for (int i = 1; i <= n; i++) 
        {
            int x; cin >> x; 
            v[i] = x; 
        }
        // mp <integer, vector of locations where integer occurs>
        unordered_map<int, vector<int>> mp; 
        for (int i = 1; i <= n; i++) if (mp[v[i]].size() == 0 or mp[v[i]].back() != 0) mp[v[i]].push_back(0);
        for (int i = 1; i <= n; i++) mp[v[i]].push_back(i); 
        for (int i = 1; i <= n; i++) if (mp[v[i]].back() != n + 1) mp[v[i]].push_back(n + 1); 
        // per[integer] is least period 
        unordered_map<int, int> per; 
        for (auto it : mp)
        {
            int ans = 0; 
            for (int i = 1; i < it.second.size(); i++) ans = max(ans, it.second[i] - it.second[i - 1]); 
            per[it.first] = ans; 
        }
        sort(v.begin() + 1, v.end()); 
        int i = 1; 
        vector<int> ans; 
        for (int k = n; k >= 1; k--)
        {
            while (i < v.size() and per[v[i]] > k) i++; 
            if (i == v.size()) ans.push_back(-1); 
            else ans.push_back(v[i]); 
        }
        reverse(ans.begin(), ans.end()); 
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl; 
    }
    return 0;
}
