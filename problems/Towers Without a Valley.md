---
Created Time: Feb 24, 2021 8:02 AM
Last edited time: May 23, 2021 8:53 AM
Points: 2000
Pomos (25 mins): 1
Source: https://binarysearch.com/contest/Weekly-Contest-47-FeZJewLaN1?questionsetIndex=3
Status: waiting
---

# Towers Without a Valley

You are given a list of integers `nums`. Consider a list of integers `A` such that `A[i] ≤ nums[i]`. Also, there are no `j` and `k` such that there exist `j < i < k` and `A[j] > A[i]` and `A[i] < A[k]`.
Return the maximum possible sum of `A`.
**Constraints**
- `1 ≤ n ≤ 100,000` where `n` is the length of `nums`
### **Example 1**
****Input****
`nums = [10, 6, 8]`
****Output****
`22`
### **Explanation**
We can create `A = [10, 6, 6]`.
### **Example 2**
****Input****
`nums = [4, 5, 1, 1, 5]`
****Output****
`12`
### **Explanation**
We can create `A = [4, 5, 1, 1, 1]`.
---
```cpp
int solve(vector<int>& nums) {
/*
    the numbers in A should follow the one of the 3 following patterns
    all non decreasing order
    all non increasing order
    first non decreasing and then non increasing
    there fore if nums is in any of the patterns above we can just return it. 
    we can classify the above three patterns as mountains. (the first to have peaks at the first and the last respectively)
    otherwise 
    2 5 4 8 9 6 3 3 7 4 -> 2 4 4 8 9 6 3 3 3 3 
    first we need to identify the peak i.e. 9 then we can traverse in both left and right to fill A
    the peak can be anything (should we consider all of the peaks?)
    if peak is idx, the for all i < idx, A[i] = min(nums[i]...nums[idx])
    and for all i > idx, A[i] = min(nums[idx]...nums[i])
    we need to fix the peak to calculate maximum value of A in linear time. 
    what if the peak is the maximum value in the nums?
    consider 10 12 11 13 12 1 14 9, the peak being 14 is does not contribute maximum A. i.e.  1 1 1 1 1 14 9. In this case we need the peak to be 13. -> 10 11 11 13 12 1 1 1. 
    so, how do we determine the peak?
    The peak is the one which gathers most value from both left and right...
    consider more examples:
    1 4 7 8 9 5 4 6 9 8 -> the peak should be 
*/
}
```
Patterns: [Array](Array.md)[Mountain](Mountain.md)