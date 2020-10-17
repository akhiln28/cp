#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <set>
#include <stdlib.h>

#define max_n 100001

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        vector<int> v(n), ans(n);
        for (size_t i = 0; i < n; i++)
        {
            char ch; cin >> ch;
            v[i] = ch - '0';
        }

        set<int> end[2];
        int set_count = 0;

        for (size_t i = 0; i < n; i++)
        {
            if (end[1 - v[i]].empty())
            {
                set_count++;
                end[v[i]].insert(set_count);
                ans[i] = set_count;
            }
            else
            {
                auto it = end[1 - v[i]].begin();
                ans[i] = *it;
                end[1 - v[i]].erase(it);
                end[v[i]].insert(ans[i]);
            }
        }
        cout << set_count << endl;
        for (size_t i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }cout << endl;

    }
    return 0;
}