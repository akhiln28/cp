#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 100001

using namespace std;

long long diff(vector<int> &v, int c)
{
    long long x = 1, ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans += abs(v[i] - x), x *= c;
    }
    return ans;
}

int main()
{
    int n; cin >> n;
    long long sum = 0; 
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long prev_diff = diff(v, 1);
    long long ans = prev_diff;
    int c = 2;
    for (c = 2; c < pow(1e18, 1.0/n); c++)
    {
        long long cur_diff = diff(v, c);
        ans = min(ans, cur_diff);
        if (cur_diff > prev_diff) break;
        else prev_diff = cur_diff;
    }
    cout << ans << endl;
    return 0;
}