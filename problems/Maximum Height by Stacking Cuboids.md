---
Created Time: Dec 12, 2020 4:34 PM
Do Date: Dec 18, 2020
Last edited time: May 11, 2021 9:01 AM
Points: 2000
Related To: Longest%20Increasing%20Path%2077ddff3a66da4f45b07037cecd2ae9fc.md
Source: https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
Status: done
Tags: DAG
---

# Maximum Height by Stacking Cuboids

Given `n` `cuboids` where the dimensions of the `ith` cuboid is `cuboids[i] = [widthi, lengthi, heighti]` (**0-indexed**). Choose a **subset** of `cuboids` and place them on each other.
You can place cuboid `i` on cuboid `j` if `widthi <= widthj` and `lengthi <= lengthj` and `heighti <= heightj`. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.
Return *the **maximum height** of the stacked* `cuboids`.
**Example 1:**
![Maximum%20Height%20by%20Stacking%20Cuboids%20d04881ce384645b9ba6b0232f94d8575/image.jpg](Maximum%20Height%20by%20Stacking%20Cuboids%20d04881ce384645b9ba6b0232f94d8575/image.jpg)
```
Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.
```
**Example 2:**
```
Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.
```
**Example 3:**
```
Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
Output: 102
Explanation:
After rearranging the cuboids, you can see that all cuboids have the same dimension.
You can place the 11x7 side down on all cuboids so their heights are 17.
The maximum height of stacked cuboids is 6 * 17 = 102.
```
**Constraints:**
- `n == cuboids.length`
- `1 <= n <= 100`
- `1 <= widthi, lengthi, heighti <= 100`
---
Thinking it is most probably dp. 
```cpp
class Solution {
public:
    bool is_possible(vector<int> &v1, vector<int> &v2)
    {
        return (v1[0] >= v2[0] and v1[1] >= v2[1] and v1[2] >= v2[2]); 
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size(); 
        for (auto &cube: cuboids)
        {
            sort(cube.rbegin(), cube.rend()); 
        }
        sort(cuboids.rbegin(), cuboids.rend()); 
        vector<int> dp(n); 
        for (int i = 0; i < n; i++) dp[i] = cuboids[i][0]; 
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (is_possible(cuboids[i], cuboids[j]))
                {
                    dp[j] = max(dp[j], dp[i] + cuboids[j][0]); 
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
```
Patterns: [Dp](Dp.md)[Number%20Theory](Number%20Theory.md)[Linear%20DP](Linear%20DP.md)