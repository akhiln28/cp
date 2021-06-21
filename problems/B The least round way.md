---
Created Time: Dec 27, 2020 11:16 AM
Do Date: Jan 22, 2021
Last edited time: Mar 01, 2021 8:47 AM
Points: 2000
Pomos (25 mins): 2
Related To: Maximum%20number%20of%20trailing%20zeros%20in%20the%20product%20of%20a5aacb4515814d8d81b1f5782bb2501d.md
Source: http://codeforces.com/contest/2/problem/B
Status: ok
Tags: logic, new, path cost
---

# B. The least round way

There is a square matrix *n* × *n*, consisting of non-negative integer numbers. You should find such a way on it that
- starts in the upper left cell of the matrix;
- each following cell is to the right or down from the current cell;
- the way ends in the bottom right cell.
Moreover, if we multiply together all the numbers along the way, the result should be the least "round". In other words, it should end in the least possible number of zeros.
**Input**
The first line contains an integer number *n* (2 ≤ *n* ≤ 1000), *n* is the size of the matrix. Then follow *n* lines containing the matrix elements (non-negative integer numbers not exceeding 109).
**Output**
In the first line print the least number of trailing zeros. In the second line print the correspondent way itself.
**Examples**
**input**
```
3
1 2 3
4 5 6
7 8 9
```
**output**
```
0
DDRR
```
---
At each cell we store a pair denoting the power of 2 and power 5 in the cell respectively. We want to minimize the following. 
$$⁍$$
We can use dynamic programming for this. 
$$dp[c] \rightarrow min($$
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
#define max_n 10000
int power2(int n)
{
    if (n == 0) return 1; 
    int ans = 0; 
    while (n % 2 == 0) ans++, n /= 2; 
    return ans; 
}
int power5(int n)
{
    if (n == 0) return 1; 
    int ans = 0; 
    while (n % 5 == 0) ans++, n /= 5; 
    return ans; 
}
int main()
{
    int n; cin >> n; 
    vector<vector<int>> mat(n, vector<int> (n));
    bool contains_zero = false; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            if (!mat[i][j]) contains_zero = true; 
        }
    }
    vector<vector<int>> dp1(n, vector<int> (n, max_n));
    vector<vector<int>> dp2(n, vector<int> (n, max_n));
    dp1[n - 1][n - 1] = power2(mat[n - 1][n - 1]); 
    dp2[n - 1][n - 1] = power5(mat[n - 1][n - 1]); 
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i + 1 < n) dp1[i][j] = dp1[i + 1][j] + power2(mat[i][j]);
            if (j + 1 < n) dp1[i][j] = min(dp1[i][j], dp1[i][j + 1] + power2(mat[i][j])); 
            if (i + 1 < n) dp2[i][j] = dp2[i + 1][j] + power5(mat[i][j]);
            if (j + 1 < n) dp2[i][j] = min(dp2[i][j], dp2[i][j + 1] + power5(mat[i][j])); 
        }
    }
    int ans = min(dp1[0][0], dp2[0][0]); 
    if (contains_zero) ans = min(1, ans); 
    cout << ans << endl;
    if (ans == dp1[0][0])
    {
        int i = 0, j = 0; 
        while (i < n && j < n)
        {
            int right = (j + 1 < n) ? dp1[i][j + 1] : max_n;
            int down = (i + 1 < n) ? dp1[i + 1][j] : max_n;
            if (right < down) 
            {
                cout << 'R';
                j++; 
            }
            else
            {
                if (down != max_n) cout << 'D';
                i++;
            }
        }
        cout << endl;
    }   
    else
    {
        int i = 0, j = 0; 
        while (i < n && j < n)
        {
            int right = (j + 1 < n) ? dp2[i][j + 1] : max_n;
            int down = (i + 1 < n) ? dp2[i + 1][j] : max_n;
            if (right < down) 
            {
                cout << 'R';
                j++; 
            }
            else
            {
                if (down != max_n) cout << 'D';
                i++;
            }
        }
        cout << endl;
    } 
    return 0;
}
```
Patterns: [Matrix](Matrix.md)[Dp](Dp.md)