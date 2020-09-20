/*
    title: D.cpp
    author: Akhil
    date: 2020-09-19
    time: 17:46:12
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
#include <set>
#include <stdio.h>

using namespace std;

int mod = 998244353;

int main()
{
    int n, k; cin >> n >> k;
    vector<pair<int, int>> p(k);
    for (int i = 0; i < k; i++)
    {
        cin >> p[i].first >> p[i].second; 
    }
    sort(p.begin(), p.end());
    vector<int> dp(n + 1, 0), cum_dp(n + 1);
    dp[1] = 1;
    cum_dp[1] = 1;
    auto cum = [&cum_dp] (int i, int j)
    {
        return (cum_dp[j] - ((i >= 1) ? cum_dp[i - 1] : 0) + mod) % mod;
    };
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i - p[j].first >= 1)
            {
                dp[i] = (dp[i] + cum(i - p[j].second, i - p[j].first)) % mod;
            }
            else break;
        }
        cum_dp[i] = (cum_dp[i - 1] + dp[i]) % mod;
    }
    cout << dp[n] << endl;
    return 0;
}