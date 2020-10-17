/*
    title: B.cpp
    author: Akhil
    date: 2020-10-11
    time: 14:45:14
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
        for (int i = 0; i < n; i++)
        {
            cin >> v[i]; 
        }
        sort(v.rbegin(), v.rend());
        long long ans = accumulate(v.begin(), v.begin() + k + 1, 0LL);
        cout << ans << endl; 
    }
    return 0;
}
