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
        int n, k; cin >> n >> k;
        vector<int> v(n); 
        for (auto &i : v) cin >> i; 
        int id = min_element(v.begin(), v.end()) - v.begin(); 
        int ans = 0; 
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] < k and i != id) ans += (k - v[i])/v[id];  
        }
        cout << ans << endl;
    }
    return 0;
}
