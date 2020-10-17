/*
    title: C.cpp
    author: Akhil
    date: 2020-09-27
    time: 20:33:11
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
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

int is_possible(vector<int> v, int k)
{
    multiset<int> s; 
    for (int i = 0; i < k; i++) s.insert(v[i]); 
    int l = 0; 
    for (int i = k; i < v.size(); i++)
    {
        if (s.count(v[i])) s.insert(v[i]); 
        auto it = s.find(v[l]); 
        if (it != s.end()) s.erase(it);
        l++; 
    }
    if (s.size()) return *s.begin(); 
    return -1; 
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n; 
        vector<int> v(n); 
        for (auto &i : v) cin >> i;
        int l = 0, r = n / 2 + 1, ans = n, val; 
        while (l <= r)
        {
            int m = l + (r - l)/2;
            int tmp = is_possible(v, m); 
            if (tmp != -1) ans = min(ans, m), val = tmp, r = m - 1; 
            else l = m + 1; 
        }
        for (int i = 1; i <= n; i++)
        {
            if (i < ans) cout << -1 << " "; 
            else cout << val << " "; 
        }
        cout << endl;
    }
    return 0;
}
