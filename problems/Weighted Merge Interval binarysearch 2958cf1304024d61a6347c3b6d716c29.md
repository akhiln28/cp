# Weighted Merge Interval | binarysearch

Created Time: Apr 06, 2021 8:59 AM
Day Completed: https://www.notion.so/3-April-21-9039b11e89b84ab2b54e61189730204b
Last edited time: Apr 11, 2021 8:34 AM
Pattern: https://www.notion.so/Interval-Overlaps-565fcb6c998148ab82b9ec576adcf781, https://www.notion.so/Intervals-ebd124f2083d4f999c01b25e664d9e01, https://www.notion.so/Cumulative-73b8950eb0ab42228e72265c36aec690
Points: 1500
Pomos (25 mins): 2
Source: https://binarysearch.com/problems/Weighted-Merge-Interval
Status: done

You are given a two-dimensional list of integers `intervals`. Each element contains `[start, end, weight]`, meaning that during the inclusive integer interval `[start, end]` its weight is `weight`. Weight is additive so if we have `[[1, 5, 6], [2, 7, 3]]`, then during `[2, 5]` we have weight of `9`. The input `intervals` may or may not be overlapping.

Return the list of intervals that have the highest weight, sorted in ascending order. The returned intervals should be merged, so `[[1, 2], [3, 4]]` should be merged to `[1, 4]`.

**Constraints**

- `0 ≤ n ≤ 100,000` where `n` is the length of `intervals`
- `2 ** 31 < start ≤ end < 2 ** 31`