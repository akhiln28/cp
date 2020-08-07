/*
    title: wormholes.cpp
    author: Akhil Nichenametla
    date: 2020-08-05
    time: 19:23:53
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

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<pair<int, int>> periods(n);
    vector<int> warm_v(x), warm_w(y);

    F(i, 0, n)
    {
        cin >> periods[i].first >> periods[i].second;
    }
    F(i, 0, x)
    {
        cin >> warm_v[i];
    }
    F(i, 0, y)
    {
        cin >> warm_w[i];
    }
    sort(warm_v.begin(), warm_v.end());
    sort(warm_w.begin(), warm_w.end());

    int min_ans = INT_MAX;
    F(i, 0, n)
    {
        auto it1 = lower_bound(warm_v.begin(), warm_v.end(), periods[i].first);
        auto it2 = lower_bound(warm_w.begin(), warm_w.end(), periods[i].second);

        if (it2 == warm_w.end())
            continue;
        if (it1 == warm_v.end())
        {
            it1--;
        }
        else if (periods[i].first < *it1)
        {
            if (it1 == warm_v.begin())
                continue;
            it1--;
        }
        int s = *it1, e = *it2;
        min_ans = min(min_ans, e - s + 1);
    }
    cout << min_ans << endl;
    return 0;
}