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
    title: zone2021_c_mad_team.cpp
    author: Akhil
    date: 2021-05-05
    time: 09:12:06
    ==================================================
    You are given n candidates with all their parameters.
    You need to choose 3 candidates such that min(max(param for each candidate) for each param)
    Examples:
    5
    6 13 6 19 11
    4 4 12 11 18
    20 7 19 2 5
    15 5 12 20 7
    8 7 6 18 5
    When you try to select any 3 candidates. The worst case complexity is O(n^3).

    sort the candidates based on each param individually, we get five series
    You now has five series sorted based on the five different parameters.

    c3, c4, c5, c1, c2, c6
    c1, c3, c5, c4, c2, c6
    c3, c2, c4, c1, c5, c6
    c4, c1, c5, c2, c3, c6
    c2, c1, c4, c3, c5, c6
*/
int main()
{
    int n; cin >> n;
    vector<vector<int>> teams(n, vector<int> (5));
    for (int i = 0; i < n; i++)
    {
        cin >> teams[i][0] >> teams[i][1] >> teams[i][2] >> teams[i][3] >> teams[i][4];
    }

    return 0;
}