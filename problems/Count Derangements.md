---
Created Time: Jan 09, 2021 1:18 PM
Do Date: Feb 11, 2021
Last edited time: May 11, 2021 9:01 AM
Points: 1600
Status: done
Tags: amazon
---

# Count Derangements

Given n, count the number of derangements of $p_n$. 
---
$$d_n = (n - 1)(d_{n-1} + d_{n - 2})$$
There are n – 1 ways for element 0 (this explains multiplication with n – 1). Let **0 be placed at index i**. There are now two possibilities, depending on whether or not element i is placed at 0 in return.
1. **i is placed at 0:** This case is equivalent to solving the problem for n-2 elements as two elements have just swapped their positions.
2. **i is not placed at 0:** This case is equivalent to solving the problem for n-1 elements as now there are n-1 elements, n-1 positions and every element has n-2 choices
Reference:
[Count Derangements (Permutation such that no element appears in its original position) - GeeksforGeeks](https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/)
Patterns: [Dp](Dp.md)[Number%20Theory](Number%20Theory.md)[Linear%20DP](Linear%20DP.md)