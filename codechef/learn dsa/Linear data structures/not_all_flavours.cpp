/*
    title: not_all_flavours.cpp
    author: Akhil Nichenametla
    date: 2020-08-07
    time: 08:27:54
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

/*
Sample Input:
1
6 2
1 2 2 2 2 1
*/

int main()
{
    int T;
    cin >> T;
    for (size_t t = 0; t < T; t++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        map<int, set<int>> locs;
        for (size_t i = 0; i < n; i++)
        {
            cin >> v[i];
            locs[v[i]].insert(i);
        }
        int ans = 0;
        for (int i = 1; i <= k; i++)
        {
            set<int> locs_i = locs[i];
            int prev = -1;
            locs_i.insert(n);
            for (auto it1 : locs_i)
            {
                ans = max(ans, it1 - prev - 1);
                prev = it1;
            }
        }
        cout << ans << endl;
    }

}