#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 300

using namespace std;

// https://codeforces.com/contest/1398/problem/D

int dp[max_n][max_n][max_n];

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    vector<int> R(r + 1), G(g + 1), B(b + 1);
    for (int i = 1; i <= r; i++)
    {
        cin >> R[i];
    }
    for (int i = 1; i <= g; i++)
    {
        cin >> G[i];
    }
    for (int i = 1; i <= b; i++)
    {
        cin >> B[i];
    }
    sort(R.begin(), R.end());
    sort(G.begin(), G.end());
    sort(B.begin(), B.end());

    dp[0][0][0] = 0;

    for (int i = 0; i <= r; i++)
    {
        for (int j = 0; j <= g; j++)
        {
            for (int k = 0; k <= b; k++)
            {
                if (i && j) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + R[i]*G[j]); 
                if (j && k) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + G[j]*B[k]); 
                if (i && k) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + R[i]*B[k]); 
            }
        }
    }
    cout << dp[r][g][b] << endl;
    return 0;
}