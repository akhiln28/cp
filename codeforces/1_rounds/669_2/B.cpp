#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_set>
#include <vector>
#include <climits>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stdlib.h>

#define max_n 100001

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (n == 1) {cout << v[0] << endl; continue;}
        sort(v.rbegin(), v.rend());
        map<int, vector<pair<int, int>>> mp;
        vector<int> ans; 
        unordered_set<int> vis;
        int maxe = *max_element(v.begin(), v.end()); 
        ans.push_back(maxe);
        vis.insert(maxe);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                mp[__gcd(v[i], v[j])].push_back({v[i], v[j]});
            }
        }
        for (auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            for (auto it1 : it->second)
            {
                if (vis.find(it1.first) == vis.end()) ans.push_back(it1.first), vis.insert(it1.first);
                if (vis.find(it1.second) == vis.end()) ans.push_back(it1.second), vis.insert(it1.second);
            }
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}