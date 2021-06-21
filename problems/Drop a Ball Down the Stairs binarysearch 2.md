---
Created Time: Mar 14, 2021 8:43 AM
Do Date: Mar 15, 2021
Last edited time: Mar 16, 2021 7:02 AM
Points: 1600
Pomos (25 mins): 3
Source: https://binarysearch.com/problems/Drop-a-Ball-Down-the-Stairs
Status: done
---

# Drop a Ball Down the Stairs | binarysearch

You are given an integer `height` and a list of integers `blacklist`. You are currently standing at height `height` and you are playing a game to move a small ball down to height `0`.
In **even rounds** (`0`, `2`, `4`, `6` etc.) you can move the ball down `1`, `2`, or `4` stairs down. In **odd rounds**, you can move the ball down `1`, `3`, or `4` stairs. There are some levels of the stairs where if the ball lands there, it will die as labelled in `blacklist`. Return number of ways you can move the ball down to height `0`. Mod the result by `10 ** 9 + 7`.
**Constraints**
- `1 ≤ height ≤ 100,000`
- `0 ≤ b ≤ 100,000` where `b` is the length of `blacklist`
### **Output**
### **Explanation**
- We can move `4` stairs down on round `0`.
- We can move `1` stair down on round `0` and then `3` stairs down on round `1`.
---
```cpp
int solve(int height, vector<int>& blacklist) {
    const int mod = 1e9 + 7; 
    unordered_set<int> blist;
    for (int i = 0; i < blacklist.size(); i++) blist.insert(blacklist[i]); 
    vector<vector<long long>> dp(height + 1, vector<long long>(2)); 
    if (blist.count(0) == 0) dp[0][0] = 1, dp[0][1] = 1; 
    else return 0; 
    for (int i = 1; i <= height; i++)
    {
        // for (int i = 0; i <= height; i++) cout << dp[i] << " "; cout << endl;
        if (blist.count(i)) 
        {
            dp[i][0] = dp[i][1] = 0; 
            continue;
        }
        dp[i][0] = ((i >= 1 ? dp[i - 1][1] : 0) + (i >= 2 ? dp[i - 2][1] : 0) + (i >= 4 ? dp[i - 4][1] : 0)) % mod;
        dp[i][1] = ((i >= 1 ? dp[i - 1][0] : 0) + (i >= 3 ? dp[i - 3][0] : 0) + (i >= 4 ? dp[i - 4][0] : 0)) % mod;
    }
    return dp[height][0];
}
```
Patterns: [Dp](Dp.md)