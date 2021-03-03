/*
    title: b.cpp
    author: Akhil
    date: 2020-11-08
    time: 17:33:53
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
    int n; cin >> n; 
    vector<int> v(n); 
    for (auto &e : v) cin >> e;
    int max_gcd = 0, maxe; 
    for (int i = 2; i <= 1000; i++)
    {
        int temp_gcd = 0; 
        for (int j = 0; j < n; j++) temp_gcd += (v[j] % i == 0); 
        if (temp_gcd > max_gcd) 
        {
            maxe = i; 
            max_gcd = temp_gcd; 
        }
    }
    cout << maxe << endl;
    return 0;
}

