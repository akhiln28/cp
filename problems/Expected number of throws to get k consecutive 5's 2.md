---
Created Time: Feb 10, 2021 12:12 PM
Do Date: Feb 11, 2021
Last edited time: Feb 11, 2021 7:58 AM
Points: 1500
Status: ok
---

# Expected number of throws to get k consecutive 5's

he expected number of rolls to get 0 6's in a row, E_0, is 0.
What's the expected number of rolls to get n+1 6's in a row? First you have to roll n 6's, then you have a 1 in 6 chance of getting a six on the next roll, or a 5/6 chance of starting over again.
```
E_(n+1) = E_n + 1/6 * 1 + 5/6 *(1 +  E_(n+1))
E_(n+1)/6 = E_n + 1
E_(n+1) = 6 (E_n + 1)
```
So E_0 = 0, E_1 = 6, E_2 = 42, E_3 = 258...
```jsx
E = 5/6 * (E + 1) + 5/36 * (E + 2) + 5/216 * (E + 3) + 1/216 * 3 => E = 258.
```
Patterns: 