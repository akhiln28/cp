---
Created Time: Dec 04, 2020 5:21 PM
Do Date: Nov 30, 2020
Last edited time: Mar 01, 2021 8:41 AM
Points: 1600
Problem Statement: Given n of types 1 to n respectively (repetitoins allowed). Each type having cost a_i. You can do an operation such as change type of items i to i + 1 (cyclically) (the cost remains the same) with a cost x. Find the minimum possible cost to by all types of items?
Source: sharechat
Status: done
Tags: interview, sharechat
---

# Minimum Price

```python
max number of operations ki loop chesi, 
for maxops in [0, n - 1]:
   ans = 0
    for each type i:
        ans += min cost among (i - maxops + 1, i)
    final_ans = min(final_ans, ans)
```
![Minimum%20Price%209e454db95b584fbfa8600a71c8d6cf2c/Untitled.png](Minimum%20Price%209e454db95b584fbfa8600a71c8d6cf2c/Untitled.png)
Patterns: [Cumulative](Cumulative.md)