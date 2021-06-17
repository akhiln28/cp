# Best Time to Buy and Sell Stock III - LeetCode

Created Time: Dec 20, 2020 2:19 PM
Do Date: Dec 20, 2020
Last edited time: Mar 01, 2021 8:48 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Cumulative-73b8950eb0ab42228e72265c36aec690, https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee
Points: 2000
Pomos (25 mins): 1
Related To: Best%20Time%20to%20Buy%20and%20Sell%20Stock%20-%20LeetCode%200856c7a6811a4dc0b861d1aed9bbc105.md
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
Status: done
Tags: prefix max, suffix sum

Say you have an array for which the *i*th element is the price of a given stock on day *i*.

Design an algorithm to find the maximum profit. You may complete at most *two* transactions.

**Note:** You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

**Example 1:**

```
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
```

**Example 2:**

```
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

```

**Example 3:**

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

```

**Example 4:**

```
Input: prices = [1]
Output: 0

```

**Constraints:**

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^5`

---

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
        long long mine = INT_MAX, maxe = INT_MIN, left_ans = 0, right_ans = 0;
        vector<long long> left(prices.size()), right(prices.size());
        for (int i = 0; i < prices.size(); i++)
        {
            left_ans = max(left_ans, prices[i] - mine);
            left[i] = left_ans;
            mine = min(mine, (long long) prices[i]);
        }
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            right_ans = max(right_ans, maxe - prices[i]);
            right[i] = right_ans;
            maxe = max(maxe, (long long) prices[i]);
        }
        
        long long ans = right[0]; 
        for (int i = 0; i < prices.size() - 1; i++)
        {
            ans = max(ans, left[i] + right[i + 1]);
        }
        ans = max(ans, left[prices.size() - 1]);
        return ans;
    }
};
```