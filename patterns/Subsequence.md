---
Count: 1
Created Time: Feb 24, 2021 9:31 AM
Last Edit Time: Feb 24, 2021 9:31 AM
---
# Subsequence

A string `sub` is called a subsequence of string `s` if all the you can construct `sub` by **removing zero or more characters** from `s`. 

Check if a `sub` is a subsequence of `str`
```python
def is_subsequence(sub, s):
	ptr = 0
	for ch in sub: 
		starting at the ptr check if you can find ch in s
		if not found: return false
	return true
```