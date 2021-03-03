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

#define ll long long

const int mod = 1e9 + 7; 

int main()
{
    int h, w; cin >> h >> w;
    char s[h][w];
    ll cumh[h][w], cumw[h][w], cumd[h][w], dp[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> s[i][j];
        }
    }
    memset(cumh, 0, sizeof(ll) * h * w); 
    memset(cumw, 0, sizeof(ll) * h * w); 
    memset(cumd, 0, sizeof(ll) * h * w); 
    memset(dp, 0, sizeof(ll) * h * w);

    for (int i = h - 1; i >= 0; i--)
    {
        for (int j = w - 1; j >= 0; j--)
        {
            if (i == h - 1 && j == w - 1) 
            {
                cumh[i][j] = 1, cumw[i][j] = 1, cumd[i][j] = 1, dp[i][j] = 1;    
                continue;
            }
            else if (s[i][j] == '.')
            {
                if (i + 1 < h) dp[i][j] = (cumh[i + 1][j] + dp[i][j]) % mod; 
                if (j + 1 < w) dp[i][j] = (cumw[i][j + 1] + dp[i][j]) % mod; 
                if (i + 1 < h && j + 1 < w) dp[i][j] = (cumd[i + 1][j + 1] + dp[i][j]) % mod; 
                cumh[i][j] = dp[i][j]; 
                cumw[i][j] = dp[i][j]; 
                cumd[i][j] = dp[i][j]; 
                if (i + 1 < h) cumh[i][j] = (cumh[i + 1][j] + cumh[i][j]) % mod;
                if (j + 1 < w) cumw[i][j] = (cumw[i][j + 1] + cumw[i][j]) % mod; 
                if (i + 1 < h && j + 1 < w) cumd[i][j] = (cumd[i + 1][j + 1] + cumd[i][j]) % mod;  
            }
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    cout << dp[0][0] << endl;
    return 0;
}