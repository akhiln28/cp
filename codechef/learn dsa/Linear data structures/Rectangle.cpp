/*
    title: Rectangle.cpp
    author: Akhil Nichenametla
    date: 2020-08-06
    time: 17:12:01
*/

#include <iostream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>
#define F(i,a,b) for(int i = a; i < b; i++)

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points;
    points.push_back({0, 0});
    F(i, 0, n)
    {
        int x, y; cin >> x >> y;
        points.push_back(make_pair(x,y));
    }
    points.push_back({100000, 0});
    sort(points.begin(), points.end());
    long long ans = 0;
    F(y, 1, 501)
    {
        int prev = 0;
        F(i, 1, points.size())
        {
            if (points[i].second >= y)
                continue;
            else
            {
                int width = points[i].first - prev;
                ans = max(ans, (long long) width * (long long) y);
                prev = points[i].first;
            }
        }
    }
    cout << ans << endl;
    return 0;
}