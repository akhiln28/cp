#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 100001
#define m 998244353

using namespace std;

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int dp[C - A + 1][D - B + 1];

    dp[C - A][D - B - 1] = C;
    for (size_t i = D - B - 2 ; i >= 0; i--)
    {
        dp[C - A][i] = (C * dp[C - A][i + 1]) % m;
    }
    dp[C - A - 1][D - B] = D;
    for (size_t i = C - A - 2 ; i >= 0; i--)
    {
        dp[i][D - B] = (D * dp[i + 1][D - B]) % m; 
    }
    dp[C - A][D - B] = 0;

    for (int i = C - A - 1; i >= 0; i--)
    {
        for (int j = D - B - 1; j >= 0; j--)
        {
            dp[i][j] = (((j + B) * dp[i + 1][j]) % m + ((i + A) * dp[i][j + 1]) % m) % m;
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}