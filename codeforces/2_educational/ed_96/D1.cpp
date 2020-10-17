/*
    title: D1.cpp
    author: Akhil
    date: 2020-10-11
    time: 16:02:59
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
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        // int n; cin >> n; 
        string s; cin >> s; 
        string s1; 
        for (int i = 0; i < s.length(); i++)
        {
            if (s1.size() == 0) s1 += s[i]; 
            else if (s[i] != s1[s1.length() - 1]) s1 += s[i]; 
        }
        // cout << s1 << endl;
        int rem = s.length() - s1.length(); 
        int ans = (s1.length() + min(rem, (int) s1.length()));
        cout << (ans + 1)/2 << endl;
    }
    return 0;
}
