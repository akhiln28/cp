/*
    title: a.cpp
    author: Akhil
    date: 2020-11-15
    time: 08:26:25
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <unordered_map>
#include <set>
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
        long long n, k, s;
        cin >> n >> k >> s;
        long long ans = min(2 * k + n - 2 * s, n + k);
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}