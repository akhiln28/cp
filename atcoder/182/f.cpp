/*
    title: f.cpp
    author: Akhil
    date: 2020-11-08
    time: 18:35:57
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

vector<long long> get_change(long long x, vector<long long> a)
{
    vector<long long> ans; 
    int ptr = a.size() - 1; 
    while (x)
    {
        if (x >= a[ptr]) x = x % a[ptr], ans.push_back(a[ptr]); 
        else ptr--; 
    }
    return ans; 
}

int main()
{
    int n; cin >> n; 
    long long x; cin >> x;
    vector<long long> v(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> v[i]; 
    }
    
    return 0;
}

