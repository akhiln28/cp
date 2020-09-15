#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>
using namespace std;

/*
    DATE: 16-08-2020
    TIME: 12:21:15
    SOURCE: https://codeforces.com/problemset/problem/1186/D
*/

int main()
{
    int n; cin >> n;
    vector<float> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = floor(a[i]);
    }
    long long sum = accumulate(b.begin(), b.end(), 0);
    for (int i = 0; i < n; i++)
    {
        if (sum < 0 && b[i] - a[i]) 
        {
            cout << ++b[i] << endl;
            sum++;
        }
        else cout << b[i] << endl;
    }
}