/*
    title: e.cpp
    author: Akhil
    date: 2020-12-13
    time: 18:09:17
*/
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
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
#include <string.h>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> A(n), B(m); 
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> B[i]; 
    }
    int dp[n + 1][m + 1]; 
    memset(dp, 1e6, (n + 1) * (m + 1) * sizeof(int));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i; 
            else
            {
                dp[i][j] = min({1 + dp[i - 1][j - 1], 1 + dp[i - 1][j], 1 + dp[i][j - 1]});
                if (A[i - 1] == B[j - 1]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]); 
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
