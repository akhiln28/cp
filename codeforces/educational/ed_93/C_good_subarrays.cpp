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
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n;
        vector<int> v(n + 1), cum(n + 1);
        map<int, int> mp; mp[0]++;
        char ch;
        for (int i = 1; i <= n; i++)
        {
            cin >> ch;
            v[i] = ch - '0' - 1;
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cum[i] = cum[i - 1] + v[i];
            if (mp.find(cum[i]) != mp.end())
            {
                ans += mp[cum[i]];
            }
            mp[cum[i]]++;
        }
        cout << ans << endl;
    }
}