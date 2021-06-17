# Best Time to Buy and Sell Stock IV - LeetCode

Created Time: Dec 20, 2020 2:28 PM
Do Date: Dec 22, 2020
Last edited time: Mar 01, 2021 8:48 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee
Points: 2000
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
Status: waiting
Tags: amazon, de shaw, hard

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `ith` day.

Design an algorithm to find the maximum profit. You may complete at most `k` transactions.

**Notice** that you may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

**Example 1:**

```
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

```

**Example 2:**

```
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

```

**Constraints:**

- `0 <= k <= 10^9`
- `0 <= prices.length <= 1000`
- `0 <= prices[i] <= 1000`

---

The following solution looks cool. [https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/solution/](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/solution/)

```cpp
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        if 2*k >= len(prices): 
            return sum(max(0, prices[i]-prices[i-1]) for i in range(1, len(prices)))
        
        pnl = [0]*len(prices)
        for _ in range(k):
            val = 0
            for i in range(1, len(pnl)): 
                val = max(pnl[i], val + prices[i] - prices[i-1]) 
                pnl[i] = max(pnl[i-1], val)
        return pnl[-1]
```