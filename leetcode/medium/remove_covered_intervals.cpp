/*
    title: remove_covered_intervals.cpp
    author: Akhil
    date: 2020-10-04
    time: 15:38:33
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <climits>
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
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        cout << intervals.size() << endl;
        sort(intervals.begin(), intervals.end());
        auto contains = [&](vector<int> &v1, vector<int> &v2){
            return v1[0] <= v2[0] and v1[1] >= v2[1]; 
        };
        vector<vector<int>> rem; 
        for (int i = 0; i < intervals.size(); i++)
        {
            bool contain = false; 
            for (int j = 0; j < rem.size(); j++)
            {
                if (contains(rem[j], intervals[i])) 
                {
                    contain = true; 
                    break;
                } 
            }
            if (contain == false) rem.push_back(intervals[i]);
        }
        
        return rem.size(); 
    }
};
int main()
{
    vector<vector<int>> intervals; 
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y; 
        intervals.push_back({x,y});
    }
    Solution s; 
    cout << s.removeCoveredIntervals(intervals) << endl;
    return 0;
}
