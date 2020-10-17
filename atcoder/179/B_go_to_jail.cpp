/*
    title: B.cpp
    author: Akhil
    date: 2020-09-19
    time: 17:33:19
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
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i <= n - 3; i++)
    {
        if (v[i].first == v[i].second and
            v[i + 1].first == v[i + 1].second and
            v[i + 2].first == v[i + 2].second)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}