/*
    title: c_george_and_job.cpp
    author: Akhil
    date: 2020-10-06
    time: 15:24:11
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
    int n, m, k; 
    cin >> n >> m >> k;
    vector<long long> v(n + 1); 
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i]; 
    }
    vector<long long> cum(n + 1); 
    cum[1] = v[1];
    for (int i = 2; i <= n; i++) cum[i] = cum[i - 1] + v[i]; 

    vector<vector<long long>> dp(n + 1, vector<long long> (k + 1)); 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i < j * m) continue; 
            dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + cum[i] - cum[i - m]); 
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}