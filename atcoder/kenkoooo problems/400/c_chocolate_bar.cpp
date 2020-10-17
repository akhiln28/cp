/*
    title: c_chocolate_bar.cpp
    author: Akhil
    date: 2020-10-13
    time: 22:20:15
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
    long long a, b; cin >> a >> b;
    if (a % 3 == 0 or b % 3 == 0) 
    {
        cout << 0 << endl; 
        return 0; 
    }
    auto max_split = [](long long a, long long b){
        if (a % 2 == 0 or b % 2 == 0) return (a * b)/2; 
        if (a > b) swap(a, b); 
        return a * (b / 2 + b); 
    };
    auto min_split = [](long long a, long long b){
        if (a % 2 == 0 or b % 2 == 0) return (a * b)/2; 
        if (a > b) swap(a, b); 
        return a * (b / 2);
    };
    if (a > b) swap(a, b);
    long long ans = INT_MAX; 
    ans = min(ans, a * (b / 3 + 1) - min_split(a, b - b/3 - 1)); 
    if (b % 3 == 2) ans = min(ans, a * (b / 3 + 2) - min_split(a, b - b/3 - 2)); 
    ans = min(ans, max_split(a, b - b/3) - a * (b / 3)); 
    cout << ans << endl;
    return 0;
}
