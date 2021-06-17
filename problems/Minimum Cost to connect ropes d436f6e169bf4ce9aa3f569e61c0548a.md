# Minimum Cost to connect ropes

Created Time: Dec 06, 2020 9:32 AM
Do Date: Dec 04, 2020
Last edited time: Mar 01, 2021 3:42 PM
Pattern: https://www.notion.so/Array-af1fbf6be3da4abfadba9d43c8017242, https://www.notion.so/Greedy-ea1f204b1d0b40e89fdb87f6dc8055d3
Points: 1200
Problem Statement: Given n ropes of different lengths, we need to connect these ropes into one rope. We can connect only 2 ropes at a time. The cost required to connect 2 ropes is equal to sum of their lengths. The length of this connected rope is also equal to the sum of their lengths. This process is repeated until n ropes are connected into a single rope. Find the min possible cost required to connect all ropes.
Status: done
Tags: goldman sachs, new

Coming up with a solution is quite straight forward. At each step we choose the ropes greedily to get the best possible outcome. In the final answer, the number of times 

```python
set<int> array = given
while (array is not empty)
	r1 = array.front(), array.pop()
	r2 = array.front(), array.pop()
	array.insert(r1 + r2)
```

### Proof:

Similar to [Huffmann Coding](Huffmann%20Coding%209988d6a6f9284aa6b2a284e891ca6697.md) 

![Minimum%20Cost%20to%20connect%20ropes%20d436f6e169bf4ce9aa3f569e61c0548a/Untitled.png](problems/Minimum%20Cost%20to%20connect%20ropes%20d436f6e169bf4ce9aa3f569e61c0548a/Untitled.png)

The sum contains sum of depth of each value. For array (2, 3, 4, 6) the sum is equal to 2 * 3 + 3 * 3 + 4 * 2 + 6 * 1 = 29 (According to the diagram).