/*
    title: e_picking_goods.cpp
    author: Akhil
    date: 2020-09-19
    time: 09:16:14
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

long long inf = -1e15;

using namespace std;

int main()
{
    int R, C, K; cin >> R >> C >> K;
    vector<vector<int>> mat(R + 1, vector<int>(C + 1, 0));
    for (int i = 0; i < K; i++)
    {
        int r, c, v; cin >> r >> c >> v;
        mat[r][c] = v;
    }
    vector<vector<vector<long long >>> dp(R + 1, vector<vector<long long >> (C + 1, vector<long long> (4, 0)));
    for (int k = 0; k < 4; k++) dp[R][C][k] = (k) ? mat[R][C] : 0; 
    for (int r = R; r >= 1; r--)
    {
        for (int c = C; c >= 1; c--)
        {
            for (int k = 0; k < 4; k++)
            {
                if (r < R) 
                {
                    for (int k1 = 0; k1 < 4; k1++)
                        dp[r][c][k] = max(dp[r][c][k], ((k) ? dp[r + 1][c][k1] + mat[r][c] : dp[r + 1][c][k1]));
                    dp[r][c][k] = max(dp[r][c][k], dp[r + 1][c][k]);
                }
                if (c < C) 
                {
                    dp[r][c][k] = max(dp[r][c][k], (k) ? dp[r][c + 1][k - 1] + mat[r][c] : dp[r][c + 1][0]);
                    dp[r][c][k] = max(dp[r][c][k], dp[r][c + 1][k]);
                }
            }
        }
    }
    long long ans = 0; 
    for (int k = 0; k < 4; k++) ans = max(ans, dp[1][1][k]); 
    cout << ans << endl;
    return 0;
}