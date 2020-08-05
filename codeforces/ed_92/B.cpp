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

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n, k, z;
        cin >> n >> k >> z;
        vector<int> v(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        map<pair<int, int>, int> dp;
        dp[{0, 0}] = v[0];

        for (int i = 0; i < k; i++)
        {
            map<pair<int, int>, int> tmp;
            for (auto it : dp)
            {
                auto loc = it.first;
                auto val = it.second;
                if (loc.second < z && loc.first >= 1)
                    tmp[{loc.first - 1, loc.second + 1}] = val + v[loc.first - 1];
                if (loc.first < n - 1)
                    tmp[{loc.first + 1, loc.second}] = val + v[loc.first + 1];
            }
            swap(dp, tmp);
        }
        int ans = 0;
        for (auto it : dp)
            ans = max(ans, it.second);
        cout << ans << endl;
    }

    return 0;
}