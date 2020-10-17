/*
    title: C.cpp
    author: Akhil
    date: 2020-10-17
    time: 16:43:33
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
    long long n; cin >> n;
    vector<long long> ans; 
    ans.push_back(1); 
    if (n != 1) ans.push_back(n); 
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n) ans.push_back(i); 
            else 
            {
                ans.push_back(i); 
                ans.push_back(n/i); 
            }
        }
    }
    sort(ans.begin(), ans.end()); 
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
    return 0;
}