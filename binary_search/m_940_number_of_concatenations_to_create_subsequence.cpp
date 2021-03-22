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
    title: m_940_number_of_concatenations_to_create_subsequence.cpp
    author: Akhil
    date: 2021-03-22
    time: 08:44:27

    Given two strings s,t. Minimum number of concatenations of s is required to make t as the subsequence of the concatenations.
    s = dab, t = abbd
    (dab)(dab)(dab)
    int ptr = -1;
    for ch in t:
        if (index of ch in s > ptr): good, ptr = idx;
        else ans++, ptr = first idx
        else if (not found) return -1
*/

int solve(string s, string t)
{
    int ptr = -1;
    unordered_map<char, vector<int>> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]].push_back(i);
    }
    int ans = 1;
    for (int i = 0; i < t.size(); i++)
    {
        if (mp.find(t[i]) != mp.end())
        {
            vector<int>& v = mp[t[i]];
            auto it = upper_bound(v.begin(), v.end(), ptr);
            if (it == v.end())
            {
                ans++;
                ptr = v[0];
            }
            else
            {
                ptr = *it;
            }
        }
        else return -1;
    }
    return ans;
}

int main()
{
    string s("abc"), t("def");
    auto ret = solve(s, t);
    cout << ret << endl;
    return 0;
}