# Remove Covered Intervals

Created Time: Dec 01, 2020 11:55 PM
Last edited time: May 11, 2021 9:04 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Traversal-dca46f72f93e4db583e0e72ba3dc6fdb
Points: 1500
Status: done
Tags: O(n^2)

Given a list of `intervals`, remove all intervals that are covered by another interval in the list.

Interval `[a,b)` is covered by interval `[c,d)` if and only if `c <= a` and `b <= d`.

After doing so, return *the number of remaining intervals*.

**Example 1:**

```
Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
```

**Example 2:**

```
Input: intervals = [[1,4],[2,3]]
Output: 1
```

**Example 3:**

```
Input: intervals = [[0,10],[5,12]]
Output: 2
```

**Example 4:**

```
Input: intervals = [[3,10],[4,10],[5,11]]
Output: 2
```

**Example 5:**

```
Input: intervals = [[1,2],[1,4],[3,4]]
Output: 1
```

**Constraints:**

- `1 <= intervals.length <= 1000`
- `intervals[i].length == 2`
- `0 <= intervals[i][0] < intervals[i][1] <= 10^5`
- All the intervals are **unique**.

---