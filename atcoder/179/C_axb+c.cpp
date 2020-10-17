/*
    title: C.cpp
    author: Akhil
    date: 2020-09-19
    time: 17:38:38
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

int pairs(int n)
{
    int ans = 0; 
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n/i != i) ans += 2;
            else ans += 1;
        }
    }
    return ans;
}

int main()
{
    int n; 
    cin >> n;
    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += (n - 1)/i;
    }
    cout << ans << endl;
    return 0;
}