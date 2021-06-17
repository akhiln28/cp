# Interval Painting | binarysearch

Created Time: Apr 11, 2021 8:30 AM
Day Completed: https://www.notion.so/12-April-21-3f2c4d0a3c934dd5af335121c19e0a71
Do Date: Apr 11, 2021
Last edited time: Apr 11, 2021 8:34 AM
Pattern: https://www.notion.so/Interval-Overlaps-565fcb6c998148ab82b9ec576adcf781, https://www.notion.so/Cumulative-73b8950eb0ab42228e72265c36aec690
Points: 1600
Pomos (25 mins): 2
Source: https://binarysearch.com/problems/Interval-Painting
Status: done

You are given a list of integers `walks` and an integer `target`. You are currently at position `0` in a one-dimensional line. Each integer `abs(walks[i])` represents the number of steps taken. Positive value means you walked right while negative value means you walked left.

We define a "block" as an interval of length `1` that has been walked on. For example, if you walk right `2` times, then you walked on blocks `[0, 1]` and `[1, 2]` once each. If you walk left once, then you'd walk on block `[1, 2]` again.

Return the number of blocks that's been walked on at least `target` number of times.

**Constraints**

- `0 ≤ n ≤ 100,000` where `n` is the length of `walks`
- `1 ≤ target`