#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>
#define max_n 100001

using namespace std;

int mod = 1e9 + 7;

int main()
{
    int t, k; cin >> t >> k;
    vector<long long> ans(max_n, 0);
    ans[0] = 1;
    for (int i = 1; i < max_n; i++) ans[i] = (ans[i - 1] + ((i >= k) ? ans[i - k] : 0))% mod;
    
    vector<long long> cum(max_n, 0); cum[0] = ans[0];
    for (int i = 1; i < max_n; i++) cum[i] = cum[i - 1] + ans[i];
    
    for (int i = 0; i < t; i++)
    {
        int a, b; cin >> a >> b;
        cout << (cum[b] - cum[a - 1] + mod) % mod << endl;
    }
}