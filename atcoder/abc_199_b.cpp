#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <climits>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>
#include <cmath>
#include <stdio.h>

using namespace std;

/*
    title: abc_199_b.cpp
    author: Akhil
    date: 2021-04-24
    time: 17:44:53
    ==================================================
*/
int main()
{
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout << max(0, *min_element(b.begin(), b.end()) - *max_element(a.begin(), a.end()) + 1) << endl;

    return 0;
}