---
Created Time: Feb 03, 2021 7:57 AM
Do Date: Feb 03, 2021
Last edited time: Apr 06, 2021 9:02 AM
Points: 1700
Pomos (25 mins): 1
Source: https://leetcode.com/discuss/interview-question/821780/goldman-sachs-array-dp-problem-oa-august-2020
Status: ok
Tags: goldman sachs, new
---

# One step back two step forward: reach end of array

An array of costs was given. You can either take two jumps forward or one jump backward. If you land on a particular index, you have to add the cost to your total. Find the minimum cost needed to cross the array or reach the end of the array.
---
$dp[n - 1] = v[n - 1]$
$dp[i] = min(v[i] + dp[i + 2], v[i] + v[i - 1] + dp[i + 1])$
Patterns: [Dp](Dp.md)[State%20DP](State%20DP.md)