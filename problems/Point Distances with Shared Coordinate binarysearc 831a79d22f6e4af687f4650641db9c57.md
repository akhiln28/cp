# Point Distances with Shared Coordinate | binarysearch

Created Time: Feb 23, 2021 9:01 AM
Do Date: Mar 07, 2021
Last edited time: Mar 07, 2021 7:57 AM
Pattern: https://www.notion.so/Hashing-dc1f706a2c0b4b5eb6ee200a3ab1ae98, https://www.notion.so/Binary-Search-c1187205516c42ac9b3b3c69f153914a
Points: 1600
Pomos (25 mins): 1
Source: https://binarysearch.com/problems/Point-Distances-with-Shared-Coordinate
Status: done

You are given a unique two-dimensional list of integers `points` where each element `points[i]` contains `(x, y)` representing a Cartesian coordinate.

For each point `i` in `points`, return the shortest Manhattan distance to a different point that is either in the same `y` coordinate or the same `x` coordinate.

You can assume that every point has some other point that either share the same `x` or `y` coordinate.

**Constraints**

- `0 ≤ n ≤ 100,000` where `n` is the length of `points`

---

```cpp
int least_distance(vector<int>& nums, int x)
{
    int ans = INT_MAX; 
    int left = 0, right = nums.size() - 1; 
    while (left <= right)
    {
        int mid = left + (right - left)/2; 
        if (nums[mid] == x) 
        {
            ans = min({mid ? abs(nums[mid - 1] - x) : INT_MAX, 
                        mid + 1 < nums.size() ? abs(nums[mid + 1] - x) : INT_MAX, 
                        ans});
            return ans; 
        }
        else if (nums[mid] > x) right = mid - 1;
        else left = mid + 1; 
    }
    return INT_MAX; 
}
vector<int> solve(vector<vector<int>>& points) {
    unordered_map<int, vector<int>> mpx, mpy; 
    for (int i = 0; i < points.size(); i++)
    {
        mpx[points[i][0]].push_back(points[i][1]); 
        mpy[points[i][1]].push_back(points[i][0]); 
    }
    for (auto &v : mpx)
    {
        sort(v.second.begin(), v.second.end());
        // for (auto e : v.second) cout << e << " "; cout << endl;
    }
    for (auto &v : mpy)
    {
        sort(v.second.begin(), v.second.end());
        // for (auto e : v.second) cout << e << " "; cout << endl;
    }
    
    vector<int> ans; 
    for (int i = 0; i < points.size(); i++)
    {
        int dx = least_distance(mpx[points[i][0]], points[i][1]); 
        int dy = least_distance(mpy[points[i][1]], points[i][0]);
        ans.push_back(min(dx, dy));
    }
    return ans; 
}
```