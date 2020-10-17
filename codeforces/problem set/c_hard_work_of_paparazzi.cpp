/*
    title: c_hard_work_of_paparazzi.cpp
    author: Akhil
    date: 2020-10-11
    time: 11:55:05
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
    int r, n; cin >> r >> n; 
    struct celeb
    {
        int t, x, y; 
        bool reach(celeb &c1)
        {
            return (c1.t - t >= abs(c1.x - x) + abs(c1.y - y));
        }
    };
    vector<celeb> v(n + 1); 
    v[0] = {0, 1, 1}; 
    for (size_t i = 1; i <= n; i++)
    {
        int t, x, y; cin >> t >> x >> y; 
        v[i] = {t, x, y}; 
    }
    vector<int> dp(n + 1, -1); 
    dp[0] = 0;
    int ans = 0; 
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= max(0, i - 4 * r - 1); j--)
        {
            if (v[j].reach(v[i]) and dp[j] != -1) dp[i] = max(dp[i], dp[j] + 1);  
        }
        ans = max(ans, dp[i]); 
    }
    cout << ans << endl;
    return 0;
}