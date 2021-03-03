/*
    title: c.cpp
    author: Akhil
    date: 2020-11-15
    time: 10:22:19
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <set>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n; 
        vector<pair<int, int>> cds(n); 
        for (int i = 0; i < n; i++)
        {
            cin >> cds[i].first >> cds[i].second;
        }
        sort(cds.begin(), cds.end());
        long long ans = 1e18; 
        for (int i = 0; i < n; i++)
        {
            long long temp = 0; 
            int left = i, right = n - i - 1; 
            multiset<long long> cordx;
            cordx.insert(cds[i].first); 
            
            for (int j = 0; j < right; j++)
            {
                cordx.insert(cds[i].first + j + 1); 
            }
            for (int j = 0; j < left; j++)
            {
                cordx.insert(cds[i].first - j - 1); 
            }
            list<pair<int, int>> t_cds(cds.begin(), cds.end());
            while (t_cds.size())
            {
                long long mindiffx = INT_MAX;
                auto it1 = t_cds.begin(); 
                auto it2 = cordx.begin(); 
                for (auto it = t_cds.begin(); it != t_cds.end(); it++)
                {
                    long long diffx = INT_MAX;
                    auto nearest = cordx.lower_bound(it->first); 
                    if (nearest == cordx.end()) nearest--;
                    diffx = abs(it->first - *nearest);
                    if (nearest != cordx.begin())
                    {
                        long long prev_diff = abs(it->first - *prev(nearest));
                        if (diffx > prev_diff)
                        {
                            diffx = prev_diff;
                            nearest--;
                        }
                    }
                    if (mindiffx > diffx)
                    {
                        mindiffx = diffx;
                        it2 = nearest;
                        it1 = it; 
                    }
                }
                t_cds.erase(it1); 
                cordx.erase(it2); 
                temp += mindiffx + abs(it1->second - cds[i].second); 
            }
            ans = min(ans, temp); 
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
