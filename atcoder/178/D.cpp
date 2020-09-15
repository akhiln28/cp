#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>


using namespace std;

long long p = 1e9 + 7;
long long const max_n = 10001;
long long fact[max_n];
long long ifact[max_n];

long long mod(long long x)
{
    x %= p; 
    if (x < 0) x += p; 
    return x;
}

long long inverse(long long x)
{
    x = mod(x);
    if (x == 1) return x;
    return mod(1LL * (-p/x) * inverse(p%x));
}

long long ncr(long n, long r)
{
    long long ret = (ifact[n - r] * ifact[r]) % p;
    ret = (ret * fact[n]) % p;
    return ret;
}


int main()
{
    int s; cin >> s;
    fact[0] = 1;
    for (int i = 1; i < max_n; i++)
    {
        fact[i] = mod(fact[i - 1] * i); 
    }
    ifact[0] = 1;
    for (int i = 1; i < max_n; i++)
    {
        ifact[i] = mod(ifact[i - 1] * inverse(i)); 
    }
    long long ans = 0; 
    for (int i = 1; 3 * i <= s; i++)
    {
        ans = mod(ans + ncr(s - 2 * i - 1, i - 1)); 
    }
    cout << ans << endl;
    return 0;
}