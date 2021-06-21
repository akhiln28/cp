---
Created Time: Dec 12, 2020 8:36 AM
Do Date: Feb 05, 2021
Last edited time: May 11, 2021 9:10 AM
Points: 1700
Pomos (25 mins): 5
Related To: Stone%20Game%208b46a54c655949bcaed13e32b6354ecb.md
Source: https://leetcode.com/problems/stone-game-ii/
Status: done
Tags: game
---

# Stone Game II

Alice and Bob continue their games with piles of stones. There are a number of piles **arranged in a row**, and each pile has a positive integer number of stones `piles[i]`. The objective of the game is to end with the most stones.
Alice and Bob take turns, with Alice starting first. Initially, `M = 1`.
On each player's turn, that player can take **all the stones** in the **first** `X` remaining piles, where `1 <= X <= 2M`. Then, we set `M = max(M, X)`.
The game continues until all the stones have been taken.
Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.
**Example 1:**
```
Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
```
**Example 2:**
```
Input: piles = [1,2,3,4,5,100]
Output: 104
```
**Constraints:**
- `1 <= piles.length <= 100`
- `1 <= piles[i] <= 10^4`
---
The goal is to maximize what alice can score and not alice winning. 
```jsx
class Solution {
public:
    int dp[101][101];
    vector<int> cum;
    int recur(vector<int>& piles, int i, int m)
    {
        if (i >= piles.size() or m >= 100) return 0; 
        if (dp[i][m] != -1) return dp[i][m]; 
        int ans = 0, remtotal = cum[piles.size() - 1] - ((i) ? cum[i - 1] : 0);
        for (int j = 1; j <= 2 * m and i + j - 1 < piles.size(); j++)
        {
            ans = max(ans, remtotal - recur(piles, i + j, max(j, m)));
        }
        return dp[i][m] = ans; 
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, 101 * 101 * sizeof(int));
        cum.resize(piles.size()); 
        cum[0] = piles[0];
        for (int i = 1; i < piles.size(); i++)
        {
            cum[i] = cum[i - 1] + piles[i];
        }
        return recur(piles, 0, 1); 
    }
};
```
Patterns: [Array](Array.md)[Dp](Dp.md)[patterns/Knapsack](patterns/Knapsack.md)