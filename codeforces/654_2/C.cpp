#include <iostream>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

bool ans(long long a, long long b, long long n, long long m)
{
    cout << a << " " << b << " " << n << " " << m << endl;
    if (n == 0 && m == 0)
        return true;
    if (n == 0)
    {
        if (a > b)
        {
            if (b < m)
                return false;
            else
                return true;
        }
        else
        {
            if (a < m)
                return false;
            else
                return true;
        }
    }
    if (m == 0)
    {
        if (a > b)
        {
            long long t1 = min((long long)1, min(a - b, n));
            return ans(a - t1, b, n - t1, 0);
        }
        else
        {
            long long t2 = min((long long)1, min(b - a, n));
            return ans(a, b - t2, n - t2, 0);
        }
    }
    if (a > b)
    {
        long long t1 = min(a - b, n);
        bool ans1 = ans(a - t1, b, n - t1, m);
        bool ans2 = (m <= b) && ans(a, b - m, n, 0);
        return ans1 || ans2;
    }
    else
    {
        bool ans1 = (n <= b) && ans(a, b - n, 0, m);
        bool ans2 = (m <= a) && ans(a - m, b, n, 0);
        return ans1 || ans2;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    long long a, b, n, m;
    while (t--)
    {
        cin >> a >> b >> n >> m;
        cout << ans(a, b, n, m);
    }
    return 0;
}