/*
    title: b_elimination.cpp
    author: Akhil
    date: 2020-11-01
    time: 19:51:33
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
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << max(a + b, c + d) << endl;
    }
    return 0;
}