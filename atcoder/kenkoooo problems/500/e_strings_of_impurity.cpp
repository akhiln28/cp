/*
    title: e_strings_of_impurity.cpp
    author: Akhil
    date: 2020-10-14
    time: 12:54:41
*/
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
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
    string s, t; cin >> s >> t; 
    vector<vector<int>> locs(26); 
    for (int i = 0; i < s.length(); i++)
    {
        locs[s[i] - 'a'].push_back(i + 1); 
    }
    int rot = 0, pos = 0; 
    for (int i = 0; i < t.length(); i++)
    {
        vector<int> &v = locs[t[i] - 'a'];
        if (v.size() == 0) 
        {
            cout << -1 << endl; 
            return 0; 
        }
        auto it = upper_bound(v.begin(), v.end(), pos); 
        if (it == v.end())
        {
            rot++;
            pos = v[0];
        }
        else pos = *it; 
    }
    cout << rot * s.length() + pos << endl;
    return 0;
}