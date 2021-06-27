---
created at: 2021-06-22
author: akhiln
tags: [problem, atcoder, palindrome]
level: 1203
status: done
---

# Palindromic Matrix
### Problem Statement
You have a matrix `A` containing lower case English alphabet. Determine whether you can create `A'` by rearranging letters in `A` so that each row and each column is a palindrome?

#### Constraints
$$ 1 \le H,W \le 100 $$

#### Examples
Input:
```
3 4
aabb
aabb
aacc
```
Output:



### Solution
So, given a list of `HxW` letters we need to check if you can form matrix such that each row and each column is a palindrome.

Each element (not at the center) should be present at four locations exactly.

Every element must be present even number of times in the given matrix `A` otherwise it is not possible to construct a palindromic matrix.

- When `H`, `W`
- both even
	- every element should be repeated 4 times
- `H` even is `W` is odd
	- at most H/2 elements can only be repeated 2 times
- both are odd
	- at most `H/2` elements can only be repeated 2 times
	- at most `W/2` elements can be repeated exactly 2 times
	- at most one element can be unique


#### References
[[Palindrome]]