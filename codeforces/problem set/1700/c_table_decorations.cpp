/*
    title: c_table_decorations.cpp
    author: Akhil
    date: 2020-10-04
    time: 09:59:09
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

bool is_possible(long long r, long long g, long long b, long long t)
{
    return (min(2 * t, r) + min(2 * t, g) + min(2 * t, b) >= 3 * t); 
}
int main()
{
    long long r, g, b; cin >> r >> g >> b;
    long long left = 0, right = (r + g + b)/3; 
    long long ans = 0; 
    while (left <= right)
    {
        long long mid = left + (right - left)/2; 
        if (is_possible(r,g,b,mid))
        {
            ans = max(ans, mid); 
            left = mid + 1; 
        }
        else right = mid - 1; 
    }
    cout << ans << endl; 
    return 0;
}