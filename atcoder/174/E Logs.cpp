#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
#include <cmath>
#include <stdio.h>

using namespace std;

bool isPossible(vector<int> &v, int ans, int k)
{
    int sum = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        int cuts = ceil((long double)v[i] / ans) - 1;
        sum += cuts;
    }
    return sum <= k;
}

int binary_search(vector<int> &v, int k)
{
    int max_v = *max_element(v.begin(), v.end());
    int l = 1, r = max_v;
    while (r - l > 1)
    {
        bool ispossible = isPossible(v, (l + r)/2, k);
        if (!ispossible)
        {
            l = (l + r) / 2;
        }
        else
        {
            r = (l + r) / 2;
        }
    }
    if (isPossible(v, l, k))
        return l;
    else return r;
}

int main()
{
    int N, k;
    cin >> N >> k;
    vector<int> v(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    cout << binary_search(v, k) << endl;
    return 0;
}