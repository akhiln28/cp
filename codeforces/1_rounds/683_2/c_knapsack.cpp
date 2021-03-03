/*
    title: c_knapsack.cpp
    author: Akhil
    date: 2020-11-16
    time: 10:01:06
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
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
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; 
        long long w; 
        cin >> n >> w;
        vector<long long> v(n); 
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long sum = 0;
        vector<int> ans; 
        for (int i = 0; i < n; i++)
        {
            if (v[i] >= (w + 1)/2 && v[i] <= w)
            {
                ans.clear();
                sum = v[i];
                ans.push_back(i); 
                break;
            }
            if (v[i] < (w + 1)/2) 
            {
                ans.push_back(i);
                sum += v[i]; 
                if (sum >= (w + 1)/2) break;
            }
        }
        if (ans.size() == 0 || sum < (w + 1)/2)
        {
            cout << -1 << endl;
            continue; 
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << (ans[i] + 1) << " "; 
        }
        cout << endl;
    }
    return 0;
}
