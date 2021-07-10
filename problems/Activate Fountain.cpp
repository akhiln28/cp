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
    title: Activate Fountain.cpp
    author: Akhil
    date: 2021-07-09
    time: 17:58:54
    ==================================================
*/

int fountainActivation(vector<int>& locations) {
    int n = locations.size();
    vector<int> right_max(n);
    int ans = 1;

    for (int i = 1; i <= n; i++) {
        int left = max(i - locations[i - 1], 1);
        int right = min(i + locations[i - 1], n);

        right_max[left - 1] = right;
    }

    int right = right_max[0];
    int cur_max = right;
    for (int i = 1; i < n; i++) {
        cur_max = max(cur_max, right_max[i]);

        if (i == right) {
            ans++;
            right = cur_max;
        }
    }
    return ans;
}
int main()
{
    vector<int> locations(3, 1);
    cout << fountainActivation(locations) << endl;
    return 0;
}