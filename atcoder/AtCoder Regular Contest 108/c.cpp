/*
    title: c.cpp
    author: Akhil
    date: 2020-11-28
    time: 18:28:29
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
#include <cstring>

using namespace std;

#define maxn 101

char dp[maxn][maxn];
string s;

char play(char x, char y)
{
    if (x == y)
        return x;
    if (x > y)
        swap(x, y);
    if (x == 'P' && y == 'R')
        return 'P';
    if (x == 'R' && y == 'S')
        return 'R';
    if (x == 'P' && y == 'S')
        return 'S';
    return 'A';
}

int twopow(int x, int n)
{
    if (x == 0)
        return 1;
    int temp = twopow(x / 2, n);
    if (x & 1)
    {
        return (temp * temp * 2) % n;
    }
    else
        return (temp * temp) % n;
}

char func(int start, int k, int n)
{
    if (dp[start][k] != 'A')
        return dp[start][k];
    if (k == 1)
    {
        dp[start][k] = play(s[start], s[(start + 1) % n]);
    }
    else
    {
        int new_start = (start + twopow(k - 1, n)) % n;
        dp[start][k] = play(func(start, k - 1, n), func(new_start, k - 1, n));
    }

    return dp[start][k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cin >> s;
    memset(dp, 'A', maxn * maxn * sizeof(char));
    cout << func(0, k, n) << endl;
    return 0;
}
