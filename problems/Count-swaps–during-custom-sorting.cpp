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
    title: Count swaps during custom sorting.cpp
    author: Akhil
    date: 2021-07-09
    time: 19:38:49
    ==================================================
*/

long howManySwaps(vector<int> arr) {
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]] = i;
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(mp[arr[i]] - i);
    }
    return ans/2;
}

int main()
{
    vector<int> arr{5, 1, 4, 2};
    cout << howManySwaps(arr) << endl;
    return 0;
}