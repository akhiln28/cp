#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long ans = 0, min_v = INT64_MAX;
        for (size_t i = 0; i < n; i++)
        {
            min_v = min(min_v, v[i]);
            ans += min_v;
        }
        cout << ans << endl;
    }
    return 0;
}