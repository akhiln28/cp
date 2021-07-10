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
    title: Processing Time.cpp
    author: Akhil
    date: 2021-07-09
    time: 19:31:50
    ==================================================
*/

int minTime(vector<int> pt, vector<int> tt) {
    int n = pt.size();
    sort(pt.begin(), pt.end());
    sort(tt.rbegin(), tt.rend());
    vector<int> groupmax;
    for (int i = 0; i < tt.size(); i += 4) {
        groupmax.push_back(tt[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, groupmax[i] + pt[i]);
    }
    return ans;
}
int main()
{
    vector<int> pt{10, 8};
    vector<int> tt{1, 2, 2, 3, 4, 5, 7, 8};
    cout << minTime(pt, tt) << endl;
    return 0;
}