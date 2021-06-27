---
created at: 2021-06-27 
author: akhiln
tags: [problem, matrix]
level: 
---

# Cyclically rotating a grid 
### Problem Statement


#### Examples

### Solution

how about storing each layer as an array 

```python
layer length = 2m + 2n - 4 when in outer layer

four possibilities: choose smallest of (i, n - i, j, m - j)
	top: i
		traversal: 
			(i, i) -> (i, m - i - 1)
			(i + 1, m - i - 1) -> (n - i - 1, m - i - 1)
			(n - i - 1, m - i - 2) -> (n - i - 1, i)
			(n - i - 2, i) -> (i + 1, i)
		layer length = 2(n - 2i) + 2(m - 2i) - 4
		k = k % (layer length)
		(i, j) -> (i, j - k)
		
number of layers = min(n/2, m/2)

rotating the layer k clockwise: 
	val[i] = val[(i + k) % n]
```

#### References

