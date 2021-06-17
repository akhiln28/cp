# E. Apollo versus Pan

Created Time: Dec 29, 2020 10:20 PM
Last edited time: May 11, 2021 9:12 AM
Pattern: https://www.notion.so/Custom-datastructures-6c89204250cd4dbb88ef0addf2ca20a3, https://www.notion.so/Bits-e38c7329b88e4b65ac64bfc4a9ffc7ed
Source: https://codeforces.com/contest/1466/problem/E
Status: waiting

Given n integers $x_1, x_2..., x_n (x_i \in 2^{60}, n \le 5.10^5)$. Find the value of the below expression?

$$\sum_{i = 1}^n \sum_{j = 1}^n \sum_{k = 1}^n (x_i \& x_j).(x_j\|x_k)$$

Print the result modulo $10^9 + 7$. 

Input: 

```cpp
8
2
1 7
3
1 2 4
4
5 5 5 5
5
6 2 2 1 0
1
0
1
1
6
1 12 123 1234 12345 123456
5
536870912 536870911 1152921504606846975 1152921504606846974 1152921504606846973

```

output: 

```cpp
128
91
1600
505
0
1
502811676
264880351
```

---