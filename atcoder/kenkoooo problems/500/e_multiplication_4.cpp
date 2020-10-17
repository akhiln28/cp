/*
    title: e_multiplication_4.cpp
    author: Akhil
    date: 2020-09-19
    time: 10:16:50
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

long long mod = 1e9 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long> neg, pos;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x >= 0)
            pos.push_back(x);
        else
            neg.push_back(x);
    }
    if (k == n)
    {
        long long ans = 1;
        for (int i = 0; i < neg.size(); i++)
            ans = (ans * neg[i]) % mod;
        for (int i = 0; i < pos.size(); i++)
            ans = (ans * pos[i]) % mod;
        cout << (ans + mod) % mod << endl;
        return 0;
    }
    if (pos.size() == 0 and (k & 1))
    {
        sort(neg.rbegin(), neg.rend());
        long long ans = 1;
        for (int i = 0; i < k; i++)
        {
            ans = (ans * neg[i]) % mod;
        }
        cout << (ans + mod) % mod << endl;
        return 0;
    }
    sort(pos.rbegin(), pos.rend());
    sort(neg.begin(), neg.end());
    int i = 0, j = 0;
    long long ans = 1;
    while (k > 0)
    {
        long long t1 = -1, t2 = -1;
        if (i < (int) pos.size() - 1) t1 = pos[i] * pos[i + 1];
        if (j < (int) neg.size() - 1) t2 = neg[j] * neg[j + 1];
        if (k == 1 or t1 > t2)
            ans = (ans * pos[i]) % mod, i++, k--;
        else
        {
            ans = (ans * neg[j]) % mod, ans = (ans * neg[j + 1]) % mod;
            j += 2, k -= 2;
        }
    }
    cout << (ans + mod) % mod << endl;
    return 0;
}