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
    int n; cin >> n;
    vector<int> v(n); 
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    long long ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] > v[i + 1]) 
        {
            ans += v[i] - v[i + 1], v[i + 1] = v[i];
        }
    }
    cout << ans << endl;
    return 0;
}