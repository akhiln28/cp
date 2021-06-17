# Cut Ribbons of Same Length

Created Time: Feb 17, 2021 8:06 AM
Do Date: Feb 17, 2021
Last edited time: Mar 31, 2021 8:59 AM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3, https://www.notion.so/Binary-Search-c1187205516c42ac9b3b3c69f153914a
Points: 1500
Source: https://binarysearch.com/contest/Weekly-Contest-46-Wgbjnsf4qw?questionsetIndex=1
Status: done

You are given a list of positive integers `ribbons` and an integer `k`. Given that you can cut the ribbons as many times as you want, return the largest `r` such that you can have `k` ribbons of length `r`. If there is no solution, return `-1`.

**Constraints**

- `1 ≤ n ≤ 100,000` where `n` is the length of `ribbons`
- `1 ≤ k`

### **Explanation**

We can cut the ribbon of size `9` into `3` pieces of size `3` each. Then cut the ribbon of size `4` into size `1` and `3`. Then we can achieve `5` ribbons of size `3`.

### **Explanation**

1