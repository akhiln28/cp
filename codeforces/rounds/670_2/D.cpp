#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <utility>

using namespace std;

int main()
{
    int n; cin >> n; 
    vector<int> v(n); 
    for (auto &i : v) cin >> i;
    vector<long long> diff(n); diff[0] = v[0];
    for (int i = 1; i < n; i++) diff[i] = v[i] - v[i - 1];
    long long sum = diff[0];
    for (int i = 1; i < n; i++) if (diff[i] > 0) sum += diff[i];

    cout << (long long) ceil(sum/2.0) << endl;

    int q; cin >> q;
    for (int i = 0; i < q; i++)
    {
        int l, r, x; cin >> l >> r >> x;
        if (diff[l - 1] > 0 or l == 1) 
        {
            sum -= diff[l - 1], diff[l - 1] += x; 
            if (diff[l - 1] > 0 or l == 1) sum += diff[l - 1];
        }
        else 
        {
            diff[l - 1] += x; 
            if (diff[l - 1] > 0) sum += diff[l - 1];
        }
        if (r != n) 
        {
            if (diff[r] > 0)
            {
                sum -= diff[r], diff[r] -= x;
                if (diff[r] > 0) sum += diff[r];
            }
            else {diff[r] -= x; if (diff[r] > 0) sum += diff[r];}
        }
        cout << (long long) ceil(sum/2.0) << endl;
    }
}