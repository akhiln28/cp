---
created at: 2021-06-23 
author: akhiln
tags: [problem]
level: 
status: pending
---

# Friend Suggestions 
### Problem Statement
You are given `N` users. And `M` friends ships, `K` block ships. `a` is a friend candidate for `b` if there is no direct relationship between `a` and `b` and there is an indirect friend ship connection between `a` and `b`. 

For each user find the number of friend candidates?
#### Examples

### Solution
We can first group the users in connected components based on the friend ship. We can use [Union Find](Union%20Find.md) to find all the connected components. 

#### References

