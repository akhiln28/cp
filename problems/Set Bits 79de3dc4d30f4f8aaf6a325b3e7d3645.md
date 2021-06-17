# Set Bits

Created Time: Dec 08, 2020 11:15 PM
Do Date: Dec 08, 2020
Last edited time: May 11, 2021 9:12 AM
Pattern: https://www.notion.so/Custom-datastructures-6c89204250cd4dbb88ef0addf2ca20a3, https://www.notion.so/Bits-e38c7329b88e4b65ac64bfc4a9ffc7ed
Points: 1600
Problem Statement: Given n, return the number of set bits in all the numbers from 1 to n?
Source: https://binarysearch.com/problems/Set-Bits
Status: done

Given n, return the number of set bits in all the numbers from 1 to n?

---

We want $\sum_1^Ncount(i)$. 

count(2^k) = 

```cpp
int solve(int n) {
    if (n == 0) return 0; 
    int x = 1, len = 0; // x is the largest power of two less than n
    while ((x << 1) <= n) x <<= 1, len++; 
    int ans = 1 + len * (1 << (len - 1)); // total number of set bits in 1 ... 2 ^ len
    n = n - x; 
    return ans + n + solve(n);
}
```

[binarysearch | Master Algorithms Together](https://binarysearch.com/room/Bit-Manipulation-8S67dmOnIe/editorials/713245)