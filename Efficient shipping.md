---
created at: 2021-07-09 
author: akhiln
tags: [problem]
level: 
---

# Efficient shipping 
## Problem Statement
`boxes[i]` denotes the number of boxes of product $i$
`unitsPerBox[i]` denotes the number of units per box for each product $i$
`truckSize` denotes the number of boxes that the truck can carry. 

Find the maximum number of units of any mix of products that can be shipped. 


### Examples
boxes = [1, 2, 3]
unitsPerBox = [3, 2, 1]
truckSize = 3

## Approach
Total number of boxes = sum(boxes)

Simple greedy
Sort each box by the value i.e. units per box. 

## Solution

### References

