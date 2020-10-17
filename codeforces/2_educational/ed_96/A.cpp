/*
    title: A.cpp
    author: Akhil
    date: 2020-10-11
    time: 14:33:26
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
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n; 
        bool flag = false; 
        for (int z = 0; z * 7 <= n; z++)
        {
            for (int y = 0; y * 5 + 7 * z <= n; y++)
            {
                if ((n - y * 5 - z * 7) % 3 == 0)
                {
                    cout << (n - y * 5 - z * 7)/3 << " " << y << " " << z << endl;
                    flag = true; 
                    break;
                }
            }
            if (flag) break; 
        }
        if (flag == false) cout << -1 << endl;
    }
    return 0;
}
