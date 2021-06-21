---
Created Time: Apr 03, 2021 7:55 AM
Last edited time: May 20, 2021 9:55 AM
Points: 2000
Source: https://leetcode.com/problems/critical-connections-in-a-network/
Status: waiting
---

# Critical Connections in a Network - LeetCode

There are `n` servers numbered from `0` to `n-1` connected by undirected server-to-server `connections` forming a network where `connections[i] = [a, b]` represents a connection between servers `a` and `b`. Any server can reach any other server directly or indirectly through the network.
A *critical connection* is a connection that, if removed, will make some server unable to reach some other server.
Return all critical connections in the network in any order.
**Example 1:**
![Critical%20Connections%20in%20a%20Network%20-%20LeetCode%20a37ca2f6e3c44975b9b31ceb19626bbb/1537_ex1_2.png](Critical%20Connections%20in%20a%20Network%20-%20LeetCode%20a37ca2f6e3c44975b9b31ceb19626bbb/1537_ex1_2.png)
```
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
```
**Constraints:**
- `1 <= n <= 10^5`
- `n-1 <= connections.length <= 10^5`
- `connections[i][0] != connections[i][1]`
- There are no repeated connections.
Patterns: 