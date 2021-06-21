---
Created Time: Mar 03, 2021 9:20 AM
Do Date: Mar 03, 2021
Last edited time: Mar 03, 2021 9:28 AM
Points: 1600
Source: https://binarysearch.com/problems/Number-of-Non-Overlapping-Sublists-With-Sum-of-Target
Status: ok
---

# Number of Non-Overlapping Sublists With Sum of Target | binarysearch

You are given a list of integers `nums` and an integer `target`. Return the maximum number of non-overlapping, non-empty sublists that exist such that each sublist's sum is `target`.
**Constraints**
- `0 ≤ n ≤ 100,000` where `n` is the length of `nums`
---
****Input****
`nums = [4, 3, 7, 5, -3, 10]`
`target = 7`
****Output****
`3`
```cpp
int maximumNonOverlapping(vector<pair<int, int>>& intervals)
{
    int ans = 0; 
    sort(intervals.begin(), intervals.end(), [](pair<int, int> p1, pair<int, int> p2){
        return p1.second < p2.second; 
    });
    int prev = -1; 
    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i].first > prev) ans++, prev = intervals[i].second;
    }
    return ans;
}
int solve(vector<int>& nums, int target) {
    // first we can find all the sublists as intervals whose sum is target.
    // now we want the maximum number of non overlapping intervals. i.e. activity selection problem
    int n = nums.size(); 
    if (n == 0) return 0; 
    vector<int> cums(n);
    cums[0] = nums[0]; 
    for (int i = 1; i < n; i++) cums[i] = cums[i - 1] + nums[i]; 
    unordered_map<int, vector<int>> mp; // map of cums sum and vector of indices
    mp[0].push_back(-1); 
    vector<pair<int, int>> intervals; 
    for (int i = 0; i < n; i++)
    {
        if (mp.find(cums[i] - target) != mp.end())
        {
            auto &v = mp[cums[i] - target];
            for (auto e : v)
            {
                intervals.push_back({e + 1, i});
            }
        }
        mp[cums[i]].push_back(i); 
    }
    return maximumNonOverlapping(intervals); 
}
```
Patterns: [Subarray](Subarray.md)[Intervals](Intervals.md)