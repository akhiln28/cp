#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n;
        if (n <= 3) {cout << -1 << endl; continue;}
        vector<int> evens, odds;
        for (int i = 1; i <= n; i++)
        {
            if (i & 1) odds.push_back(i);
            else evens.push_back(i);
        }
        if (n & 1)
        {
            for (auto i : odds) cout << i << " "; 
            reverse(evens.begin(), evens.end());
            if (evens.size()) swap(evens[0], evens[1]);
            for (auto i : evens) cout << i << " ";
        }
        else
        {
            for (auto i : evens) cout << i << " ";
            reverse(odds.begin(), odds.end());
            swap(odds[0], odds[1]);
            for (auto i : odds) cout << i << " ";
        }
        cout << endl;
    }
}