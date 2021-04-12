#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

/*
    title: m_interval_painting.cpp
    author: Akhil
    date: 2021-04-12
    time: 07:43:59
    ==================================================
    you are at position 0,
    +2 => (0 - 1 => 1, 1 - 2 => 1)
    -4 => ()
    this is a interval overlap problem
*/
int solve(vector<int>& walks, int target) {
    int pos = 0;
    vector<pair<int, int>> cums;
    for (int i = 0; i < walks.size(); i++)
    {
        int next_pos = pos + walks[i];
        if (walks[i] > 0)
        {
            cums.push_back({pos, 1});
            cums.push_back({next_pos, -1});
        }
        else if (walks[i] < 0)
        {
            cums.push_back({next_pos, 1});
            cums.push_back({pos, -1});
        }
        pos = next_pos;
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < cums.size(); i++) mp[cums[i].first] += cums[i].second;
    vector<pair<int, int>> final_cums;
    for (auto kv : mp)
    {
        final_cums.push_back(kv);
    }
    sort(final_cums.begin(), final_cums.end());
    int sum = final_cums[0].second, ans = 0, prev = final_cums[0].first;
    for (int i = 1; i < final_cums.size(); i++)
    {
        if (sum >= target) ans += final_cums[i].first - prev;
        sum += final_cums[i].second;
        prev = final_cums[i].first;
    }
    return ans;
}

int main()
{
    vector<int> walks{2, -4, 1};
    int target = 2;
    auto ret = solve(walks, target);
    cout << ret << endl;
    return 0;
}