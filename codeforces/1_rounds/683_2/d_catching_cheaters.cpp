/*
    title: d_catching_cheaters.cpp
    author: Akhil
    date: 2020-11-16
    time: 19:09:39
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
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

void solve()
{
    int n, m; cin >> n >> m;
    string str1, str2; 
    cin >> str1 >> str2; 
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    int ans = 0; 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 2; 
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j] - 1, dp[i][j - 1] - 1); 
                dp[i][j] = max(dp[i][j], 0); 
            }
            ans = max(ans, dp[i][j]); 
        }
    }
    cout << ans << endl;
}

int main()
{
    solve(); 
    return 0;
}
