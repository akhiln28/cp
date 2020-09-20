/*
    title: E.cpp
    author: Akhil
    date: 2020-09-19
    time: 18:32:13
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

int main()
{
    long long n, x, m; cin >> n >> x >> m;
    vector<long long> v;
    v.push_back(x);
    unordered_set<long long> s;
    s.insert(x);
    while (true)
    {
        x = (x * x) % m;
        if (s.count(x)) break;
        else v.push_back(x), s.insert(x);
    }
    long long idx = -1; 
    for (int i = 0; i < (int) v.size(); i++) if (v[i] == x) {idx = i; break;}
    long long ans = accumulate(v.begin(), v.begin() + (int) min(n, idx), 0LL); 
    n -= idx;
    if (n <= 0) {cout << ans << endl; return 0;}
    ans += n / (v.size() - idx) * accumulate(v.begin() + idx, v.end(), 0LL);
    n %= (v.size() - idx);
    ans += accumulate(v.begin() + idx, v.begin() + idx + n, 0LL); 
    cout << ans << endl;
    return 0;
}