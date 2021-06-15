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
    title: abc200_3.cpp
    author: Akhil
    date: 2021-05-08
    time: 17:35:35
    ==================================================
    number of pairs of integers i, j such that Ai - Aj is a multiple of 200
*/
int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i] %= 200;
    }
    vector<long long> reminder(200);
    for (int i = 0; i < n; i++)
    {
        reminder[v[i]]++;
    }
    long long ans = 0;

    for (int i = 0; i < 200; i++)
    {
        ans += reminder[i] * (reminder[i] - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}