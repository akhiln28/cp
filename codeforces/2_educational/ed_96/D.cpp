/*
    title: D.cpp
    author: Akhil
    date: 2020-10-11
    time: 15:20:10
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
        int n; cin >> n; 
        string s; cin >> s; 
        string s1; 
        for (int i = 0; i < s.length(); i++)
        {
            if (s1.size() <= 1) s1 += s[i]; 
            else if (s[i] != s1[s1.length() - 1]) s1 += s[i]; 
            else if (s[i] == s1[s1.length() - 1] and s[i] != s1[s1.length() - 2]) s1 += s[i]; 
        }
        int count = 0; 
        for (int i = 0; i < s1.length(); i++)
        {
            bool flag = true; 
            if (i and s1[i] == s1[i - 1]) flag = false; 
            if (i < s1.length() - 1 and s1[i] == s1[i + 1]) flag = false; 
            if (flag) count++; 
        }
        int rem = s.length() - s1.length(); 
        int ans = s1.length() + min(rem, count); 
        cout << (ans + 1)/2 << endl;
    }
    return 0;
}