/*
    title: c.cpp
    author: Akhil
    date: 2020-12-13
    time: 17:40:12
*/

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

#define max_n 500

using namespace std;

long long C(int n, int r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}

int main()
{
    int l;
    cin >> l;
    long long ans = C(l - 1, 11);
    cout << ans << endl;
    return 0;
}
