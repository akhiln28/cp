/*
    title: b.cpp
    author: Akhil
    date: 2020-11-28
    time: 18:01:06
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

using namespace std;

bool is_possible(long long n, long long x)
{

    long double l = x, r = 2 * (n + 1) / (long double)(x + 1);
    return l <= r;
}

int main()
{
    long long n;
    cin >> n;

    long long left = 0, right = n + 1;
    long long ans = 0;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (is_possible(n, mid))
            left = mid + 1, ans = max(ans, mid);
        else
            right = mid - 1;
    }
    cout << (n - ans + 1) << endl;
    return 0;
}
