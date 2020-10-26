/*
    title: d_caesars_legions.cpp
    author: Akhil
    date: 2020-10-19
    time: 08:23:24
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

#define max_n 101

int mod = 1e8; 

using namespace std;

int main()
{
    int n1, n2, k1, k2; cin >> n1 >> n2 >> k1 >> k2; 
    vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>> (n2 + 1, vector<int>(2))); 
    dp[0][0][0] = dp[0][0][1] = 1; 
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            for (int k = i - 1; k >= i - min((int)i, k1); k--)
            {
                dp[i][j][0] = (dp[i][j][0] + dp[k][j][1]) % mod; 
            }
            for (int k = j - 1; k >= j - min((int)j, k2); k--)
            {
                dp[i][j][1] = (dp[i][j][1] + dp[i][k][0]) % mod; 
            }
        }
    }
    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % mod << endl;
    return 0;
}
