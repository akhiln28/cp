/*
    title: A.cpp
    author: Akhil Nichenametla
    date: 2020-08-05
    time: 20:03:54
*/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 100001

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int prev = v[0];
        bool flag = true;
        for (size_t i = 1; i < n; i++)
        {
            if (v[i] - prev > 1)
            {
                flag = false;
                break;
            }
            prev = v[i];
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}