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

long long mod = 1e9 + 7;

using namespace std;

int main()
{
    int n; cin >> n;
    long long total = 1;
    for (int i = 0; i < n; i++)
    {
        total = (total * 10) % mod;
    }
    long long total09 = 1;
    for (int i = 0; i < n; i++)
    {
        total09 = (total09 * 8) % mod;
    }
    long long total0 = 1;
    for (int i = 0; i < n; i++)
    {
        total0 = (total0 * 9) % mod;
    }
    cout << (total - total0 * 2 + total09 + 2 * mod) % mod << endl;
    return 0;
}