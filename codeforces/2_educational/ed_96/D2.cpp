/*
    title: D2.cpp
    author: Akhil
    date: 2020-10-11
    time: 17:35:04
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

// need to add sources and comments for easy readability for the next time

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n; 
        string s; cin >> s; 
        vector<int> runs; 
        int run = 0; 
        for (int i = 0; i < s.length(); i++)
        {
            run++; 
            if (i == s.length() - 1 or s[i] != s[i + 1]) runs.push_back(run), run = 0; 
        }
        int ans = 0; 
        for (int i = 0, j = 0; i < runs.size(); i++)
        {
            j = max(j, i); 
            while(j < runs.size() and runs[j] == 1) j++; 
            if (j == runs.size()) runs.pop_back(), j--; 
            else runs[j]--; 
            ans++; 
        }
        cout << ans << endl;
    }
    return 0;
}