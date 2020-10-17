/*
    title: c_eugene_and_an_array.cpp
    author: Akhil
    date: 2020-10-06
    time: 19:49:06
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
    vector<long long> v(n + 1), cum(n + 1); 
    for (int i = 1; i < n + 1; i++) cin >> v[i]; 
    for (int i = 1; i < n + 1; i++) cum[i] = cum[i - 1] + v[i]; 
    unordered_map<long long, long long> mp; 
    mp[0] = 0; 
    long long ans = 0, prev = -1; 
    for (int i = 1; i < n + 1; i++)
    {
        if (mp.find(cum[i]) != mp.end())
        {
            prev = max(prev, mp[cum[i]]); 
            ans += i - prev - 1; 
        }
        else ans += i - prev - 1; 
        mp[cum[i]] = i;  
    }
    cout << ans << endl;
    return 0;
}