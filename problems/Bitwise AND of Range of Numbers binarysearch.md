---
Created Time: Dec 15, 2020 9:25 AM
Do Date: Dec 15, 2020
Last edited time: May 11, 2021 9:12 AM
Points: 1500
Pomos (25 mins): 1
Problem Statement: Given two integers start and end, return the bitwise AND of all numbers in [start, end], inclusive.
Source: https://binarysearch.com/problems/Bitwise-AND-of-Range-of-Numbers
Status: done
---

# Bitwise AND of Range of Numbers | binarysearch

Given two integers `start` and `end`, return the bitwise AND of all numbers in `[start, end]`, inclusive.
**Constraints**
- `0 ≤ start ≤ end < 2**31`
---
```cpp
int solve(int start, int end) {
    int left = 1; 
    while (2 * left <= start) left *= 2; 
    if (start >= left and end < 2 * left) 
        return left + solve(start % left, end % left); 
    else return 0; 
}
```
Patterns: [Custom%20datastructures](Custom%20datastructures.md)[Bits](Bits.md)