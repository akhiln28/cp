# Convert all 0 → 1's

Created Time: Dec 18, 2020 12:53 PM
Last edited time: Mar 01, 2021 8:46 AM
Pattern: https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee
Points: 1800
Pomos (25 mins): 2
Problem Statement: Given 2 arrays, array A (containing only 0s and 1s) and the other cost array B of the same size. We needed to convert all the elements of array A to 1 in minimum cost. For every ith element in the array A, converting from 0 to 1 requires B[i] cost but if A[i-1] and A[i+1] are 1 then A[i] can be converted to 1 with 0 cost. Return the minimum possible cost to convert all 0s to 1s. I thought for around 12-13 mins but simply could not come up any optimal approach. Than i made up a BFS solution over all indexes (brute force approach) and to my surprise i passed 9/13 test cases.
Status: waiting
Tags: de shaw

This was a hard question.Given 2 arrays, array A (containing only 0s and 1s) and the other cost array B of the same size. We needed to convert all the elements of array A to 1 in minimum cost. For every ith element in the array A, converting from 0 to 1 requires B[i] cost but if A[i-1] and A[i+1] are 1 then A[i] can be converted to 1 with 0 cost. Return the minimum possible cost to convert all 0s to 1s. I thought for around 12-13 mins but simply could not come up any optimal approach. Than i made up a BFS solution over all indexes (brute force approach) and to my surprise i passed 9/13 test cases.

---

Here greedy does not work, consider the follow example, 

```cpp
[0, 0, 0], [2, 3, 4]
ans = 3, but greedy = 2 + 3 = 5
```

Subproblem: 

Given array always contains 0's.