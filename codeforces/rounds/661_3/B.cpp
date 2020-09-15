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
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (size_t i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int min_a = *min_element(a.begin(), a.end());
        int min_b = *min_element(b.begin(), b.end());
        for (size_t i = 0; i < n; i++)
        {
            a[i] -= min_a;
            b[i] -= min_b;
        }
        long long ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            ans += max(a[i], b[i]);
        }
        cout << ans << endl;
    }

    return 0;
}