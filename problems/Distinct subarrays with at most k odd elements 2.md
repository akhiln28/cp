---
Created Time: Dec 15, 2020 7:15 PM
Do Date: Dec 15, 2020
Last edited time: May 11, 2021 9:00 AM
Points: 1700
Pomos (25 mins): 2
Problem Statement: Given an integer array nums, find number of distinct contiguous subarrays with at most k odd elements. 
Status: ok
Tags: swiggy, unverified
---

# Distinct subarrays with at most k odd elements

Given an integer array nums (≤ 1000), find number of distinct contiguous subarrays with at most k odd elements. (two contiguous subarrays are distinct if they different by at least one element)
---
Using set with custom functor. The functor returns (p1 ≠ p2); The only the unique pairs will be inserted. We can get the final size. 
```cpp
set with custom functor. 
for (int i = 0; i < n; i++)
	for (int j = i; j < n; j++)
		if i to j has at most k odd elements
			set.insert(pair)
		else break;
```
Patterns: [Custom%20datastructures](Custom%20datastructures.md)