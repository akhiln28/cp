#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <stdlib.h>

#define max_n 100001

using namespace std;

int main()
{
    int n; cin >> n;
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        points.push_back({x, y});
    }
    vector<long long> sum, diff;
    for (int i = 0; i < n; i++)
    {
        sum.push_back(points[i].first + points[i].second);
        diff.push_back(points[i].first - points[i].second);
    }
    sort(sum.begin(), sum.end());
    sort(diff.begin(), diff.end());
    cout << max(sum[sum.size() - 1] - sum[0], diff[diff.size() - 1] - diff[0]) << endl;
    return 0;
}