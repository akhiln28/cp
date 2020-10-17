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

long long solve(long long a, long long b, long long x, long long y, long long n)
{
    long long a1 = max(x, a - n), b1 = b;
    n -= (a - a1);
    if (n > 0) b1 = max(y, b - n);
    return a1 * b1;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        long long a, b, x, y, n; cin >> a >> b >> x >> y >> n;
        cout << min(solve(a, b, x, y, n), solve(b, a, y, x, n)) << endl;
    }

    return 0;
}