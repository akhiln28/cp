/*
    title: C.cpp
    author: Akhil
    date: 2020-10-24
    time: 20:14:26
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

int mod = 1e9 + 7; 

int main()
{
    int n, x, pos; 
    cin >> n >> x >> pos;
    vector<int> locs;
    int left = 0, right = n; 
    while (left < right)
    {
        int mid = (left + right)/2 + 1; 
        locs.push_back(mid); 
        if (pos + 1 >= mid) left = mid; 
        else if (pos + 1 < mid) right = mid - 1; 
    }
    sort(locs.begin(), locs.end());
    long long ans = 1, l = x - 1, r = n - x; 
    for (int i = 1; i <= n; i++)
    {
        if (i == pos + 1) continue; 
        if (binary_search(locs.begin(), locs.end(), i))
        {
            if (i > pos + 1) 
            {
                ans = (ans * r) % mod; r--; 
            }
            else 
            {
                ans = (ans * l) % mod; l--; 
            }
        }
    }
    for (int i = 1; i <= l + r; i++) ans = (ans * i) % mod; 
    cout << ans << endl;
    return 0;
}
