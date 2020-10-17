#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    long long sum = 0; 
    for (int i = 0; i < n; i++)
    {
        cin >> v[i]; sum += v[i];
    }
    if (n < 3) {cout << 0 << endl; return 0;};
    if (sum % 3 != 0) {cout << 0 << endl; return 0;}; 

    vector<long long> prefix_sum(n), suffix_sum(n);
    prefix_sum[0] = v[0];
    for (int i = 1; i < n; i++) prefix_sum[i] = prefix_sum[i - 1] + v[i];
    suffix_sum[n - 1] = v[n - 1]; 
    for (int i = n - 2; i >= 0; i--) suffix_sum[i] = suffix_sum[i + 1] + v[i];

    vector<int> pref, suff;
    for (int i = 0; i < n; i++)
        if (prefix_sum[i] == sum / 3) pref.push_back(i);
    for (int i = 0; i < n; i++) 
        if (suffix_sum[i] == sum / 3) suff.push_back(i);
    long long ans = 0; 
    
    for (int i = 0; i < pref.size(); i++)
    {
        ans += distance(suff.end(), upper_bound(suff.begin(), suff.end(), pref[i] + 1));
    }
    cout << abs(ans) << endl;
}