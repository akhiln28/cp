---
created at: 2021-07-07 
author: akhiln
tags: [problem]
level: 
---

# Find local peaks sequel 
### Problem Statement
Given a list of integers `nums`. Return the indices of all the peaks. And index `i` is called peak if all the below are true
1. The first number to the right different from `nums[i]` is smaller than `nums[i]` or does not exist
2. The first number to the left different from `nums[i]` is smaller than `nums[i]` or does not exist
3. There is at least one number on its left or its right that's different than `nums[i]`

#### Examples
Input: [2, 5, 5, 5, 3, 8, 8]
Output: [1, 2, 3, 5, 6]

### Solution
for each index, find the next different index, and the before different index.
[2, 5, 5, 5, 3, 8, 8]
next different - [5, 3, 3, 3, 8, -, -]
	iterate from right to left, maintain cur = `nums[i]`.
before different - [-, 2, 2, 2, 5, 3, 3]
	iterate from left to right

[[Find local peaks sequel.py]]
#### References

