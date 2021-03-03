/*
    title: c_division.cpp
    author: Akhil
    date: 2020-11-01
    time: 20:04:58
*/
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

vector<pair<long long, int>> prime_factors(long long n)
{
    vector<pair<long long, int>> ans; 
    int i = 2; 
    while(true)
    {
        if (n % i == 0)
        {
            int exp = 0; 
            while (n % i == 0) exp++, n /= i; 
            ans.push_back({i, exp});
            if (n == 1) break;
        }
        i++;
    }
    return ans; 
}

int exp(long long &n, long long f)
{
    int ans = 0; 
    while (n % f == 0) ans++, n /= f;
    return ans; 
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        long long p, q; cin >> p >> q;
        vector<pair<long long, int>> prime_factors_q = prime_factors(q); 
        long long ans = 0; 
        for (auto f : prime_factors_q)
        {
            long long tp = p; 
            int e = exp(tp, f.first); 
            // cout << f.first << " " << f.second << endl;
            long long temp = tp * pow(f.first, (e, f.second - 1));
            ans = max(ans, temp); 
        }
        cout << ans << endl;
    }
    return 0;
}