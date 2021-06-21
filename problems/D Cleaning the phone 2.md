---
Created Time: Jan 25, 2021 10:20 AM
Do Date: Jan 25, 2021
Last edited time: Mar 31, 2021 8:59 AM
Points: 1500
Related To: Minimum%20cost%20you%20need%20to%20spend%20to%20get%20required%20val%205f8338589e4e403d8ba6a936f7184bba.md
Source: https://codeforces.com/contest/1475/problem/D
Status: done
---

# D Cleaning the phone

Given a list of apps running in the phone memory. For each app you are given the amount of ram it occupies and the score it gives (either 1 or 2). Find the minimum score you need to remove to get ram of at least m. 
Group memories based on the scores. And sort each group according to their memory in decreasing order. Now apply two pointers method. 
```cpp
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
        int n, m; cin >> n >> m;
        vector<int> ram(n), score(n); 
        for (int i = 0; i < n; i++)
        {
            cin >> ram[i]; 
        }
        for (int i = 0; i < n; i++)
        {
            cin >> score[i];
        }
        vector<int> one, two; 
        for (int i = 0; i < n; i++)
        {
            if (score[i] == 1) one.push_back(ram[i]); 
            else two.push_back(ram[i]); 
        }
        sort(one.begin(), one.end(), greater<int>());
        sort(two.begin(), two.end(), greater<int>());
        long long memory = accumulate(two.begin(), two.end(), 0LL); 
        int cost = 2 * two.size();
        
        int ans = INT_MAX;
        int i = 0, j = two.size() - 1; 
        // for each i find the least possible j
        for (i = 0; i <= one.size(); i++)
        {
            while (j >= 0 && memory - two[j] >= m)
            {
                cost -= 2; 
                memory -= two[j]; 
                j--;
            }
            if (memory >= m) ans = min(ans, cost); 
            if (i != one.size())
            {
                memory += one[i];
                cost += 1; 
            }
        }
        if (ans != INT_MAX) cout << ans << endl;
        else cout << -1 << endl;
    }
    return 0;
}
```
Patterns: [Two%20Pointers](Two%20Pointers.md)[patterns/Greedy](patterns/Greedy.md)[Binary%20Search](Binary%20Search.md)