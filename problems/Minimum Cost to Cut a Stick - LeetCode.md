---
Created Time: Dec 20, 2020 8:40 AM
Do Date: Jan 10, 2021
Last edited time: Mar 01, 2021 8:48 AM
Points: 2000
Pomos (25 mins): 2
Source: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
Status: done
Tags: O(n^3)
---

# Minimum Cost to Cut a Stick - LeetCode

Given a wooden stick of length `n` units. The stick is labelled from `0` to `n`. For example, a stick of length **6** is labelled as follows:
Given an integer array `cuts` where `cuts[i]` denotes a position you should perform a cut at.
You should perform the cuts in order, you can change the order of the cuts as you wish.
The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.
Return *the minimum total cost* of the cuts.
**Example 1:**
![Minimum%20Cost%20to%20Cut%20a%20Stick%20-%20LeetCode%20620639f2a8f4413b88a47a5445df8bf7/e1.jpg](Minimum%20Cost%20to%20Cut%20a%20Stick%20-%20LeetCode%20620639f2a8f4413b88a47a5445df8bf7/e1.jpg)
```
Input: n = 7, cuts = [1,3,4,5]
Output: 16
Explanation: Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:
The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
```
![Minimum%20Cost%20to%20Cut%20a%20Stick%20-%20LeetCode%20620639f2a8f4413b88a47a5445df8bf7/e11.jpg](Minimum%20Cost%20to%20Cut%20a%20Stick%20-%20LeetCode%20620639f2a8f4413b88a47a5445df8bf7/e11.jpg)
**Example 2:**
```
Input: n = 9, cuts = [5,6,1,4,2]
Output: 22
Explanation: If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
```
**Constraints:**
- `2 <= n <= 10^6`
- `1 <= cuts.length <= min(n - 1, 100)`
- `1 <= cuts[i] <= n - 1`
- All the integers in `cuts` array are **distinct**.
---
```cpp
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        int size = cuts.size(); 
        vector<vector<int>> dp(size, vector<int> (size, INT_MAX));
        for (int i = size - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (j == i + 1)
                {
                    dp[i][j] = 0; 
                    continue; 
                }
                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]); 
                }
            }
        }
        return dp[0][size - 1]; 
    }
};
```
Patterns: [Array](Array.md)[Dp](Dp.md)