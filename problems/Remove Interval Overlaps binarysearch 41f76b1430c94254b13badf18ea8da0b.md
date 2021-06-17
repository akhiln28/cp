# Remove Interval Overlaps | binarysearch

Created Time: Jan 15, 2021 10:03 PM
Do Date: Jan 17, 2021
Last edited time: May 11, 2021 9:04 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Traversal-dca46f72f93e4db583e0e72ba3dc6fdb
Points: 1000
Related To: Activity%20Selection%20Problem%20b98e4f278b8745d182d05ec2bebc05ef.md
Source: https://binarysearch.com/problems/Remove-Interval-Overlaps
Status: done

Given a collection of exclusive `intervals`, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

The intervals are not necessarily sorted in any order.

---

This question is same as the activity selection problem. 

```cpp
int solve(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
        return a[1] < b[1]; 
    });
    int ans = 0, prev = INT_MIN; 
    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i][0] >= prev) ans++, prev = intervals[i][1]; 
    }
    return intervals.size() - ans; 
}
```