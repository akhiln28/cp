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
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> dp(n);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
        for (int j = i - 1; j >= 0 && j >= i - k; j--)
        {
            dp[i] = min(dp[i], dp[j] + abs(v[j] - v[i]));
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}