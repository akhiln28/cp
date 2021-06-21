---
Created Time: May 09, 2021 9:12 AM
Last edited time: May 23, 2021 8:54 AM
Points: 1700
Source: https://atcoder.jp/contests/abc200/tasks/abc200_d
Status: done
---

# D - Happy Birthday! 2

Given a sequence of integers $a_1 \space to \space a_n$. (n < 200). Find if there are any two distinct sets of indices such that their sum modulo 200 is same? If yes print the two sets. 
### Format
**Input**
```
N
a1 a2 a3 ... an
```
**Output**
```
Yes/No
x ai aj al ...
y ap aq ar ...
```
### Constraints
$$2 \le N \le 200 \\
1 \le a_i \le 10^9$$
### **Examples**
**Input**
```
5
180 186 189 191 218
```
**Output**
```
Yes
1 1
2 3 4
```
---
**Input**
```
6
2013 1012 2765 2021 508 6971
```
**Output**
```
No
```
---
## Algorithm
```python
Given nums
eight_nums = first 8 elements of nums
subsets = all the subsets of eight_nums
use hashing to figure out any two subsets with same sum
```
### Explanation
We just need to find two sequences whose sum is same and there only 200 possibilities for their sum. If we generate 201 sequences then at least two of them must have same sum. 
So, consider only up to 8 elements from the array and generate all the 255 non empty subsets and you will have the answer
## Solution
```jsx
```
Patterns: [Subsequence](Subsequence.md)[Pegionhole%20Principle](Pegionhole%20Principle.md)