/*
    title: b.cpp
    author: Akhil
    date: 2020-11-30
    time: 20:13:40
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

int main()
{
    int num_cases;
    cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        long long x;
        cin >> x;
        long long left = 0, right = x, ans = INT_MAX;
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            if (mid * (mid + 1) / 2 < x)
                left = mid + 1;
            else
                ans = min(ans, mid), right = mid - 1;
        }
        if (ans * (ans + 1) / 2 - x == 1)
            cout << ans + 1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
