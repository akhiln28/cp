---
created at: 2021-06-17 
author: akhiln
tags: [problem]
level: 1600
---

# shortest time to cook all n dishes 
### Problem Statement
Given `N` dishes each taking $T_i$ minutes to cook in the oven. You have two ovens. Find the shortest number of minutes to cook all n dishes. 

#### Constraints
$1 \le N \le 100$
$1 \le T_i \le 10^3$

#### Examples
Input: [8, 3, 7, 2, 5]
Output:
	

### Solution
- We need to group the given n integers into two such that the maximum of the sum of its integers is minimized. 
- i.e. we need to choose a subset whose sum is most nearest to $sum/2$
- We need to check if a given $target sum$ is possible or not...
	- $dp[target]$ denotes whether $target$ can be achieved or not.

$$min(max(sum_1, sum_2))$$



#### References
- [[Optimization]]
- [[Knapsack e1ea6dfd10d74218b7477511a6be96f8]]
