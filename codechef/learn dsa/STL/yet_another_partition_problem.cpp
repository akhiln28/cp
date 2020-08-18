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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    set<int> s;
    s.insert(0); cin >> a[0];
    for (size_t i = 1; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % a[i - 1] != 0) s.insert(i);
    }
    for (int i = 0; i < q; i++)
    {
        int t, idx;
        cin >> t >> idx; idx--;
        if (t == 1)
        {
            int x; cin >> x;
            a[idx] = x;
            s.insert(idx);
            if (idx < n - 1) s.insert(idx + 1);
            if (idx > 0 && a[idx] % a[idx - 1] == 0) s.erase(idx);
            if (idx < n - 1 && a[idx + 1] % a[idx] == 0) s.erase(idx + 1);
        }
        else
        {
            auto it = s.upper_bound(idx); it--;
            cout << *it + 1 << endl;
        }
    }
}