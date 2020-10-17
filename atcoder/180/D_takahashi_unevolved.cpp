/*
    title: D.cpp
    author: Akhil
    date: 2020-10-17
    time: 17:05:42
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
    long long x, y, a, b; 
    cin >> x >> y >> a >> b;
    long long exp = 0; 
    // mistake: corner case
    while (x <= b and x * (a - 1) <= b and x * a < y)
    {
        x = x * a; 
        exp++; 
    }
    exp += (y - x - 1)/b;
    cout << exp << endl;
    return 0;
}
