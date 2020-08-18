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
    DATE: 18-08-2020
    TIME: 15:55:12
    SOURCE: https://codeforces.com/problemset/problem/1272/D
*/

int main()
{
    int n; cin >> n;
    vector<int> v(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // first find all the strictly increasing sub arrays
    vector<vector<int>> cis;
    vector<int> sub; sub.push_back(0);
    for (int i = 1; i < n; i++)
    {
        if (sub.empty()) sub.push_back(i);
        else if (v[i] > v[sub.back()]) sub.push_back(i);
        else 
        {
            cis.push_back(sub); sub.clear();
            sub.push_back(i);
        }
    }
    if (sub.size()) cis.push_back(sub);

    int ans = cis[0].size();
    for (int i = 1; i < cis.size(); i++)
    {
        ans = max(ans, (int)cis[i].size());
        if (cis[i].front() == cis[i - 1].back() + 1)
        {
            bool f1 = (cis[i - 1].size() >= 2 && v[*prev(cis[i - 1].end(), 2)] < v[cis[i].front()]);
            bool f2 = (cis[i].size() >= 2 && v[cis[i][1]] > v[cis[i - 1].back()]);
            if (f1 || f2) ans = max(ans, (int)cis[i - 1].size() + (int)cis[i].size() - 1);
        }
        if (cis[i].front() == cis[i - 1].back() + 2)
        {
            if (v[cis[i - 1].back()] < v[cis[i].front()]) ans = max(ans, (int) cis[i - 1].size() + (int) cis[i].size());
        }
    }
    cout << ans << endl;
    return 0;
}

