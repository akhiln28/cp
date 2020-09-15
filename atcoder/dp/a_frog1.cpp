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
    int n; cin >> n;
    vector<int> v(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> dp(n);
    dp[0] = 0; dp[1] = abs(v[1] - v[0]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(v[i] - v[i - 1]), dp[i - 2] + abs(v[i] - v[i - 2]));
    }
    
    cout << dp[n - 1] << endl;
    return 0;
}

