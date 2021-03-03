/*
    title: d.cpp
    author: Akhil
    date: 2020-11-08
    time: 18:00:39
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
    int n; cin >> n; 
    vector<long long> v(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> v[i]; 
    }
    vector<long long> cum(n); 
    cum[0] = v[0]; 
    for (int i = 1; i < n; i++)
    {
        cum[i] = cum[i - 1] + v[i]; 
    }
    vector<long long> dist(n); 
    dist[0] = v[0]; 
    for (int i = 1; i < n; i++)
    {
        dist[i] = dist[i - 1] + cum[i];
    }
    vector<long long> pref_max(n); 
    pref_max[0] = cum[0]; 
    for (int i = 1; i < n; i++)
    {
        pref_max[i] = max(pref_max[i - 1], cum[i]); 
    }
    
    long long ans = max(0LL, dist[0]); 
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, dist[i - 1] + pref_max[i]);
    }
    cout << ans << endl;
    return 0;
}
