#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <array>
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

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto profit = [&](double passed, double total){
            return (passed + 1)/(total + 1) - passed/total;
        };
        priority_queue<pair<double, array<int, 2>>> pq;
        double ans = 0;
        for (auto &c : classes)
        {
            ans += (double) c[0]/c[1];
            pq.push({profit(c[0], c[1]), {c[0], c[1]}});
        }
        while (extraStudents--)
        {
            auto [added_profit, c] = pq.top(); pq.pop();
            ans += added_profit;
            pq.push({profit(c[0] + 1, c[1] + 1), {c[0] + 1, c[1] + 1}});
        }
        return ans/classes.size();
    }
};

int main()
{
    // {passed, total}
    vector<vector<int>> classes{{1, 2}, {3, 5}, {2, 2}};
    int extraStudents = 2;
    Solution obj;
    auto ret = obj.maxAverageRatio(classes, extraStudents);
    cout << ret << endl;
    return 0;
}