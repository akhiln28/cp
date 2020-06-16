#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <string>
#define LONG_MIN (-2147483647L - 1)

#define max_n
using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int sqrtn = sqrt(n);
        if (k >= n)
        {
            cout << '1' << endl;
        }
        else
        {
            // largest factor <= k
            long max_fac_lt_k = LONG_MIN;
            if (!(n & 1))
            {
                if (n / 2 <= k)
                    max_fac_lt_k = max(max_fac_lt_k, (long)n / 2);
                if (2 <= k)
                    max_fac_lt_k = max(max_fac_lt_k, (long)2);
            }
            for (long i = 3; i <= sqrtn; i += 2)
            {
                if (n % i == 0)
                {
                    if (i <= k)
                        max_fac_lt_k = max(max_fac_lt_k, (long)i);
                    if (n / i <= k)
                        max_fac_lt_k = max(max_fac_lt_k, (long)n / i);
                }
            }
            if (max_fac_lt_k == LONG_MIN)
            {
                cout << n << endl;
            }
            else
                cout << n / max_fac_lt_k << endl;
        }
    }
    return 0;
}
