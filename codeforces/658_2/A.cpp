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
        int n, m;
        cin >> n >> m;
        int x;
        map<int, int> mp;
        for (size_t i = 0; i < n; i++)
        {
            cin >> x;
            mp[x]++;
        }
        int count = 0, ans = -1;
        for (size_t i = 0; i < m; i++)
        {
            cin >> x;
            if (mp.find(x) != mp.end())
            {
                ans = x;
                count++;
            }
        }
        if (ans != -1)
        {
            cout << "YES" << endl;
            cout << 1 << " " << ans << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}