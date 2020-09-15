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
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n), b(m);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    vector<long long> prefa(n), prefb(m);
    prefa[0] = a[0], prefb[0] = b[0];
    for (int i = 1; i < n; i++) prefa[i] = a[i] + prefa[i - 1];
    for (int i = 1; i < m; i++) prefb[i] = b[i] + prefb[i - 1];

    int ans = distance(prefb.begin(), upper_bound(prefb.begin(), prefb.end(), k)); 
    for (int i = 0; i < n; i++)
    {
        if (prefa[i] <= k) {ans = max(ans, i + 1 + (int)distance(prefb.begin(), upper_bound(prefb.begin(), prefb.end(), k - prefa[i])));}
    }
    cout << ans << endl;
    return 0; 
}