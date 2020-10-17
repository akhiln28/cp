/*
    title: b_dna_sequence.cpp
    author: Akhil
    date: 2020-10-03
    time: 20:08:38
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
    int n; 
    string s; 
    cin >> n >> s; 
    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>> (n + 1));
    int ans = 0; 
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1]; 
            if (s[j - 1] == 'A') dp[i][j].first--; 
            if (s[j - 1] == 'T') dp[i][j].first++;
            if (s[j - 1] == 'G') dp[i][j].second--; 
            if (s[j - 1] == 'C') dp[i][j].second++;
            ans += (dp[i][j].first == 0 and dp[i][j].second == 0); 
        }
    }
    cout << ans << endl;
    return 0;
}