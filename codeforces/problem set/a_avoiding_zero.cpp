/*
    title: a_avoiding_zero.cpp
    author: Akhil
    date: 2020-10-11
    time: 10:32:40
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

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        size_t n;
        cin >> n;
        vector<int> v(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int sum = accumulate(v.begin(), v.end(), 0);
        if (sum > 0)
            sort(v.rbegin(), v.rend());
        else if (sum < 0)
            sort(v.begin(), v.end());
        else
        {
            cout << "NO" << endl;
            continue; 
        }
        cout << "YES" << endl;
        for (size_t i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}