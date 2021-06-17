# Stone Game

Created Time: Dec 11, 2020 10:04 PM
Do Date: Dec 12, 2020
Last edited time: Mar 01, 2021 8:48 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee
Points: 1500
Problem Statement: Alex and Lee play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].
The objective of the game is to end with the most stones. The total number of stones is odd, so there are no ties.
Alex and Lee take turns, with Alex starting first. Each turn, a player takes the entire pile of stones from either the beginning or the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.
Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
Relates: Stone%20Game%20VI%20ea94fc0ede584298a528ddf2e8029643.md, Stone%20Game%20II%20b5e49ab3f72742868ea991b0bb5918e2.md, Stone%20Game%20VII%202888cd0740d34f57bd073f679581ed73.md
Source: https://leetcode.com/problems/stone-game/
Status: done
Tags: game

Alex and Lee play a game with piles of stones. There are an even number of piles **arranged in a row**, and each pile has a positive integer number of stones `piles[i]`.

The objective of the game is to end with the most stones. The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first. Each turn, a player takes the entire pile of stones from either the beginning or the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return `True` if and only if Alex wins the game.

**Example 1:**

```
Input: piles = [5,3,4,5]
Output: true
Explanation: 
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.

```

**Constraints:**

- `2 <= piles.length <= 500`
- `piles.length` is even.
- `1 <= piles[i] <= 500`
- `sum(piles)` is odd.

---

only one element - alex wins

two elements [a1, a2] - alex wins

n elements [a1, a2, ..., an] - we can reuse the previous findings. i.e. dynamic programming. 

$dp[i][j][0] = max(piles[i] - dp[i + 1][j][1], piles[j] - dp[i][j - 1][1])$

$dp[i][j][1] = max(piles[i] - dp[i + 1][j][0], piles[j] - dp[i][j - 1][0])$

```cpp
bool stoneGame(vector<int>& piles) {
	int n = piles.size(); 
	int dp[n][n][2]; 
	memset(dp, 0, n * n * 2 * sizeof(int)); 
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j < n; j++)
		{
			if (j == i) dp[i][j][0] = piles[i]; 
			else
			{
				dp[i][j][0] = max(piles[i] - dp[i + 1][j][1], piles[j] - dp[i][j - 1][1]);
				dp[i][j][1] = max(piles[i] - dp[i + 1][j][0], piles[j] - dp[i][j - 1][0]);
			}
		}
	}
	return dp[0][n - 1][0] > 0;
}
```

I feel like I got betrayed. 

consider, 4 piles

[a1, a2, a3, a4] - alex can always chose between (a1 + a3) or (a2 + a4). so alex wins. 

we can extend this to n, (for even), alex can chose the even positions or odd positions. **so alex always wins.**