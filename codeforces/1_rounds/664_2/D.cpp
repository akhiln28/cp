#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main()
{
    int n, d;
    long long m;
    cin >> n >> d >> m;
    vector<long long> large, small;
    for (int i = 0; i < n; i++)
    {
        long long x; cin >> x;
        if (x > m) large.push_back(x);
        else small.push_back(x);
    }
    sort(large.rbegin(), large.rend());
    sort(small.rbegin(), small.rend());
    for (int i = 1; i < large.size(); i++) large[i] += large[i - 1];
    for (int i = 1; i < small.size(); i++) small[i] += small[i - 1];
    
    long long ans = 0;
    if (small.size() > 0) ans = small[small.size() - 1];
    int t = (n % (d + 1) == 0) ? n / (d + 1) : n / (d + 1) + 1; 
    if (t > 0 && t <= large.size()) ans = max(ans, large[t - 1]);
    for (int i = 0; i < small.size(); i++)
    {
        t = ((n - 1 - i)%(d + 1) == 0) ? (n - 1 - i)/(d + 1) : (n - 1 - i)/(d + 1) + 1;
        if (t > 0 && t <= large.size()) ans = max(ans, small[i] + large[t - 1]);
    }
    cout << ans << endl;
    return 0;
}