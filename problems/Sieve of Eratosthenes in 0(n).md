---
Created Time: Dec 18, 2020 12:33 PM
Last edited time: May 23, 2021 8:53 AM
Related To: Sieve%20of%20Eratosthenes%20-%20GeeksforGeeks%20c4fa828f26d748bd8af24fde1bdcfb42.md
Source: https://www.geeksforgeeks.org/sieve-eratosthenes-0n-time-complexity/
Status: waiting
---

# Sieve of Eratosthenes in 0(n) time complexity

The [classical Sieve of Eratosthenes algorithm](https://www.geeksforgeeks.org/sieve-of-eratosthenes/) takes O(N log (log N)) time to find all prime numbers less than N. In this article, a modified Sieve is discussed that works in O(N) time.
**Example :**
```
Given a number N, print all prime 
numbers smaller than N
Input :  int N = 15
Output : 2 3 5 7 11 13
Input : int N = 20
Output : 2 3 5 7 11 13 17 19
```
Manipulated Sieve of Eratosthenes algorithm works as following:
```python
For every number i where i varies from 2 to N-1:
    Check if the number is prime. If the number
    is prime, store it in prime array.
For every prime numbers j less than or equal to the smallest  
prime factor p of i:
    Mark all numbers j*p as non_prime.
    Mark smallest prime factor of j*p as j
```

Patterns: [Number Theory](Number%20Theory.md), [Dp](Dp.md)