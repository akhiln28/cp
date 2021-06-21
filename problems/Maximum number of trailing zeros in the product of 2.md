---
Created Time: Dec 27, 2020 9:13 AM
Last edited time: Mar 01, 2021 8:48 AM
Points: 1700
Relates: B%20The%20least%20round%20way%209889b0d9a536439cab8ba6814793987d.md
Source: https://www.geeksforgeeks.org/maximum-number-of-trailing-zeros-in-the-product-of-the-subsets-of-size-k/
Status: waiting
Tags: new
---

# Maximum number of trailing zeros in the product of the subsets of size k - Geeksforgeeks

Given an array of size n and a positive integer k, find the maximum number of trailing zeros in the product of the subsets of size k.
Examples:
```
Input : arr = {50, 4, 20}
        k = 2
Output : 3
Here, we have 3 subsets of size 2. [50, 4] 
has product 200, having 2 zeros at the end, 
[4, 20] — product 80, having 1 zero at the 
end, [50, 20] — product 1000, having 3 zeros
at the end. Therefore, the maximum zeros at
the end of the product is 3.
Input : arr = {15, 16, 3, 25, 9}
        k = 3
Output : 3
Here, the subset [15, 16, 25] has product 6000.
Input : arr = {9, 77, 13}
        k = 3
Output : 0
Here, the subset [9, 77, 13] has product 9009
having no zeros at the end.
```
**Dynamic Programming approach :**
Obviously, the number of zeros at the end of the number is determined by minimum of powers of **2** and **5** in the number. Let **pw5** be the maximal power of **5** in the number and **pw2** be the maximal power of **2**.
Let, **subset[i][j]** be the maximum amount of 2s we can collect considering **i** numbers having j number of 5s in each of them.
We traverse through all numbers of given, for every array element, we count number of 2s and 5s in it. Let pw2 be the number of 2s in current number and pw5 be the number of 5s.
Now, there is one transition for **subset[i][j]**:
// For current number (pw2 two’s and pw5 five’s) we check
// if we can increase value of subset[i][j].
subset[i][j] = max(subset[i][j], subset[i-1][j-pw5] + pw2)
The above expression can also be written as below.**subset[i + 1][j + pw5] = max(subset[i + 1][j + pw5], subset[i][j] + pw2);**
The answer will be **max(ans, min(i, subset[k][i])**
Patterns: [Array](Array.md)[Dp](Dp.md)