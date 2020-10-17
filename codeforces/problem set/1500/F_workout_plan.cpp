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

/*
    DATE: 16-08-2020
    TIME: 19:44:42
    SOURCE: https://codeforces.com/problemset/problem/1218/F
*/

long long top(multiset<long long> &s, int cnt)
{
    if (cnt > s.size()) return -1;
    else 
    {
        long long ans = 0;
        while (cnt > 0)
        {
            ans += *s.begin(), s.erase(s.begin()), cnt--;
        }
        return ans;
    }
}
int main()
{
    int n, k; cin >> n >> k;
    vector<int> v(n), costs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    long long A; cin >> A;
    for (int i = 0; i < n; i++)
    {
        cin >> costs[i];
    }
    multiset<long long> s;    
    long long cur = k, ans = 0;
    for (int i = 0; i < n; i++)
    {
        s.insert(costs[i]);
        if (cur < v[i])
        {
            int cnt = ceil((float) (v[i] - cur)/A); cur += cnt * A;
            long long cost = top(s, cnt);
            if (cost == -1)
            {
                cout << "-1" << endl;
                return 0;
            }
            else {
                ans += cost;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
