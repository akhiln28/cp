#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    int n; cin >> n;
    int hap[3][n];
    for (int i = 0; i < n; i++)
    {
        cin >> hap[0][i] >> hap[1][i] >> hap[2][i];        
    }
    int dp[3][n]; dp[0][0] = hap[0][0], dp[1][0] = hap[1][0], dp[2][0] = hap[2][0];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = max(dp[1][i - 1] + hap[0][i], dp[2][i - 1] + hap[0][i]);
        dp[1][i] = max(dp[0][i - 1] + hap[1][i], dp[2][i - 1] + hap[1][i]);
        dp[2][i] = max(dp[0][i - 1] + hap[2][i], dp[1][i - 1] + hap[2][i]);
    }
    cout << max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n - 1])) << endl;
}

