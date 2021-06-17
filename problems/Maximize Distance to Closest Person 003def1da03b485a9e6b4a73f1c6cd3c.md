# Maximize Distance to Closest Person

Created Time: Dec 01, 2020 11:55 PM
Last edited time: May 11, 2021 9:04 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Traversal-dca46f72f93e4db583e0e72ba3dc6fdb
Points: 1500
Status: done

You are given an array representing a row of `seats` where `seats[i] = 1` represents a person sitting in the `ith` seat, and `seats[i] = 0` represents that the `ith` seat is empty **(0-indexed)**.

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized.

Return *that maximum distance to the closest person*.

**Example 1:**

![https://assets.leetcode.com/uploads/2020/09/10/distance.jpg](https://assets.leetcode.com/uploads/2020/09/10/distance.jpg)

```
Input: seats = [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (i.e. seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.

```

**Example 2:**

```
Input: seats = [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat (i.e. seats[3]), the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.

```

**Example 3:**

```
Input: seats = [0,1]
Output: 1

```

**Constraints:**

- `2 <= seats.length <= 2 * 104`
- `seats[i]` is `0` or `1`.
- At least one seat is **empty**.
- At least one seat is **occupied**.

---

```cpp
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int prev = -1, maxe = INT_MIN; 
        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i] == 1)
            {
                if (prev == -1) maxe = i - prev - 1;
                else if (maxe < (i - prev)/2) maxe = (i - prev)/2;
                prev = i; 
            }
        }
        if (seats[seats.size() - 1] == 0)
        {
            if (maxe < seats.size() - prev - 1) maxe = seats.size() - prev - 1; 
        }
        return maxe; 
    }
};
```