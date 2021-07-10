---
Created Time: Mar 02, 2021 8:13 AM
Do Date: Mar 02, 2021
Last edited time: Mar 02, 2021 8:58 AM
Points: 1500
Pomos (25 mins): 1
Source: https://atcoder.jp/contests/arc113/tasks/arc113_a
Status: done
---

# A - A*B*C

Given a positive integer $k$, find the number of triples of positive integers (A,B,C) such that  `A.B.C <= k`. Two triples that only differ in the order of numbers are also distinguished.
### **Constraints**
- $1 \le k \le 2 \times 10^5$
- $k$ is an integer.
---
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
    int k; cin >> k; 
    long long ans = 0; 
    for (long long i = 1; i <= k; i++)
    {
        for (long long j = 1; j <= k; j++)
        {
            int d = k/(i * j);
            ans += d; 
            if (d == 0) break; 
        }
    }
    cout << ans << endl;
    return 0;
}
```
### Complexity:
Time: $O(k\times log^2k)$
Patterns: [Number%20Theory](Number%20Theory.md)