---
created at: 2021-07-09 
author: akhiln
tags: [problem]
level: 
---

# Minimum Processing time 
## Problem Statement
Given n processors each available at $pt_i$. And you are given `4n` tasks. Each processor has 4 cores, which can execute the tasks simultaneously asynchronously. What is the least time taken for processors to complete all the tasks? (you can assign tasks to processes as you wish)

### Examples
input: pt = [10, 8], tasks = [1, 2, 2, 3, 4, 5, 7, 8]
output: 
	10 + max(g1) 8
	8 + max(g2) 3

## Approach
This is essentially grouping `4n` tasks into n groups each of size 4. Such that $max(g_i + sum(g_i))$ is minimized. 

Sort the array and find the `n` maximums. Merge them in reverse order. 


## Solution

### References

