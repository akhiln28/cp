---
Created Time: Dec 01, 2020 11:55 PM
Last edited time: May 20, 2021 9:55 AM
Points: 1800
Problem Statement: queen can travel to right, down, diagonal right down any length but not over obstacle, find the number of possible paths to h, w
Status: waiting
Tags: counting, cummulative
---

# Queen on the Grid

'#' → denotes wall, '." → denotes road
Given h, w (both <2000) and matrix S, containing '.' and '#'. 
---
**Sample Input 1**
```
3 3
...
.#.
...
```
**Sample Output 1** 
```
10
```
There are 1010 ways to travel, as follows:
- (1,1)→(1,2)→(1,3)→(2,3)→(3,3)(1,1)→(1,2)→(1,3)→(2,3)→(3,3)
- (1,1)→(1,2)→(1,3)→(3,3)(1,1)→(1,2)→(1,3)→(3,3)
- (1,1)→(1,2)→(2,3)→(3,3)(1,1)→(1,2)→(2,3)→(3,3)
- (1,1)→(1,3)→(2,3)→(3,3)(1,1)→(1,3)→(2,3)→(3,3)
- (1,1)→(1,3)→(3,3)(1,1)→(1,3)→(3,3)
- (1,1)→(2,1)→(3,1)→(3,2)→(3,3)(1,1)→(2,1)→(3,1)→(3,2)→(3,3)
- (1,1)→(2,1)→(3,1)→(3,3)(1,1)→(2,1)→(3,1)→(3,3)
- (1,1)→(2,1)→(3,2)→(3,3)(1,1)→(2,1)→(3,2)→(3,3)
- (1,1)→(3,1)→(3,2)→(3,3)(1,1)→(3,1)→(3,2)→(3,3)
- (1,1)→(3,1)→(3,3)(1,1)→(3,1)→(3,3)
---
**Sample Input 2** 
```
4 4
...#
....
..#.
....
```
**Sample Output 2** 
```
84
```
From (1,1)(1,1), the queen can move to (1,2)(1,2), (1,3)(1,3), (2,1)(2,1), (2,2)(2,2), (3,1)(3,1), or (4,1)(4,1).
One possible path to (4,4)(4,4) is (1,1)→(3,1)→(3,2)→(4,3)→(4,4)(1,1)→(3,1)→(3,2)→(4,3)→(4,4).
---
**Sample Input 3**
```
8 10
..........
..........
..........
..........
..........
..........
..........
..........
```
**Sample Output 3** 
```
13701937
```
Find the count modulo (10^9+7).
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
#include <string.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7; 
int main()
{
    int h, w; cin >> h >> w;
    char s[h][w];
    ll cumh[h][w], cumw[h][w], cumd[h][w], dp[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> s[i][j];
        }
    }
    memset(cumh, 0, sizeof(ll) * h * w); 
    memset(cumw, 0, sizeof(ll) * h * w); 
    memset(cumd, 0, sizeof(ll) * h * w); 
    memset(dp, 0, sizeof(ll) * h * w);
    for (int i = h - 1; i >= 0; i--)
    {
        for (int j = w - 1; j >= 0; j--)
        {
            if (i == h - 1 && j == w - 1) 
            {
                cumh[i][j] = 1, cumw[i][j] = 1, cumd[i][j] = 1, dp[i][j] = 1;    
                continue;
            }
            else if (s[i][j] == '.')
            {
                if (i + 1 < h) dp[i][j] = (cumh[i + 1][j] + dp[i][j]) % mod; 
                if (j + 1 < w) dp[i][j] = (cumw[i][j + 1] + dp[i][j]) % mod; 
                if (i + 1 < h && j + 1 < w) dp[i][j] = (cumd[i + 1][j + 1] + dp[i][j]) % mod; 
                cumh[i][j] = dp[i][j]; 
                cumw[i][j] = dp[i][j]; 
                cumd[i][j] = dp[i][j]; 
                if (i + 1 < h) cumh[i][j] = (cumh[i + 1][j] + cumh[i][j]) % mod;
                if (j + 1 < w) cumw[i][j] = (cumw[i][j + 1] + cumw[i][j]) % mod; 
                if (i + 1 < h && j + 1 < w) cumd[i][j] = (cumd[i + 1][j + 1] + cumd[i][j]) % mod;  
            }
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
```
Patterns: [Matrix](Matrix.md)[Cumulative](Cumulative.md)[Dp](Dp.md)