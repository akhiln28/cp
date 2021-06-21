---
Created Time: Dec 01, 2020 11:55 PM
Do Date: Mar 09, 2021
Last edited time: Mar 09, 2021 9:23 AM
Points: 1600
Pomos (25 mins): 1
Status: ok
---

# Minimum Area Rectangle

Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.
If there isn't any rectangle, return 0.
**Example 1:**
```
Input:[[1,1],[1,3],[3,1],[3,3],[2,2]]
Output:4
```
**Example 2:**
```
Input:[[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output:2
```
**Note**:
1. `1 <= points.length <= 500`
2. `0 <= points[i][0] <= 40000`
3. `0 <= points[i][1] <= 40000`
4. All points are distinct.
```cpp
class Solution {
public:
    int max_n = 40001;
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, vector<int>> hxy; 
        for (int i = 0; i < points.size(); i++)
        {
            hxy[points[i][0]].push_back(points[i][1]); 
        }
        vector<int> xs;
        for (auto it : hxy)
        {
            xs.push_back(it.first); 
        }
        sort(xs.begin(), xs.end()); 
        unordered_map<int, int> yps;
        int ans = INT_MAX; 
        for (int i = 0; i < xs.size(); i++)
        {
            vector<int> &ys = hxy[xs[i]]; 
            sort(ys.begin(), ys.end()); 
            for (int j = 0; j < ys.size(); j++)
            {
                for (int k = j + 1; k < ys.size(); k++)
                {
                    auto it = yps.find(max_n * ys[j] + ys[k]);
                    if (it != yps.end())
                    {
                        ans = min(ans, (ys[k] - ys[j]) * (xs[i] - it->second)); 
                    }
                    yps[max_n * ys[j] + ys[k]] = xs[i]; 
                }
            }
        }
        return (ans == INT_MAX) ? 0 : ans; 
    }
};
```
Patterns: [Hashing](Hashing.md)[Geometry](Geometry.md)