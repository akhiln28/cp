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
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        for (int x = 1; x * x <= v[i]; x++)
        {
            if (v[i] % x != 0)
                continue;
            if (mp.find(x) != mp.end())
            {
                if ((x == v[i] && mp[v[i]] > 1) || x != v[i])
                {
                    ans--;
                    break;
                }
            }
            else if (mp.find(v[i] / x) != mp.end())
            {
                if ((v[i] / x == v[i] && mp[v[i]] > 1) || v[i] / x != v[i])
                {
                    ans--;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}