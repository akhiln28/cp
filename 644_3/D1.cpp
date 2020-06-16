#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    long t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        long ans = INT16_MIN;
        for (long i = 1; i * i <= n; i++)
        {
            if (n % i == 0 && i <= k)
                ans = max(ans, i);
            if (n % i == 0 && n / i <= k)
                ans = max(ans, n / i);
        }
        cout << n / ans << endl;
    }

    return 0;
}