---
created at: 2021-06-27
author: akhiln
tags: [problem, substring, counting]
level:
---

# Number of wonderful substrings
### Problem Statement
Given a string of length `n`, find the number of wonderful substrings. A **wonderful** string is a string where **at most one** letter appears an **odd** number of times.
Given a string `word` that consists of the first ten lowercase English letters (`'a'` through `'j'`)

$$ n \le 10^5 $$

#### Examples

### Solution
Brute force approach would be to iterate over all the substrings i.e. `O(n^2)` and check the count of each alphabet.

All single characters i.e. `n` are wonderful substrings.
What about all the substrings of length 2?

#### DP approach
dp[i] = number of wonderful substrings until i.
dp[i + 1] = dp[i] + count of wonderful substrings ending at i + 1.

dp1[i] = number of wonderful substrings ending at i.
dp1[i] =
`aabbdbbbaaaddbbb` ->

#### Optimization step:
How about finding the number of substrings that are not wonderful. i.e. strings which contain at least 2 odd repetitions.

If a substring has 2 odd repetitions all its super strings are invalid. How to utilize this optimization?





#### References
1. [Number of Substrings](Number%20of%20Substrings.md)
2. [Linear](Linear)
3. [Source](https://leetcode.com/contest/weekly-contest-247/problems/number-of-wonderful-substrings/)