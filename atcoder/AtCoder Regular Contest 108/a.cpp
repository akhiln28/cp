/*
    title: a.cpp
    author: Akhil
    date: 2020-11-28
    time: 17:31:22
*/

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
#include <cstring>

#define ll long long

using namespace std;

int main()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    if (a > b)
    {
        cout << min((a - b - 1) * y + x, (a - b - 1) * 2 * x + x) << endl;
    }
    else
    {
        cout << min((b - a) * y + x, (b - a) * 2 * x + x) << endl;
    }
    
    return 0;
}
