---
Created Time: Mar 01, 2021 8:29 AM
Do Date: Mar 03, 2021
Last edited time: Mar 03, 2021 8:02 AM
Points: 2000
Pomos (25 mins): 4
Source: https://binarysearch.com/problems/Number-of-Monotonically-Increasing-Lists
Status: done
---

# Number of Monotonically Increasing Lists | binarysearch

You are given integers `n` and `k`. Return the number of distinct lists such that for each list:
- There are `k` positive numbers whose sum is `n`
- Every number is greater than or equal to the number on its left
Mod the result by `10 ** 9 + 7`.
**Constraints**
- `1 ≤ n * k ≤ 200,000`
****Input****
`n = 8`
`k = 4`
****Output****
`5`
### **Explanation**
We can have the following lists:
- `[1,1,1,5]`
- `[1,1,2,4]`
- `[1,1,3,3]`
- `[1,2,2,3]`
- `[2,2,2,2]`
Note that in each list every number is greater than or equal to the number on its left. Each list has length of `4` and sums to `8`.
---
```cpp
const int mod = 1e9 + 7; 
int func(int n, int k, vector<vector<int>>& mem)
{
    if (n == 0 and k == 0) return 1; 
    if (n < k) return 0; 
    if (k <= 0) return 0;
    if (mem[n][k] != -1) return mem[n][k]; 
    return mem[n][k] = (func(n - 1, k - 1, mem) + func(n - k, k, mem)) % mod; 
}
int solve(int n, int k) {
    vector<vector<int>> mem(n + 1, vector<int> (k + 1, -1));
    return func(n, k, mem); 
}
```
Patterns: [Dp](Dp.md)[Memoization](Memoization.md)