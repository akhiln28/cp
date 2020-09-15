#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

int mod = 1e9 + 7;

using namespace std;

int main()
{
    long long n, k, d; cin >> n >> k >> d;
    vector<long long> dpk(n + 1, 0), dpd(n + 1, 0);
    dpk[0] = 1, dpd[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0 && j >= i - k; j--)
        {
            dpk[i] = (dpk[i] + dpk[j]) % mod;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0 && j >= i - (d - 1); j--)
        {
            dpd[i] = (dpd[i] + dpd[j]) % mod;
        }
    }
    cout << (dpk[n] - dpd[n] + mod) % mod << endl;
    return 0; 
}