/*
    title: c_gcd_on_blackboard.cpp
    author: Akhil
    date: 2020-10-13
    time: 08:36:15
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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> pref(n), suff(n);
    pref[0] = v[0];
    for (int i = 1; i < n; i++) pref[i] = __gcd(pref[i - 1], v[i]);
    suff[n - 1] = v[n - 1]; 
    for (int i = n - 2; i >= 0; i--) suff[i] = __gcd(suff[i + 1], v[i]); 
    int ans = max(suff[1], pref[n - 2]); 
    for (int i = 1; i < n - 1; i++)
    {
        ans = max(ans, __gcd(pref[i - 1], suff[i + 1])); 
    }
    cout << ans << endl;
    return 0;
}
