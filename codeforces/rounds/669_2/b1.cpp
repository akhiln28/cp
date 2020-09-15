#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

int max_gcd(int &gcd, vector<int> &v)
{
    int max_g = __gcd(gcd, v[0]);
    for (int i = 0; i < v.size(); i++)
    {
        max_g = max(max_g, __gcd(gcd, v[i]));
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (max_g == __gcd(gcd, v[i])) 
        {
            int ret = v[i];
            v.erase(v.begin() + i); 
            gcd = max_g;
            return ret; 
        }
    }
    return 0; 
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (n == 1) {cout << v[0] << endl; continue;}
        sort(v.rbegin(), v.rend());
        cout << v[0] << " ";
        int gcd = v[0]; v.erase(v.begin());
        while (v.size())
        {
            cout << max_gcd(gcd, v) << " ";
        }
        cout << endl; 
    }
    return 0; 
}