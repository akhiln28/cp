---
Created Time: Jan 15, 2021 12:36 PM
Last edited time: May 11, 2021 9:12 AM
Points: 1000
Source: https://binarysearch.com/problems/XOR-Range-Queries
Status: done
---

# XOR Range Queries | binarysearch

You are given a list of integers `nums` and a two-dimensional list of integers `queries`. Each element in `queries` contains `[i, j]` and asks what is the value of `nums[i] ^ nums[i + 1] ^ ... ^ nums[j]`. Return a list containing the answer for each query.
**Constraints**
- `0 ≤ n ≤ 100,000` where `n` is the length of `nums`
- `0 ≤ m ≤ 100,000` where `m` is the length of `queries`
### **Output**
### **Explanation**
First query asks `1 ^ 3` which is `2`. The second query asks `3 ^ 4 ^ 2` which is `5`
Patterns: [Custom%20datastructures](Custom%20datastructures.md)[Bits](Bits.md)