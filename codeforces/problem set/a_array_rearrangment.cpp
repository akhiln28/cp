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
        int n, x; cin >> n >> x; 
        vector<int> a(n), b(n); 
        for (size_t i = 0; i < n; i++)
        {
            cin >> a[i]; 
        }
        for (size_t i = 0; i < n; i++)
        {
            cin >> b[i]; 
        }
        bool flag = true; 
        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());
        for (size_t i = 0; i < n; i++)
        {
            if (a[i] + b[i] > x) 
            {
                flag = false; 
                break;
            }
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

