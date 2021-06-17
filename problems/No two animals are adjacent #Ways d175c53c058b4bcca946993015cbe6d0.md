# No two animals are adjacent #Ways

Created Time: Dec 18, 2020 9:04 AM
Do Date: Jan 31, 2021
Last edited time: May 11, 2021 9:01 AM
Pattern: https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee, https://www.notion.so/Number-Theory-02e26369bab8475881b8a6a9d7b33ca9, https://www.notion.so/Linear-DP-40f64e6224704d17972aa352dc735edb
Points: 1600
Pomos (25 mins): 2
Problem Statement: There are x lions, y tigers, z leopards, and w panthers. Find the number of ways to place them on a line such that no two same animals are adjacent to each other. (0<=x,y,z,w<=51) [DP]
Status: ok
Tags: de shaw

There are x lions, y tigers, z leopards, and w panthers. Find the number of ways to place them on a line such that no two same animals are adjacent to each other. (0<=x,y,z,w<=51) [DP]

---

I did not understand the solution below, [https://leetcode.com/discuss/interview-question/796266/de-shaw-oa-intern-2021](https://leetcode.com/discuss/interview-question/796266/de-shaw-oa-intern-2021)

$$dp[x][y][z][w][k = 0/1/2/3]\rightarrow denotes \space the \space number \space of \space ways \space to \space arrange \space so \space that \space it \space ends \space with \space k$$

```cpp
dp[x][y][z][w][k=0/1/2/3] being our current state
k represents current animal breed
Transitions are simple
for simplicity, let k=0
dp[x][y][z][w][0] = dp[x-1][y][z][w][1]+dp[x-1][y][z][w][2]+dp[x-1][y][z][w][3]
bases case is
dp[0][0][0][0][0/1/2/3] = 1;
```

$Ans[!X\cap !Y\cap !Z\cap !W] = Total - Ans[X \cup Y \cup Z \cup W]$

$$X\rightarrow atleast \space two \space lions \space are \space adjacent$$

We can calculate $Ans[X \cup Y \cup Z \cup W]$ in O(X + Y + Z + W).