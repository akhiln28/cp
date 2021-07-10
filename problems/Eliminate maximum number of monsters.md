---
created at: 2021-07-05 
author: akhiln
tags: [problem]
level: 1500
---

# Eliminate maximum number of monsters 
### Problem Statement
Given $n$ `distances` and $n$ `speeds` of monsters from your town. Find the maximum number of monsters that you can kill. You can only kill one monster at the start of each minute. You lose the instant the monster is in your town.

#### Examples
input: {1, 3, 4}, {1, 1, 1}
output: 3

input: {3, 2, 4}, {5, 3, 2}
output: 1
	times = {0.6, 0.67, 2}
	
input: times = {0.1, 2, 2.3}
output: 3
	times can be converted to ceil = {1, 2, 3}
	
input: times = {2, 2, 3}
output: 3

### Solution
```python
ans = 0
times.sort()
for time in times:
	if time > ans:
		ans++
return ans
```

#### References
1. Simple logic
2. Greedy