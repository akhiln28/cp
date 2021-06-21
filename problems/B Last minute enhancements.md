---
Created Time: Dec 29, 2020 10:01 PM
Do Date: Jan 05, 2021
Last edited time: May 11, 2021 9:04 AM
Points: 800
Relates: Maximum%20distinct%20elements%20by%20increment%20and%20decreme%2067b002bc28e244948588a50256bcc2cc.md
Source: https://codeforces.com/contest/1466/problem/B
Status: done
---

# B. Last minute enhancements

Given n positive integers $x_1, x_2,.., x_n (\in [1, 2n]), n\le 10^5$. For each integer you can increase the value by 1 exactly once. Find the maximal number of distinct integers possible after applying operations in the given integers?
---
***We describe two solutions.***
.The first focuses on maximal contiguous intervals of values. We notice that for each such interval $[l,r]$ it can either remain unchanged or get increased to $[l, r + 1]$ (other possibilities won't increase the number of different elements; thus, we don't need to consider them). From this observation, we conclude that the result is the number of different elements in the input increased by the number of intervals containing at least one duplicate
The second is based on a simple, greedy approach, where we analyze the elements in nondecreasing order. While analyzing, we keep the set of elements for which we have already decided its value. When we want to add the next element, then we check if it is in the set. If it is, we increase it by 11; otherwise, we keep it as it is.
```cpp
/*
    title: b.cpp
    author: Akhil
    date: 2020-12-30
    time: 20:12:59
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
    int num_cases;
    cin >> num_cases;
    for (int case_num = 1; case_num <= num_cases; case_num++)
    {
        int n;
        cin >> n;
        vector<int> line(2 * n + 2);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            line[x]++;
        }
        int ans = 0; 
        for (int i = 2 * n + 1; i >= 1; i--)
        {
            if (line[i] == 0 && line[i - 1]) line[i] = 1, line[i - 1]--;     
        }
        for (int i = 1; i < 2 * n + 2; i++)
        {
            ans += (line[i] > 0); 
        }
        cout << ans << endl;
    }
    return 0;
}
```
Patterns: [Array](Array.md)[patterns/Greedy](patterns/Greedy.md)[Traversal](Traversal.md)