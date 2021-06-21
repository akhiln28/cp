---
Created Time: May 25, 2021 9:19 AM
Day Completed: https://www.notion.so/1-June-21-Tuesday-ffcc3cd580b9487598bde6a4408597cf
Last edited time: May 31, 2021 9:49 AM
Points: 1700
Source: https://leetcode.com/problems/jump-game-vii/
Status: ok
---

# Jump Game VII - LeetCode

You are given a **0-indexed** binary string `s` and two integers `minJump` and `maxJump`. In the beginning, you are standing at index `0`, which is equal to `'0'`. You can move from index `i` to index `j` if the following conditions are fulfilled:
- `i + minJump <= j <= min(i + maxJump, s.length - 1)`, and
- `s[j] == '0'`.
Return `true` if you can reach index `s.length - 1` in `s`*, or* `false` *otherwise.*
### Constraints
- `2 <= s.length <= 10^5`
- `s[i]` is either `'0'` or `'1'`.
- `s[0] == '0'`
- `1 <= minJump <= maxJump < s.length`
### **Examples**
**Example 1:**
```
Input: s = "011010", minJump = 2, maxJump = 3
Output: true
Explanation:
In the first step, move from index 0 to index 3.
In the second step, move from index 3 to index 5.
```
**Example 2:**
```
Input: s = "01101110", minJump = 2, maxJump = 3
Output: false
```
---
## Algorithm
```python
you can move from i to j
instead of working with the string we will work with a list of numbers
011010, min = 2, max = 3
0, 3, 5
if there is any sequence of 1's whose length is greater than max then return false
consider min = 3, max = 5
0, 2, 5, 7, 11
0 -> 5 stop...
you have current range, i to j, find the smallest from i and largest jump from j. this will be your new range..
This way you are going to expand your range
but what about the case when there is no smallest jump from i?? how do you expaned your range? i.e. the case when you cannot escape from i..
```
### Explanation
I did not get the BFS solution [https://leetcode.com/problems/jump-game-vii/discuss/1224654/Clean-Python-3-BFS](https://leetcode.com/problems/jump-game-vii/discuss/1224654/Clean-Python-3-BFS)
## Solution
```cpp
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<bool> dp(n); 
        dp[0] = true;
        int window = 0;
        for (int i = 1; i < n; i++) {
            if (i >= maxJump + 1) window -= dp[i - maxJump - 1];
            if (i >= minJump) window += dp[i - minJump];
            dp[i] = window > 0 and s[i] == '0';
        }
        return dp[n - 1]; 
    }
};
```
Patterns: [BFS](BFS.md)[Dp](Dp.md)