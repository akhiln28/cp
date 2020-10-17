/*
    title: C.cpp
    author: Akhil
    date: 2020-10-11
    time: 14:53:48
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
        cout << 2 << endl;
        if (n == 2)
        {
            cout << 1 << " " << 2 << endl;
            continue; 
        }
        vector<int> v; 
        for (int i = 0; i < n - 3; i++) v.push_back(i + 1); 
        cout << n - 2 << " " << n << endl;
        cout << n - 1 << " " << n - 1 << endl;
        v.push_back(n - 1); 
        while (v.size() >= 2)
        {
            int a = v.back(); v.pop_back();  
            int b = v.back(); v.pop_back();  
            cout << a << " " << b << endl;
            v.push_back((a + b)/2);
        }
    }
    return 0;
}
