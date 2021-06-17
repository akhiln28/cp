# Perfect Squares | binarysearch

Created Time: Dec 22, 2020 5:59 PM
Do Date: Dec 22, 2020
Last edited time: May 11, 2021 9:01 AM
Pattern: https://www.notion.so/Dp-71e29475df134130a63445f5437e90ee, https://www.notion.so/Number-Theory-02e26369bab8475881b8a6a9d7b33ca9, https://www.notion.so/Linear-DP-40f64e6224704d17972aa352dc735edb
Points: 1200
Problem Statement: Write a program that determines the smallest number of square numbers that sum up to n.
Source: https://binarysearch.com/problems/Perfect-Squares
Status: ok

Write a program that determines the smallest number of square numbers that sum up to `n`.

**Constraints**

- `1 ≤ n ≤ 10000`

### **Example 1**

****Input****

`n = 4`

****Output****

`1`

### **Explanation**

4 is already the square of 2.

### **Example 2**

****Input****

`n = 17`

****Output****

`2`

### **Explanation**

16 + 1

### **Example 3**

****Input****

`n = 18`

****Output****

`2`

### **Explanation**

9 + 9

---

**Intuition**

Time Complexity: **`O(sqrt(n))`**Using **Bachet's Conjecture** Solves The Problem..**Bachet's Conjecture** States That Any every natural number can be represented as the **sum of four integer squares.**Also From Legendre **3-Square Theorem** We Know That a positive integer can be expressed as the sum of three squares **if and only if it is not of the form** `4^k(8m+7)` for integers k and m.Combining Two Above Statements We Say That Least Number Of Perfect Squares Can be Either `1,2,3 or 4` no matter how **large** the number is...

```python
class Solution:
    def solve(self, n):
        m = n
        p = sqrt(n)
        if ceil(p) == floor(p):
            return 1
        while n & 3 == 0:
            n >>= 2
        if n & 7 == 7:
            return 4
        n = m
        for i in range(1, int(p) + 1):
            j = sqrt(n - i * i)
            if ceil(j) == floor(j):
                return 2
        return 3
```

I did something like below, in $O(n\sqrt n)$

```cpp
int solve(int n) {
    int root = sqrt(n); 
    if (root * root == n) return 1; 
    int dp[n + 1]; 
    fill(dp, dp + n + 1, 1e5); 
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        int root = sqrt(i); 
        if (root * root == i) dp[i] = 1; 
        else
        {
            for (int j = 1;; j++)
            {
                if (i < j*j) break;
                dp[i] = min(dp[i], 1 + dp[i - j * j]); 
            }
        }
    }
    return dp[n]; 
}
```

Simple greedy program like below **does not work**. 

```cpp
int solve(int n) {
    int root = sqrt(n); 
    if (root * root == n) return 1; 
    else return 1 + solve(n - root * root);
}
```