---
Created Time: Feb 17, 2021 8:06 AM
Do Date: Feb 17, 2021
Last edited time: Mar 31, 2021 8:59 AM
Points: 1500
Source: https://binarysearch.com/contest/Weekly-Contest-46-Wgbjnsf4qw?questionsetIndex=1
Status: done
---

# Cut Ribbons of Same Length

You are given a list of positive integers `ribbons` and an integer `k`. Given that you can cut the ribbons as many times as you want, return the **largest** `r` such that you can have `k` ribbons of length `r`. If there is no solution, return `-1`.
**Constraints**
- `1 ≤ n ≤ 100,000` where `n` is the length of `ribbons`
- `1 ≤ k`
#### **Input**

ribbons = [1, 2, 3, 4, 9]
k = 5

#### **Output**
3

#### **Explanation**
We can cut the ribbon of size `9` into `3` pieces of size `3` each. Then cut the ribbon of size `4` into size `1` and `3`. Then we can achieve `5` ribbons of size `3`.


#### **Input**
ribbons = [8]
k = 4

#### **Output**
2

#### **Explanation**
We can cut the ribbon into `4` pieces of size `2`.

## Solution
Since we only need to find a single value, first thing that comes to my mind is binary search. 
[[Cut Ribbons of Same Length.py]]
