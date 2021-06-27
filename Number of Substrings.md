---
created at: 2021-06-27 
author: akhiln
tags: [pattern]
level: 
---

# Number of Substrings 
## Forces
Given a string of length `n`. Count the number of valid substrings.

### Pseudo code
A generic approach would be to iterate over all the substrings. 

```cpp
for (int i = 0; i < n; i++) {
	for (int j = i; j < n; j++) {
		return substring(i to j);
	}
}
```

## Parents
1. [Substring](Substring.md)