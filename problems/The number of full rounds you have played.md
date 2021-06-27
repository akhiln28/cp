---
created at: 2021-06-20 
author: akhiln
tags: [problem, case]
level: 1200
status: done
---

# The number of full rounds you have played
### Problem Statement
Given two times `startTime` and `finishTime`. Find the number of rounds you can play? Each round starts at the multiple of 15mins and is 15mins long. 


#### Examples

### Solution
```python
if startTime < endTime
	time difference
		10:31 to 11:42 - 1 + 2
		10:42 to 11:31 - 1 + 2
If start time is greater than end time i.e. 
	consider 10:31 to 4:42
		10:31 to 23:59 + 0:0 to 4:42
```
#### References
Pattern: [[Casing]]