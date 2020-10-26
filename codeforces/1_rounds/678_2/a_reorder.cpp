/*
    title: A.cpp
    author: Akhil
    date: 2020-10-24
    time: 19:37:03
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
        int n, m; cin >> n >> m;
        vector<int> v(n); 
        for (int i = 0;i < n; i++) cin >> v[i]; 
        bool flag = accumulate(v.begin(), v.end(), 0) == m; 
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}