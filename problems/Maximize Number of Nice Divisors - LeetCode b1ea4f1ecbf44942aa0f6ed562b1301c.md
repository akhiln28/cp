# Maximize Number of Nice Divisors - LeetCode

Created Time: Mar 27, 2021 10:18 PM
Do Date: Mar 27, 2021
Last edited time: May 23, 2021 8:53 AM
Pattern: https://www.notion.so/Calculus-55f3d17128ab46aabe15ed37cd933269
Points: 1700
Source: https://leetcode.com/problems/maximize-number-of-nice-divisors/
Status: waiting

![LeetCode_Sharing.png](problems/Maximize%20Number%20of%20Nice%20Divisors%20-%20LeetCode%20b1ea4f1ecbf44942aa0f6ed562b1301c/LeetCode_Sharing.png)

You are given a positive integer `primeFactors`. You are asked to construct a positive integer `n` that satisfies the following conditions:

- The number of prime factors of `n` (not necessarily distinct) is **at most** `primeFactors`.
- The number of nice divisors of `n` is maximized. Note that a divisor of `n` is **nice** if it is divisible by every prime factor of `n`. For example, if `n = 12`, then its prime factors are `[2,2,3]`, then `6` and `12` are nice divisors, while `3` and `4` are not.

Return *the number of nice divisors of* `n`. Since that number can be too large, return it **modulo** `109 + 7`.

Note that a prime number is a natural number greater than `1` that is not a product of two smaller natural numbers. The prime factors of a number `n` is a list of prime numbers such that their product equals `n`.

**Example 1:**

```
Input: primeFactors = 5
Output: 6
Explanation: 200 is a valid value of n.
It has 5 prime factors: [2,2,2,5,5], and it has 6 nice divisors: [10,20,40,50,100,200].
There is not other value of n that has at most 5 prime factors and more nice divisors.
```

**Example 2:**

```
Input: primeFactors = 8
Output: 18
```

**Constraints:**

- `1 <= primeFactors <= 109`