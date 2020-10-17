/*
    title: b_unplanned_queries.cpp
    author: Akhil
    date: 2020-09-23
    time: 07:59:13
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
    int n, m; cin >> n >> m; 
    vector<int> v(n); 
    for (size_t i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        v[a - 1]++, v[b - 1]++; 
    }
    for (size_t i = 0; i < n; i++)
    {
        if (v[i] & 1) {cout << "NO" << endl; return 0;}
    }
    
    cout << "YES" << endl;
    return 0; 
}