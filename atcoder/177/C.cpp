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
#define mod 1000000007

using namespace std;

int main()
{
    int n; cin >> n;
    vector<long long> v(n), cum(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    long long ans = 0; 
    cum[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        cum[i] = (cum[i - 1] + v[i]) % mod;
    }
    for (int i = 0; i < n; i++)
    {
        ans = (ans + (v[i] * (cum[n - 1] - cum[i] + mod) % mod) % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}