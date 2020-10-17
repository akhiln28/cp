/*
    title: B.cpp
    author: Akhil
    date: 2020-10-17
    time: 16:32:56
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
    int n; cin >> n; 
    vector<long long> v(n); 
    for (auto &e : v) cin >> e; 
    long long ans1 = 0;
    long double ans2 = 0;
    long long ans3 = 0; 
    for (int i = 0; i < n; i++)
    {
        ans1 += abs(v[i]);
        ans2 += v[i] * v[i]; 
        ans3 = max(ans3, abs(v[i])); 
    }
    ans2 = sqrt(ans2); 
    cout.precision(15);
    cout << ans1 << endl;
    cout << fixed << ans2 << endl;
    cout << ans3 << endl;
    return 0;
}
