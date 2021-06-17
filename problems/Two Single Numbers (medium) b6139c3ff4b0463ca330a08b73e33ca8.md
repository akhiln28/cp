# Two Single Numbers (medium)

Created Time: Dec 22, 2020 4:57 PM
Do Date: Dec 22, 2020
Last edited time: May 11, 2021 9:12 AM
Pattern: https://www.notion.so/Custom-datastructures-6c89204250cd4dbb88ef0addf2ca20a3, https://www.notion.so/Bits-e38c7329b88e4b65ac64bfc4a9ffc7ed
Pomos (25 mins): 1
Problem Statement: In a non-empty array of numbers, every number appears exactly twice except two numbers that appear only once. Find the two numbers that appear only once.
Source: educative.io
Status: ok

In a non-empty array of numbers, every number appears exactly twice except two numbers that appear only once. Find the two numbers that appear only once.

**Example 1:**

```
Input: [1, 4, 2, 1, 3, 5, 6, 2, 3, 5]
Output: [4, 6]

```

**Example 2:**

```
Input: [2, 1, 3, 2]
Output: [1, 3]
```

---

Finding single number is straight forward. So, if the two numbers are x and y, we can find `x ^ y`.  

1. Taking XOR of all numbers in the given array will give us XOR of `num1` and `num2`, calling this XOR as `n1xn2`.
2. Find any bit which is set in `n1xn2`. We can take the rightmost bit which is ‘1’. Let’s call this `rightmostSetBit`.
3. Iterate through all numbers of the input array to partition them into two groups based on `rightmostSetBit`. Take XOR of all numbers in both the groups separately. Both these XORs are our required numbers.