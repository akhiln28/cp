---
created at: 2021-07-09
author: akhiln
tags: [problem]
level:
---

# Count swaps during custom sorting
## Problem Statement
To sort the given array you first find the smallest pair $(i, j)$ such that $i < j$ and $arr[i] > arr[j]$. Find the number of swaps during the sorting.

### Examples
input: [7, 1, 2]

output: 2
	- [7, 1, 2] -> [1, 7, 2] -> [1, 2, 7]
input: [3, 7, 1, 2]

output:
	- [3, 7, 1, 2] -> [1, 7, 3, 2] -> [1, 3, 7, 2] -> [1, 2, 7, 3] -> [1, 2, 3, 7]
	- Minimum is 2, [3, 7, 1, 2] -> [3, 2, 1, 7] -> [1, 2, 3, 7]



## Approach
Can be done using simulation in $O(n^2)$. But $n < 10^5$
For each element find the first element to the right that is less than the current element.

Kind of looks like a simulation question.

The answer only depends on just the sorting and not on the actual values.

1 2 3 4 -> 0
4 3 2 1 -> (3 4 2 1) -> (2 4 3 1) -> (1 4 3 2) = 6 swaps

Let $numRight[i]$ be the number of elements to the right which are less than current  $arr[i]$.

I think the answer is $sum(numRight)$. But finding $numRight$ is unknown.

input is [3, 7, 1, 2], sorted array should be [1, 2, 3, 7]. The displacement is 2 + 2 + 2 + 2 = 8/2 = 4

input is [7, 1, 2], sorted = [1, 2, 7]. Displacement = 2 + 1 + 1 = 4

input is [5, 1, 4, 2], sorted = [1, 2, 4, 5]. Displacement = 3 + 1 + 0 + 2 = 6

But [5, 1, 4, 2] -> [1, 5, 4, 2] -> [1, 4, 5, 2] -> [1, 2, 5, 4] -> [1, 2, 4, 5]

## Solution

### References
1. 

