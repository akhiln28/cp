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
    title: e_1011_generate_anagram_substrings.cpp
    author: Akhil
    date: 2021-03-22
    time: 07:50:56
    ---------------------------------------------
    Need to return all the substrings which has another substring as anagram.
*/

vector<string> solve(string str)
{
    vector<string> ans;
    map<vector<int>, vector<int>> anagrams;
    auto hashf = [](string &str)
    {
        vector<int> v(26);
        for (auto ch : str) v[ch - 'a']++;
        return v;
    };
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            string s = str.substr(i, j - i + 1);
            anagrams[hashf(s)].push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            string s = str.substr(i, j - i + 1);
            vector<int> v = hashf(s);
            vector<int> locs = anagrams[v];
            for (int k = 0; k < locs.size(); k++)
            {
                if (locs[k] != i)
                {
                    ans.push_back(s);
                    break;
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string str("aba");
    auto ret = solve(str);
    for (auto e: ret)
    {
        cout << e << endl;
    }
    return 0;
}