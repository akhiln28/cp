# H-Index - LeetCode

Created Time: Feb 04, 2021 8:45 PM
Do Date: Feb 05, 2021
Last edited time: Feb 05, 2021 7:50 AM
Points: 1500
Related To: H-Index%20II%20-%20LeetCode%20438da1823db64e88a563fd1d08875b18.md
Source: https://leetcode.com/problems/h-index/
Status: done

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the [definition of h-index on Wikipedia](https://en.wikipedia.org/wiki/H-index): "A scientist has index h if h of his/her N papers have **at least** h citations each, and the other N − h papers have **no more than** h citations each."

**Example:**

```
Input: citations = [3,0,6,1,5]Output: 3 
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
             received 3, 0, 6, 1, 5 citations respectively. 
             Since the researcher has 3 papers with at least 3 citations each and the remaining 
             two with no more than 3 citations each, her h-index is 3.
```

**Note:** If there are several possible values for *h*, the maximum one is taken as the h-index.

---