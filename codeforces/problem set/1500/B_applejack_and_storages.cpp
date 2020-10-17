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
// https://codeforces.com/problemset/problem/1393/B

int main()
{
    int n; cin >> n;
    map<int, int> mp;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mp[x]++;
    }
    multiset<int> s;
    for (auto it : mp)
    {
        s.insert(it.second);
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++)
    {
        char ch; cin >> ch;
        cin >> x;
        if (ch == '+')
        {
            int old = mp[x]; 
            if (s.find(old) != s.end()) s.erase(s.find(old));
            mp[x]++; s.insert(mp[x]);
        }
        else
        {
            int old = mp[x];
            if (s.find(old) != s.end()) s.erase(s.find(old));
            mp[x]--; if (mp[x]) s.insert(mp[x]);
        }
        bool square = (!s.empty() && *s.rbegin() >= 4);
        bool rect = ((!s.empty() &&*s.rbegin() >= 8) ||
                        (s.size() >= 2 && *prev(s.end(), 2) >= 4) ||
                        (s.size() >= 2 && *s.rbegin() >= 6 && *prev(s.end(), 2)>= 2) ||
                        (s.size() >= 3 && *prev(s.end(), 2) >= 2 && *prev(s.end(), 3) >= 2));
        cout << ((square && rect) ? "YES" : "NO") << endl;
    }
}