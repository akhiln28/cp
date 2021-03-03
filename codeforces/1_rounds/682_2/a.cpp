/*
    title: a.cpp
    author: Akhil
    date: 2020-11-14
    time: 10:56:17
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
        vector<int> v(n, 1); 
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}
