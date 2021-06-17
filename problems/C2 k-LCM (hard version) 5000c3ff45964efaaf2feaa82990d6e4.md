# C2. k-LCM (hard version)

Created Time: Apr 05, 2021 7:49 AM
Do Date: Apr 05, 2021
Last edited time: Apr 05, 2021 8:28 AM
Pattern: https://www.notion.so/Construction-baf5eaaa0bc4494fa78ad7ee1cd5efda
Points: 1600
Source: https://codeforces.com/problemset/problem/1497/C2
Status: done

**It is the hard version of the problem. The only difference is that in this version 3≤𝑘≤𝑛3≤k≤n.**

You are given a positive integer 𝑛n. Find 𝑘k positive integers 𝑎1,𝑎2,…,𝑎𝑘a1,a2,…,ak, such that:

- 𝑎1+𝑎2+…+𝑎𝑘=𝑛
- 𝐿𝐶𝑀(𝑎1,𝑎2,…,𝑎𝑘)≤𝑛2

Here 𝐿𝐶𝑀LCM is the [least common multiple](https://en.wikipedia.org/wiki/Least_common_multiple) of numbers 𝑎1,𝑎2,…,𝑎𝑘a1,a2,…,ak.

We can show that for given constraints the answer always exists.

**Input**

The first line contains a single integer 𝑡t (1≤𝑡≤104)(1≤t≤104)  — the number of test cases.

The only line of each test case contains two integers 𝑛n, 𝑘k (3≤𝑛≤1093≤n≤109, 3≤𝑘≤𝑛3≤k≤n).

It is guaranteed that the sum of 𝑘k over all test cases does not exceed 105105.

**Output**

For each test case print 𝑘k positive integers 𝑎1,𝑎2,…,𝑎𝑘 for which all conditions are satisfied.

**Example**

```
2
6 4
9 5

```

```
1 2 2 1
1 3 3 1 1

```