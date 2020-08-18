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

// https://codeforces.com/problemset/problem/1188/A1

int main()
{
    int n; cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() == 2)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}