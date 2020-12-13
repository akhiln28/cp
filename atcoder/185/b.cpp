/*
    title: b.cpp
    author: Akhil
    date: 2020-12-13
    time: 17:34:21
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
    int n, m, t; cin >> n >> m >> t; 
    int cur_time = 0, cap = n; 
    bool flag = false;
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b; 
        n -= (a - cur_time); 
        if (n <= 0)
        {
            flag = true; 
            break;
        }
        n = min(cap, n + b - a); 
        cur_time = b; 
    }
    n -= (t - cur_time); 
    if (n <= 0) flag = true; 
    if (flag == false)
    {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0;
}

