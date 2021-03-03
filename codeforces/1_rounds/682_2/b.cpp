/*
    title: b.cpp
    author: Akhil
    date: 2020-11-14
    time: 10:59:05
*/
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <set>
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
        unordered_set<int> s; 
        bool flag = false; 
        for (int i = 0; i < n; i++)
        {
            int x; cin >> x;
            if (s.count(x))
            {
                flag = true; 
            }
            s.insert(x); 
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
