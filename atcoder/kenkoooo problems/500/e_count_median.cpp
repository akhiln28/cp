/*
    title: e_count_median.cpp
    author: Akhil
    date: 2020-10-11
    time: 10:06:43
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
    size_t n; cin >> n; 
    vector<long long> a(n), b(n); 
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i]; 
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto med = [](vector<long long> &v){
        if (v.size() & 1) return (double) v[v.size()/2]; 
        else return (double)(v[v.size()/2] + v[v.size()/2 - 1])/2.0; 
    };
    long long ans; 
    if (n & 1) ans = med(b) - med(a) + 1;
    else ans = 2 * (med(b) - med(a)) + 1;
    cout << ans << endl;
    return 0;
}
