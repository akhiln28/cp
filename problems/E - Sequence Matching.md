---
Created Time: Dec 12, 2020 6:08 PM
Do Date: Dec 12, 2020
Last edited time: Mar 01, 2021 8:46 AM
Points: 1700
Problem Statement: Given two integers sequences A and B of lengths n and m respectively. You can convert A and B to A1 and B1 by removing some elements from them such that |A1| = |B1|.  Let x be the number of elements removed in both A and B. And Let y be the number of positions i, such that A1 and B1 differ. 
Return the minimum possible value of x + y? 
Source: https://atcoder.jp/contests/abc185/tasks/abc185_e
Status: done
---

# E - Sequence Matching

Let $dp[i][j]$ → denotes the answer for strings A[0-i] and B[0-j]. We get the dp equation as shown below. 
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
#include <string.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<int> A(n), B(m); 
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> B[i]; 
    }
    int dp[n + 1][m + 1]; 
    memset(dp, 1e6, (n + 1) * (m + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i; 
            else
            {
                dp[i][j] = min({1 + dp[i - 1][j - 1], 1 + dp[i - 1][j], 1 + dp[i][j - 1]});
                if (A[i - 1] == B[j - 1]) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]); 
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
```
Patterns: [Two%20Pointers](Two%20Pointers.md)[String](String)[Dp](Dp.md)