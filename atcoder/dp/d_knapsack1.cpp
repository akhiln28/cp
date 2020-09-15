#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

#pending

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> weights(n), values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i] >> values[i];
    }
    int dp[101][100001]; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (j == w) dp[i][w] = 0;
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
            }
        }
    }
    cout << dp[n - 1][w] << endl;
    return 0;
}