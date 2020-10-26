/*
    title: b_spreadsheets.cpp
    author: Akhil
    date: 2020-10-20
    time: 20:43:57
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

string get_col(int col)
{
    string ans;
    while (col > 0)
    {
        ans += 'A' + ((col % 26 == 0) ? 25 : (col % 26) - 1); 
        col = (col % 26 == 0) ? (col / 26 - 1) : col / 26; 
    }
    reverse(ans.begin(), ans.end());
    return ans; 
}

int get_col_num(string col)
{
    int ans = 0; 
    int f = 1; 
    for (int i = col.length() - 1; i >= 0; i--)
        ans += (col[i] - 'A' + 1) * f, f *= 26;
    return ans; 
}

string solve(string s)
{
    if (s[0] == 'R')
    {
        int idx = -1; 
        for (int i = 2; i < s.length(); i++) 
        {
            if (s[i] == 'C')
            {
                idx = i;
                break;
            }
        }
        if (idx != -1)
        {
            int col = stoi(s.substr(idx + 1)); 
            int row = stoi(s.substr(1, idx)); 
            return get_col(col) + to_string(row); 
        }
    }
    int idx = 0; 
    while (idx < s.length() and s[idx] >= 'A' and s[idx] <= 'Z') idx++; 
    int col = get_col_num(s.substr(0, idx)); 
    int row = stoi(s.substr(idx)); 
    return "R" + to_string(row) + "C" + to_string(col); 
}

int main()
{
    int n; cin >> n;
    string s; 
    for (int i = 0; i < n; i++)
    {
        cin >> s; 
        cout << solve(s) << endl;
    }
    return 0;
}
