# Number of 1 Bits - LeetCode

Created Time: Jan 15, 2021 2:47 PM
Do Date: Jan 31, 2021
Last edited time: May 11, 2021 9:12 AM
Pattern: https://www.notion.so/Custom-datastructures-6c89204250cd4dbb88ef0addf2ca20a3, https://www.notion.so/Bits-e38c7329b88e4b65ac64bfc4a9ffc7ed
Source: https://leetcode.com/problems/number-of-1-bits/
Status: done

Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the [Hamming weight](http://en.wikipedia.org/wiki/Hamming_weight)).

**Note:**

- Note that in some languages such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
- In Java, the compiler represents the signed integers using [2's complement notation](https://en.wikipedia.org/wiki/Two%27s_complement). Therefore, in **Example 3** above, the input represents the signed integer. `3`.

**Follow up**: If this function is called many times, how would you optimize it?

**Example 1:**

```
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

```

**Example 2:**

```
Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

```

**Example 3:**

```
Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

```

**Constraints:**

- The input must be a **binary string** of length `32`

---

The below solution I found in the leetcode discuss is very good. 

```cpp
int hammingWeight(uint32_t n) {
    int count = 0;
    
    while (n) {
        n &= (n - 1); // remove last occuring one from n
        count++;
    }
    
    return count;
}
```