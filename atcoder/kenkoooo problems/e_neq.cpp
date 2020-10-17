#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

const int max_n = 5e5 + 1;

long long fact[max_n];

long long mod = 1e9 + 7;

long long mpow(long long a, long long x)
{
    if (x == 0 or a == 1) return 1;
    long long temp = mpow(a, x/2);
    if (x & 1) return (temp * ((temp * a) % mod)) % mod;
    else return (temp * temp) % mod;
}

long long inverse(long long a)
{
    return mpow(a, mod - 2);
}

long long npr(long long n, long long r)
{
    return (fact[n] * inverse(fact[n - r])) % mod;
}
long long ncr(long long n, long long r)
{
    return (fact[n] * ((inverse(fact[n - r]) * inverse(fact[r])) % mod)) % mod;
}

int main()
{
    long long n, m; cin >> n >> m;
    fact[0] = 1;
    for (long long i = 1; i < max_n; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    long long t1 = npr(m, n);
    long long t2 = t1; 
    for (long long i = 1; i <= n; i++)
    {
        long long t = (npr(m - i, n - i) * ncr(n, i)) % mod;
        if (i & 1) t2 = (t2 - t) % mod;
        else t2 = (t2 + t) % mod;
    }
    long long ans = ((t1 * t2) % mod + mod) % mod;
    cout << ans << endl;
    return 0; 
}