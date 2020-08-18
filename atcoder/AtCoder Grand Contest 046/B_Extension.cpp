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
#define m 998244353

using namespace std;

long long ncr(int n, int r)
{
    if (r == 0 || r == n) return 1;
    if (r > n/2) r = n - r;
    long long ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans *= (n - r + i);
        ans /= i;
    }
    return ans;
}

int main()
{
    cout << ncr(52, 1) << endl;
    return 0;
}