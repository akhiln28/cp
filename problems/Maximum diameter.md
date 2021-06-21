---
Created Time: Dec 04, 2020 5:03 PM
Do Date: Dec 04, 2020
Last edited time: Mar 01, 2021 8:46 AM
Points: 1600
Problem Statement: Given an array which represents the number of nodes at the ith level in a tree. arr[0] = 1. Find the maximum possible diameter of the tree?
Source: sharechat
Status: done
Tags: interview, sharechat
---

# Maximum diameter

When the number of nodes at level is one. 
**Algorithm**
```python
int ans = 0; 
int count = 0; 
int cur_ans, prev_ans = 0; 
for i = 0 to n - 1:
	if (arr[i] == 1)
		cur_ans = max(2 * count + 1, prev_ans + count + 1)
		ans = max(ans, cur_ans)
		count = 0; 
		prev_ans = cur_ans; 
	else count++;
return ans
```
Patterns: [Dp](Dp.md)