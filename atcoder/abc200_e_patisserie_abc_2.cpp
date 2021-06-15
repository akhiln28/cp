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
    title: abc200_5.cpp
    author: Akhil
    date: 2021-05-08
    time: 18:19:16
    ==================================================
    Cake has three parameters beauty, taste and popularity. each of which is between 1 to n.
    all N^3 distinct cakes are arranged sorted based on their sum of three parameters.

    Find the parameters of the kth cake?
    number of cakes whose sum if 3, 4, 5 and so on
*/
int main()
{
    int n, k; cin >> n >> k;
    vector<vector<int>> cakes;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cakes.push_back({i + 1, j + 1, k + 1});
            }
        }
    }
    sort(cakes.begin(), cakes.end(), [](vector<int> &a, vector<int> &b) {
        int sum1 = accumulate(a.begin(), a.end(), 0), sum2 = accumulate(b.begin(), b.end(), 0);
        if (sum1 != sum2) return sum1 < sum2;
        else if (a[0] != b[0]) return a[0] < b[0];
        else return a[1] < b[1];
    });
    map<int, int> mp;
    for (int i = 0; i < cakes.size(); i++)
    {
        int sum = accumulate(cakes[i].begin(), cakes[i].end(), 0);
        mp[sum]++;
        // cout << sum << " (" << cakes[i][0] << " " << cakes[i][1] << " " << cakes[i][2] << ") " << endl;
    }
    for (auto p : mp)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}